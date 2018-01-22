## <center>**Lab1-2-左递归**</center>

## pb15111604 金泽文



**测试说明**

​	在lab-1-2-answer/中分别执行一下指令

```
sh plus.sh
sh mult.sh
sh unsupport.sh
```

​	*plus.sh 用于测试 PlusFirst.g4*

```
root@ubuntu:/home/test/PB15111604/lab-1-2-answer# sh plus.sh
alias antlr4=java org.antlr.v4.Tool
antlr4 -Dlanguage=Python3 PlusFirst.g4
python3 plus_calculator.py

Please enter a expression: 1+5*6
(1+5)
(6*6)
36
```

​	*mult.sh 用于测试 MultFirst.g4*

```
root@ubuntu:/home/test/PB15111604/lab-1-2-answer# sh mult.sh
alias antlr4=java org.antlr.v4.Tool
antlr4 -Dlanguage=Python3 MultFirst.g4
python3 mult_calculator.py

Please enter a expression: 1+5*6 
(5*6)
(1+30)
31
```

​	*unsupport.sh 用于测试不支持的左递归类型。*

```
root@ubuntu:/home/test/PB15111604/lab-1-2-answer# sh unsupport.sh
alias antlr4=java org.antlr.v4.Tool
antlr4 -Dlanguage=Python3 UnsupportedLeftRecursive.g4

error(119): UnsupportedLeftRecursive.g4::: The following sets of rules are mutually left-recursive [s, a] and [m] and [n] and [o] and [p] and [q] and [r]
```



**优先级**

而对于antrl4对于优先级的处理，比如：

- `e : e '*' e # Mult | e '+' e # Add | INT # Int ;`

- `e : e '+' e # Add | e '*' e # Mult | INT # Int ;`

  经过我的检验，发现左边的优先级更高，也就是说在一个|产生式中优先按照左边递推。​



关于左递归的思考**

​	刚开始进行测试，将C1Parser.g4 的compilationUnit部分改为：

```
compilationUnit: compilationUnit?  (decl | funcdef) EOF
```

​	结果：

```
reaper@ubuntu:/home/PB15111604/c1recognizer/grammar$ antlr4 *.g4
error(119): C1Parser.g4::: The following sets of rules are mutually left-recursive [compilationUnit]
```

​	提示为左递归错误。

​	可能是因为antlr4对支持的左递归的类型也有限制。

​	而我单独设置一个简单的SupportedLeftRecursive.g4如下：

```
reaper@ubuntu:/home/PB15111604/c1recognizer/grammar$ cat -n SupportedLeftRecursive.g4 
     1	parser grammar SupportedLeftRecursive;
     2	options { tokenVocab = C1Lexer;  }
     3	
     4	a: a s | s;
     5	s: Number;
```

​	结果:

```
reaper@ubuntu:/home/PB15111604/c1recognizer/grammar$ antlr4 SupportedLeftRecursive.g4 
reaper@ubuntu:/home/PB15111604/c1recognizer/grammar$ 
```

​	没有报错。说明**`对于最基本的直接左递归，antlr4是支持的`**。

​	而对于

```
reaper@ubuntu:/home/PB15111604/c1recognizer/grammar$ cat -n pportedLeftRecursive1.g4 
     1	parser grammar SupportedLeftRecursive1;
     2	options { tokenVocab = C1Lexer;  }
     3	
     4	a: a? s;
     5	s: Number;
```

​	结果：

```
reaper@ubuntu:/home/PB15111604/c1recognizer/grammar$ antlr4 UnsupportedLeftRecursive1.g4 
error(119): UnsupportedLeftRecursive1.g4::: The following sets of rules are mutually left-recursive [a]
```

​	提示为左递归错误。而这里的语言语上一个直接左递归的例子相同，只不过形式不同，这里用了？，结果却报错了。

​	类似的，想到 * + 等符号，果然都报错了。

​	继续想到的一个间接左递归的例子：

```
reaper@ubuntu:/home/PB15111604/c1recognizer/grammar$ cat -n UnsupportedLeftRecursive2.g4 
     1	parser grammar UnsupportedLeftRecursive2;
     2	options {tokenVocab = C1Lexer; }
     3	
     4	s: a s | Number;
     5	a: s a | Int;
```

​	结果:

```
reaper@ubuntu:/home/PB15111604/c1recognizer/grammar$ antlr4 UnsupportedLeftRecursive2.g4 
error(119): UnsupportedLeftRecursive2.g4::: The following sets of rules are mutually left-recursive [s, a] 0
```

​	提示为左递归错误。

​	最后将以上归结到一个文件UnsupportedLeftRecursive.g4中。

```
reaper@ubuntu:/home/PB15111604/c1recognizer/grammar$ cat  UnsupportedLeftRecursive.g4 
parser grammar UnsupportedLeftRecursive;
options {tokenVocab = C1Lexer; }

s: a s | Number;
a: s a | Int;

m: m? b;
b: Number;

n: n* b;

o: o+ b;

p: p?? b;

q: q*? b;

r: r+? b;
```

​	结果：

```
reaper@ubuntu:/home/PB15111604/c1recognizer/grammar$ antlr4 UnsupportedLeftRecursive.g4 
error(119): UnsupportedLeftRecursive.g4::: The following sets of rules are mutually left-recursive [s, a] and [m] and [n] and [o] and [p] and [q] and [r]
```

​	综上，antlr4支持的左递归只有形如 

```
a: a s| s;
s: Number
```

​	这样的**`最直接的左递归`**。

​	而**不支持间接左递归，以及“较为复杂”的、类似直接左递归而实际上需要转化为间接左递归的左递归**。后者的例子如：

```
m: m? b;
b: Number;

n: n* b;

o: o+ b;

p: p?? b;

q: q*? b;

r: r+? b;
```

​	等。

​	对于此，我的分析是：

​	以 m: m? b; 为例，antlr4会将?类似展开为

```
m: m’ b;
m’: m | /* epsilon */ ;
```

​	即在内部展开成了间接左递归，而间接左递归是不能被antlr4实现的。	

​	* 、+  的情况类似。

​	而至于antlr4间接左递归还未实现的原因，我分析认为可能是因为

```
直接左递归可以通过循环进行左递归预测，及时剪枝。而间接左递归由于逻辑复杂，很难做到直接左递归那样。
同时，间接左递归一般可以转化成直接左递归。
最后，直接左递归也是antlr4中新增加的特性，也许未来能加入间接左递归也不可知。
```



**`以上是未经调研得到的自己思考的过程，下面是调研之后所得。`**

​	经过调研验证，antlr4实现直接左递归的支持，确实是通过将左递归替换为一个判定循环(predicated loop)实现的。

​	并且经过调研发现，antlr4支持的直接左递归种类有限制。

​	首先，antlr4采用的是ALL(*)，A指Adaptive，是由ll( * ) 改进的算法。

​	**`ALL(*)在碰到多个可选分支的时候，为每个分支运行一个子parser，每个子parser有自己的dfa，以伪并行的方式探索所有可能的路径，一旦某个子parser完成匹配，则选定并终止其他parser。`**

​	显然，这个生成子parser再并行探索的过程将消耗大量的计算量，出于实际考量，antlr4只支持4中直接左递归：

```
· 二元，如expr op expr或expr (op1 | op2 | ... | opN) expr。
· 三元，如expr '?' expr ':' expr
· 一元前缀，即把任意元素的尾递归视做一元前缀，如'(' type ')' expr或('+' | '-' | '++' | '--') expr
· 一元后缀，如expr '.' identifier
```

​	这样，间接左递归并不被支持也可以理解。因为复杂的产生式将产生巨大的计算量，而对于文法来说，间接左递归一般手工转化为直接左递归，而直接左递归又以以上三种为主，这样既能涵盖绝大部分的需求，又能保证计算量不爆炸，赞！



以上，就是我对于antlr4左递归的思考、分析、与调研。



**`说明`**：以上的中间程序是我思考的过程测试用的，并没有提交到git库中，而是将最后的结果总结到了要提交的g4中。
