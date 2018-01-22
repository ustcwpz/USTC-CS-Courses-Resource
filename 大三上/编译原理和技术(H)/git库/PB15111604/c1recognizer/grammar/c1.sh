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
