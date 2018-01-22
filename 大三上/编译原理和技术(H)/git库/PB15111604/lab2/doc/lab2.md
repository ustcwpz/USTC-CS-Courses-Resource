# **lab2 代码生成**

**金泽文 PB15111604**

--------------------------

## **1.设计思路**

### **1.1思路概要：**

​	根据c1recognizer得到的AST，通过visit遍历节点(体现为node.field->accept(*this))，来生成llvm ir。

### **1.2具体visit实现：**

​    **1.2.1 Assembly：visit(assembly &node)**

​	对node.global_defs成员遍历，注意为了避免error对其他global_def的影响，每次这里的每次visit之前要重置一遍各个flag，如lval_as_rval，in_global等。

​    **1.2.2 Function：visit(func_def_syntax &node)**

​	函数的创建通过Function::Create，传入name,module.get()等，函数类型只有void。函数创建之后emplace进functions中。

​	对于函数体body，需要注意builder.CreateVoid()。函数体通过node.body->accept().

​    **1.2.3 Block：visit(block_syntax &node)**

​	对于block，需要注意：考虑作用域，enter_scope()进入新作用域，exit_scope()退出当前作用域。

​	遍历body中的每个语句(块)，注意类似于assembly，要避免语句间影响，所以每个语句间重置lval_as_rval，constexpr_expected等。

​    **1.2.4 Lval：visit(lval_syntax &node)**

​	1.2.4.1 如果需要lval的非数组：

​		通过lookup_variable(name)来得到tuple，std::get\<0\>得到指针。

​	1.2.4.2 如果需要lval的数组：

​		由于数组不论global，local都是二维数组，得到数组ptr之后通过{0, index}的GEP得到元素指针。

​	1.2.4.3 如果需要rval的非数组：

​		那就在刚才1.2.4.1的基础上在load一下。

​	1.2.4.4 如果需要rval的数组：

​		那就在刚才1.2.4.2的基础上在load一下。

​    **1.2.5 Exp：visit(unaryop_expr_syntax &node)，visit(binop_expr_syntax &node)，visit(literal_syntax &node)**

​	对于bin，unary，literal的表达式，先判断constexpr_expected。

​	如果不需要const，那就visit操作数，然后根据运算符得到value_result结果；如果需要const，就得到相应const_result。考虑所有的运算符即可。以模(mod)为例，通过builder.CreateSRem()计算。

​    **1.2.6 Decl+Define：visit(var_def_stmt_syntax &node)**

​	1.2.6.1 对于局部int：

​		builder.CreateAlloca()，参数中类型为整形，数组长度为nullptr。如果有初始化，则accept，并存入value_result，通过CreateStore进行存储。需要注意的是node.initializers的类型为ptr_list\<expr_syntax\>，取[0]来accept。

​	1.2.6.2 对于局部数组：

​		array_length必须不是variable。创建也是通过builder.CreateAlloca()，但是类型参数为ArrayType::get(Type::getInt32Ty(context), const_result)。然后通过initializer得到初始值，再通过CreateGEP得到元素指针，再CreateStore。为了后面load的时候gep方便，存入的时候按照IdxList={ConstNum(0), ConstNum(i++)}传入。注意CreateAlloca的时候ArraySize参数可以传入nullptr，也可以ConstNum(1)，因为这两个的处理都是当成1维数组，只有当ArraySize大于等于2，才会体现在llvm ir中。

​	1.2.6.3 对于全局int：

​		通过new GlobalVariable()声明，注意第一个module参数要*module.get()，因为module的类型。要传入type，还有is_constant，以及init。没有init就默认0.

​	1.2.6.4 对于全局数组：

​		通过new GlobalVariable()声明。type为ArrayType::get(Type::getInt32Ty(context), len)，传入的Initializer要ConstantArray::get(ArrayType::get(Type::getInt32Ty(context), len), values)，其中传入的IdxList需要时可以是std::vector\<Constant *\>。这里要求数组的长度，初始化都不是variable，包括const int。

​	1.2.6.5以上的声明/定义之后都要declare_variable，存入符号表。

​    **1.2.7 Assign：visit(assign_stmt_syntax &node)**

​	通过node.target->accept()得到target地址，通过node.value->accpet()得到value，通过CreateStore()赋值。

​    **1.2.8 Call：visit(func_call_stmt_syntax &node)**

​	通过CreateCall，参数中的“参数”是{}，因为没有参数。

​    **1.2.9 If：visit(if_stmt_syntax &node)**

​	这里需要注意的地方是llvm ir里每个BasicBlock都必须有语句执行。所以每次builder.SetInsertPoint之后都要有语句执行。

​	对于if语句，我BasicBlock::Create了ifB，thenB，elseB，afterB。

​	先setinsertpoint(ifB)，然后 node.pred->accept()，然后CreateBr，根据的cond是根据存下来的value_result。然后setinsertpoint(thenB)，然后node.then_body->accpet()。然后CreateBr(afterB)。然后setinsertpoint(elseB)，如果有elsebody，那就else_body->accpet。之后CreateBr(afterB)。之后要setinsertpoint(afterB)。

​    **1.2.10 While：visit(while_stmt_syntax &node)**

​	对于while，与if类似，比if简单。不再赘述。

​    **1.2.11 Cond：visit(cond_syntax &node)**

​	遍历2个oprand，然后根据比较的符号，选择对应的CreateICmp种类。比如是否相等，就是CreaetIcmpEQ(lhs, rhs)，结果存入value_result。

### **1.3错误处理：**

​	为了得到尽可能多的错误检查，在每次检查出错误之后继续检查，但是不生成错误语句。

​    **1.3.1 int/array混淆：**

​	在visit(lval)时，通过std::get\<2\>(lookup_variable(node.name))得到is_array属性：如果为false，则不是array，如果有下标，报错；如果为true，是array，如果没有下标，报错。

​    **1.3.2 重复命名/未声明错误：**

​	函数重名：在fun_def处首先查找函数名是否在funcions中。如果已经存在，则报错。

​	函数未定义：在fun_call处首先检查函数名是否在functions中。如果不存在，则报错。

​	变量重名；在var_def处通过variables[0].count(node.name)的返回值是否大于0判断是否重名。(由于变量重名只需要并且只应该检查本作用域，所以不用lookup_variable函数)

​	变量未定义：在lval处首先通过std::get\<0\>(lookup_variable(node.name))(跟上面的变量重名用了不一样的方式。)来检查所有作用于中是否存在。如果不存在则报错。

​    **1.3.3 数组初始化越界错误：**

​	全局和局部的处理方式相同，因为要求定义时的数组长度都是整形。可以根据node.array_length->accept()得到const_result表示声明长度。通过node.initializer.size()得到init的长度，如果后者大于前者，则too much报错。

​    **1.3.4 数组声明长度为变量/非正数错误：**

​	长度是否为变量，通过node.array_length->accept()时的visit(lval)得到报错。因为array_length->accept()的时候constexpr_expected是true，lval_as_rval是true，在visit(lval)中报错。

​	长度是否为负数，则通过得到的长度结果const_result，如果为负，则报错。

​    **1.3.5 常量赋值错误：**

​	在assign中，判断target是否为const，如果为const，则报错。当然，为了检查出更多的错，先舍弃target结果，然后继续检查value，语句最后检查是否有错误，如果有则不生成assign语句(如CreateStore)。

​    **1.3.6  全局初始化含变量错误：**

​	全局下，constexpr_expected为true，如果初始化含变量，则会在visit(lval)的时候报错。

​    **1.3.7 除数为0**

​	对于constexpr_expected=true的表达式，如果除数为0，则报错。

​	而对于constexpr_expected=false的表达式，则因为判断复杂而没有检查。



## **2.遇到的问题及对策+总结思考**

```
2.1 API的使用方法
  llvm ir 的API与Instruction之间没有比较清晰的对应介绍文档，导致知道语句但是经常不清楚具体应该用哪个api。有的时候虽然知道了api，但是对于参数没有详细的说明，所以只能通过猜测，以及google。
  比如GEP的指令，找了挺久。最后是在google中找到STACKOVERFLOW看到有gep的代码example，然后推测出其用法，再通过make，-emit-llvm观察ir判断是否使用正确的。这样的过程是十分低效的。但是不清楚llvm ir的api的结果只能是这样。长期的生产过程中肯定不能容忍这样的情况经常发生，必须理解透彻才能释放生产力。
```

```
2.2 错误处理
  在错误处理的时候由于想要多检查出错误，语句之间不能相互影响，要求每条语句之间就必须保证constexpr_expected，lval_as_rval等不能影响。
  这一点由于做到后期头脑麻木对于各种error出了不知道多少bug。
  所以说coding，debugging的时候必须保持头脑清醒。这个时候一个合格的文档就可以起到一定的帮助。最后也要注意身心调节，中间放松放松，不然一直绷着代码肯定会bug百出。
```

```
2.3
  本次实验受助于Visual Studio的IntelliSense之强大。在coding过程中时刻能够收到诸如函数参数类型，类成员等的提醒。尤其是这次很多API不熟悉甚至没听过的前提下，效率得到了很大的提升。
  但是IntelliSense也有坏处。那就是我可能会在coding过程中过分依赖于其提醒，而忽略了自身对API的理解，也可能会导致我离开VS就会严重影响coding效率及正确性的结果。这一点需要反思，以后的coding可能要求对API的充分理解，必须考虑到IntelliSense的这一点影响。
```

```
2.4
  总的来说，本次试验的收货还是很大的。
```

