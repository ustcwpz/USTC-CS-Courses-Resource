#!/bin/bash
echo alias antlr4='java org.antlr.v4.Tool'
alias antlr4='java org.antlr.v4.Tool'

echo antlr4 -Dlanguage=Python3 UnsupportedLeftRecursive.g4
echo 
antlr4 -Dlanguage=Python3 UnsupportedLeftRecursive.g4
