#!/bin/bash
echo alias antlr4='java org.antlr.v4.Tool'
alias antlr4='java org.antlr.v4.Tool'

echo antlr4 -Dlanguage=Python3 PlusFirst.g4
antlr4 -Dlanguage=Python3 PlusFirst.g4

echo python3 plus_calculator.py 
echo
python3 plus_calculator.py 
