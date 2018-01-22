## <center>**Lab1-3-AST**</center>

## pb15111604 金泽文

###1.**了解、使用ANTLR分析树的编程接口，书面总结它们与你在lab1-2中写的文法之间的关系；**

分析树的编程接口：

​    · visitSomething 对应非终结符something：

​        如visitCompilationUnit 对应非终结符compilationUnit

​    · SomethingContext类内部成员大部分对应非终结符something对应产生式右部：

​        如CompilationUnitContext类内部，

​        大写的EOF函数对应右部终结符EOF，返回节点指针

​        小写的decl，funcdef函数对应右部非终结符decl， funcdef，返回节点指针。

​	另外，如exp非终结符对应的产生式可能右部有很多exp，如ExpContext类的exp()就会返回一个vector。



###2.**ATN的英文全称是什么，它代表什么？**

​    全称：Augmented transition network

​    代表的是用于解析相对复杂的自然语言的，在形式语言的基础上使用的一种图结构。在有限状态机的基础上向有限状态模型增加递归机制，构造转换图，更有效的实现解析。



###3.**SLL的英文全称是什么，它和LL、以及ALL(*)的区别是什么? 它们分别怎么对待文法二义、试探回溯？**

​    SLL的英文全称：Strong ll

​    对于SLL(k)，LL(k)

​    当k=1时，SLL是SLL(1)，LL是LL(1)，此时SLL和LL等价。

​    当k>1时，对于文法：G=(N,T,P,S)，

​        LL(k)要计算FIRSTk，FOLLOWk，然后做表。

​        SLL(k)要看是否对所有的

```
A→α
A→β
```

​        都有

```
 FIRSTk(αFOLLOWk(A))∩FIRSTk(βFOLLOWk(A))=∅
```

​    根据《anltr4权威指南》，ALL(\*)-Adaptive LL(\*)，是v3的LL(\*)的扩展，在运行时动态分析。

​    ALL(*)可以说没有回溯。它改进了传统LL(\*)的前瞻算法。其在碰到多个可选分支的时候，会为每一个分支运行一个子解析器，每一个子解析器都有自己的DFA，这些子解析器以伪并行的方式探索所有可能的路径，当某一个子解析器完成匹配之后，它走过的路径就会被选定，而其他的子解析器会被杀死，本次决策完成。

​    antlr3中，SLL(\*),LL(\*)则会采取失败回溯的策略，在遇到失败的时候返回并开始尝试其他匹配方式。

###4.**了解并总结enterRecursionRule、unrollRecursionContexts、adaptivePredict函数的作用、接口和主要处理流程。**

####enterRecursionRule:

```c++
void Parser::enterRecursionRule(
  		ParserRuleContext *localctx, 
  		size_t state, 
 		size_t /*ruleIndex*/, 
  		int precedence) 
{
  	setState(state);
  	_precedenceStack.push_back(precedence);
  	_ctx = localctx;
  	_ctx->start = _input->LT(1);
  	if (!_parseListeners.empty()) {
    	triggerEnterRuleEvent(); 
      // simulates rule entry for left-recursive rules
  	}
}
```

​    作用：开始递归前的准备。

​    接口：如上：

```
void Parser::enterRecursionRule(
	ParserRuleContext *localctx, 
	size_t state, 
	size_t /*ruleIndex*/, 
	int precedence
)
```

​    流程：设置状态；优先级入栈；设置环境；设置环境起点；如果有listern触发左递归lisenter

####unrollRecursionContexts:

```c++
void Parser::unrollRecursionContexts(ParserRuleContext *parentctx) 
{
	_precedenceStack.pop_back();
	_ctx->stop = _input->LT(-1);
	ParserRuleContext *retctx = _ctx; 
	// save current ctx (return value)

	// unroll so ctx is as it was before call to recursive method
	if (_parseListeners.size() > 0) {
    	while (_ctx != parentctx) {
        	triggerExitRuleEvent();
        	_ctx = dynamic_cast<ParserRuleContext *>(_ctx->parent);
    }
	} else {
    	_ctx = parentctx;
	}

	// hook into tree
	retctx->parent = parentctx;

	if (_buildParseTrees && parentctx != nullptr) {
    	// add return ctx into invoking rule's tree
    	parentctx->addChild(retctx);
	}
}
```
​    作用：递归结束后的保存与恢复。

​    接口：

```c++
void Parser::unrollRecursionContexts(
	ParserRuleContext *parentctx) 
```

​    流程：优先级出栈；设置ctx结束点；保存返回的ctx；如果有listener，触发使其结束;返回到递归开始前的ctx，将刚才保存的ctx加到树上。

####adaptivePredict

```c++
size_t ParserATNSimulator::adaptivePredict(TokenStream *input, size_t decision, ParserRuleContext *outerContext) {

#if DEBUG_ATN == 1 || DEBUG_LIST_ATN_DECISIONS == 1
        std::cout << "adaptivePredict decision " << decision << " exec LA(1)==" << getLookaheadName(input) << " line "
            << input->LT(1)->getLine() << ":" << input->LT(1)->getCharPositionInLine() << std::endl;
#endif

    _input = input;
    _startIndex = input->index();
    _outerContext = outerContext;
    dfa::DFA &dfa = decisionToDFA[decision];
    _dfa = &dfa;

    ssize_t m = input->mark();
    size_t index = _startIndex;

    // Now we are certain to have a specific decision's DFA
    // But, do we still need an initial state?
    auto onExit = finally([this, input, index, m] {
        mergeCache.clear(); // wack cache after each prediction
        _dfa = nullptr;
        input->seek(index);
        input->release(m);
    });

    dfa::DFAState *s0;
    if (dfa.isPrecedenceDfa()) {
        // the start state for a precedence DFA depends on the current
        // parser precedence, and is provided by a DFA method.
        s0 = dfa.getPrecedenceStartState(parser->getPrecedence());
    } else {
        // the start state for a "regular" DFA is just s0
        s0 = dfa.s0;
    }

    if (s0 == nullptr) {
        bool fullCtx = false;
        std::unique_ptr<ATNConfigSet> s0_closure = computeStartState(dynamic_cast<ATNState *>(dfa.atnStartState), &ParserRuleContext::EMPTY, fullCtx);_stateLock.writeLock();
        if (dfa.isPrecedenceDfa()) {
            /* If this is a precedence DFA, we use applyPrecedenceFilter
             * to convert the computed start state to a precedence start
             * state. We then use DFA.setPrecedenceStartState to set the
             * appropriate start state for the precedence level rather
             * than simply setting DFA.s0.
             */
            dfa.s0->configs = std::move(s0_closure); // not used for prediction but useful to know start configs anyway
            dfa::DFAState *newState = new dfa::DFAState(applyPrecedenceFilter(dfa.s0->configs.get())); /* mem-check: managed by the DFA or deleted below */
            s0 = addDFAState(dfa, newState);
            dfa.setPrecedenceStartState(parser->getPrecedence(), s0, _edgeLock);
            if (s0 != newState) {
                delete newState; // If there was already a state with this config set we don't need the new one.
            }
        } else {
            dfa::DFAState *newState = new dfa::DFAState(std::move(s0_closure)); /* mem-check: managed by the DFA or deleted below */
            s0 = addDFAState(dfa, newState);

            delete dfa.s0; // Delete existing s0 DFA state, if there's any. 
            dfa.s0 = s0;
            if (s0 != newState) {
                delete newState; // If there was already a state with this config set we don't need the new one.
            }
        }
        _stateLock.writeUnlock();
    }

    // We can start with an existing DFA.
    size_t alt = execATN(dfa, s0, input, index, outerContext != nullptr ? outerContext : &ParserRuleContext::EMPTY);

    return alt;
}
  
```

​    作用：找到决策的DFA并开始预测。

​    接口：

```c++
size_t ParserATNSimulator::adaptivePredict(TokenStream *input, size_t decision, ParserRuleContext *outerContext)
```

​    流程：为预测清空缓存；找到初始状态；lock  _statelock；检查DFA；unlock；预测