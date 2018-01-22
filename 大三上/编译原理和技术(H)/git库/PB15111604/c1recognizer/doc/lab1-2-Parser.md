##<center>**Lab1-2-C1Parser**</center>##

## pb15111604 金泽文



**测试说明**

​	在c1recognizer/中执行

```
sh c1.sh 
```

​	即可测试simple.c1

​	*c1.sh内容：*

```
root@ubuntu:/home/test/PB15111604/c1recognizer/grammar# cat c1.sh
#!/bin/bash

echo alias grun='java org.antlr.v4.runtime.misc.TestRig'
alias grun='java org.antlr.v4.runtime.misc.TestRig'
echo alias antlr4='java org.antlr.v4.Tool'
alias antlr4='java org.antlr.v4.Tool'
#compile grammar to Java source code
echo antlr4 *.g4
antlr4 *.g4
# Compile Java source code
echo javac *.java
javac *.java
# Testing lexer
echo grun C1Lexer tokens -tokens ../test/test_cases/lexer/simple.c1
grun C1Lexer tokens -tokens ../test/test_cases/lexer/simple.c1
# Testing lexer + parser, GUI version parse tree
echo grun C1 compilationUnit -gui ../test/test_cases/lexer/simple.c1
grun C1 compilationUnit -gui ../test/test_cases/lexer/simple.c1
# Testing lexer + parser, console printed version parse tree
echo grun C1 compilationUnit -tree ../test/test_cases/lexer/simple.c1
grun C1 compilationUnit -tree ../test/test_cases/lexer/simple.c1
```

​	

**实验过程**

​	大体是根据文法规则,写出parser.g4，很简单。下面是写的过程中产生的2个问题。

**1.语法规则问题**

​	一开始，对于

```
compilationUnit: [ compilationUnit ] ( decl | funcdef )
```

​	报错：

```
error(50): C1Parser.g4:4:17: syntax error: ' compilationUnit ' came as a complete surprise to me while matching alternative
```

​	将这一产生式改为

```
compilationUnit: ( decl | funcdef )+;
```

​	上面的错误就没有了。

​	但是下面又有错误：

```
error(50): C1Parser.g4:9:29: syntax error: ' exp ' came as a complete surprise to me while looking for rule element
error(50): C1Parser.g4:15:29: syntax error: ' exp ' came as a complete surprise to me while looking for rule element
```

​	对应的错误是

```
constdef: 
    Identifier Assign exp
    | Identifier LeftBracket [ exp ] RightBracket Assign LeftBrace exp { Comma exp } RightBrace;
    
vardef: 
    Identifier 
    | Identifier LeftBracket exp RightBracket 
    | Identifier Assign exp 
    | Identifier LeftBracket [ exp ] RightBracket Assign LeftBrace exp { Comma exp } RightBrace;
```

​	检查的时候突然想起来.g4中的 [], {}与EBNF规则不同，于是修改了一番。

**2.EOF问题**

​	antlr4 *.g4; javac *.java 没有报错。但是在grun 的时候发现：

```
[@15,38:37='<EOF>',<EOF>,6:0]
```

​	考虑到EOF token的存在，应该修改我的compilationUnit产生式为：

```
compilationUnit: (decl | funcdef)+ EOF;
```

​	果然，比较了一下grun -gui 的结果，发现文法里有没有EOF，得到的 parse tree 是不一样的，多了EOF规则之后，得到的图片里多了 < EOF >节点。

​	grun -tree 之后也是

​	有EOF：

```
reaper@ubuntu:/home/PB15111604/c1recognizer/grammar$ grun C1 compilationUnit -tree ../test/test_cases/lexer/simple.c1 
Warning: TestRig moved to org.antlr.v4.gui.TestRig; calling automatically
(compilationUnit (decl (vardecl int (vardef i = (exp 0)) ;)) (funcdef void main ( ) (block { (stmt (lval i) = (exp 1) ;) })) <EOF>)
```

​	没有EOF：

```
reaper@ubuntu:/home/PB15111604/c1recognizer/grammar$ grun C1 compilationUnit -tree ../test/test_cases/lexer/simple.c1 
Warning: TestRig moved to org.antlr.v4.gui.TestRig; calling automatically
(compilationUnit (decl (vardecl int (vardef i = (exp 0)) ;)) (funcdef void main ( ) (block { (stmt (lval i) = (exp 1) ;) })))
```

​	结果不同。

​	同时，

**实验结果 **

​	测试simple.c1的结果：

```
root@ubuntu:/home/test/PB15111604/c1recognizer/grammar# sh c1.sh 
alias grun=java org.antlr.v4.runtime.misc.TestRig
alias antlr4=java org.antlr.v4.Tool
antlr4 C1Lexer.g4 C1Parser.g4
javac C1Lexer.java C1Parser.java C1ParserBaseListener.java C1ParserListener.java
grun C1Lexer tokens -tokens ../test/test_cases/lexer/simple.c1
Warning: TestRig moved to org.antlr.v4.gui.TestRig; calling automatically
[@0,0:2='int',<'int'>,1:0]
[@1,4:4='i',<Identifier>,1:4]
[@2,6:6='=',<'='>,1:6]
[@3,8:8='0',<Number>,1:8]
[@4,9:9=';',<';'>,1:9]
[@5,11:14='void',<'void'>,2:0]
[@6,16:19='main',<Identifier>,2:5]
[@7,20:20='(',<'('>,2:9]
[@8,21:21=')',<')'>,2:10]
[@9,23:23='{',<'{'>,3:0]
[@10,29:29='i',<Identifier>,4:4]
[@11,31:31='=',<'='>,4:6]
[@12,33:33='1',<Number>,4:8]
[@13,34:34=';',<';'>,4:9]
[@14,36:36='}',<'}'>,5:0]
[@15,38:37='<EOF>',<EOF>,6:0]
grun C1 compilationUnit -gui ../test/test_cases/lexer/simple.c1
Warning: TestRig moved to org.antlr.v4.gui.TestRig; calling automatically
Oct 08, 2017 5:52:15 PM java.util.prefs.FileSystemPreferences$1 run
INFO: Created user preferences directory.
grun C1 compilationUnit -tree ../test/test_cases/lexer/simple.c1
Warning: TestRig moved to org.antlr.v4.gui.TestRig; calling automatically
(compilationUnit (decl (vardecl int (vardef i = (exp 0)) ;)) (funcdef void main ( ) (block { (stmt (lval i) = (exp 1) ;) })) <EOF>)
```

​	一切正常。