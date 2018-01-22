##<center>**Lab1-1**</center>##

## pb15111604 金泽文

----------------------

​	过程比较顺利，除了一些智障的问题之外（中间出了一个大小写的问题），

​	对于注释，要考虑下面的情况：

     1  int i = 0;
     2  void main()   //test\
     3  sd\f \
     4  df
     5
     6  //\r\
     7  //\n\
     8
     9  {
    10      i = 1;
    11  }
​	按理说注释里除了行尾的 '\'，前面也可以有 '\'，但是github上之前的.g4没有考虑这个情况:

```reaper@ubuntu:~/2017fall/c1recognizer/src/grammar$ grun C1Lexer tokens -tokens ../../test/test_cases/simple.c1 |nl
reaper@ubuntu:~/2017fall/c1recognizer/src/grammar$ grun C1Lexer tokens -tokens ../../test/test_cases/simple.c1 |nl
Warning: TestRig moved to org.antlr.v4.gui.TestRig; calling automatically
line 2:20 token recognition error at: '\'
line 3:2 token recognition error at: '\'
line 3:5 token recognition error at: '\'
line 6:2 token recognition error at: '\'
line 6:4 token recognition error at: '\'
line 7:2 token recognition error at: '\'
line 7:4 token recognition error at: '\'
 1  [@0,0:2='int',<'int'>,1:0]
 2  [@1,4:4='i',<Identifier>,1:4]
 3  [@2,6:6='=',<'='>,1:6]
 4  [@3,8:8='0',<Number>,1:8]
 5  [@4,9:9=';',<';'>,1:9]
 6  [@5,11:14='void',<'void'>,2:0]
 7  [@6,16:19='main',<Identifier>,2:5]
```

​	考虑到实验说明里对lexical rules 中 '*?'，想到以下方法：

```Comment_inline: '//' ~[\n]*? ( '\\' '\r'* '\n' ~[\n]*?)* '\r'* '\n' -> skip;
Comment_inline: '//' ~[\n]*? ( '\\' '\r'* '\n' ~[\n]*?)* '\r'* '\n' -> skip ;
```

​	(这里我认为\r\r\r\n的写法也是符合标准的，所以采用 '\r'* '\n'的写法) 

​	我们所要~的只有'\n'，因为中间可能会有零星的'\\'出现。这么写之后，两个例子都可以过关啦！(以下的test就是上传的C1Lexer)

```
reaper@ubuntu:~/2017fall/c1recognizer/src/grammar$ grun test tokens -tokens ../../test/test_cases/simple.c1 |nl
Warning: TestRig moved to org.antlr.v4.gui.TestRig; calling automatically
 1  [@0,0:2='int',<'int'>,1:0]
 2  [@1,4:4='i',<Identifier>,1:4]
 3  [@2,6:6='=',<'='>,1:6]
 4  [@3,8:8='0',<Number>,1:8]
 5  [@4,9:9=';',<';'>,1:9]
 6  [@5,11:14='void',<'void'>,2:0]
 7  [@6,16:19='main',<Identifier>,2:5]
 8  [@7,20:20='(',<'('>,2:9]
 9  [@8,21:21=')',<')'>,2:10]
10  [@9,57:57='{',<'{'>,9:0]
11  [@10,63:63='i',<Identifier>,10:4]
12  [@11,65:65='=',<'='>,10:6]
13  [@12,67:67='1',<Number>,10:8]
14  [@13,68:68=';',<';'>,10:9]
15  [@14,70:70='}',<'}'>,11:0]
16  [@15,72:71='<EOF>',<EOF>,12:0]
```

​	以及：

```
reaper@ubuntu:~/2017fall/c1recognizer/src/grammar$ grun test tokens -tokens ../../test/test_cases/lexical_tokens.c1 |nl 
Warning: TestRig moved to org.antlr.v4.gui.TestRig; calling automatically  
 1  [@0,0:3='void',<'void'>,1:0]
 2  [@1,5:8='main',<Identifier>,1:5]
 3  [@2,9:9='(',<'('>,1:9]
 4  [@3,10:10=')',<')'>,1:10]
 5  [@4,12:12='{',<'{'>,1:12]
 6  [@5,18:22='const',<'const'>,2:4]
 7  [@6,24:26='int',<'int'>,2:10]
 8  [@7,28:28='v',<Identifier>,2:14]
 9  [@8,29:29='[',<'['>,2:15]
 ...
117  [@116,359:363='while',<'while'>,14:4]     
118  [@117,365:365='(',<'('>,14:10]            
119  [@118,366:366='i',<Identifier>,14:11]     
120  [@119,368:369='<=',<'<='>,14:13]          
121  [@120,371:371='0',<Number>,14:16]         
122  [@121,372:372=')',<')'>,14:17]            
123  [@122,374:374='i',<Identifier>,14:19]     
124  [@123,376:376='=',<'='>,14:21]            
125  [@124,378:378='i',<Identifier>,14:23]     
126  [@125,380:380='-',<'-'>,14:25]            
127  [@126,382:382='1',<Number>,14:27]         
128  [@127,383:383=';',<';'>,14:28]            
129  [@128,389:389='i',<Identifier>,15:4]      
130  [@129,391:391='=',<'='>,15:6]             
131  [@130,393:402='0x1234FeDc',<Number>,15:8] 
132  [@131,403:403=';',<';'>,15:18]            
133  [@132,405:405='}',<'}'>,16:0]             
134  [@133,406:405='<EOF>',<EOF>,16:1]         
```

错误样例

​	wrong_sample.c1内容如下：

     1	$
     2	/*
     3	1a
     4	`
     5	~                                             
```grun C1Lexer tokens -tokens  /home/PB15111604/c1recognizer/test/test_cases/wrong_sample.c1
grun C1Lexer tokens -tokens /home/PB15111604/c1recognizer/test/test_cases/wrong_sample.c1
```

​	结果：

```line 1:0 token recognition error at: '
line 1:0 token recognition error at: '$'
line 4:0 token recognition error at: '`'
line 5:0 token recognition error at: '~'
[@0,2:2='/',<'/'>,2:0]
[@1,3:3='*',<'*'>,2:1]
[@2,5:5='1',<Number>,3:0]
[@3,6:6='a',<Identifier>,3:1]
[@4,12:11='<EOF>',<EOF>,6:0]

```

​	结果正常。