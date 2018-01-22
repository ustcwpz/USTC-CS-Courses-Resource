#!/bin/bash

echo alias antlr4='java org.antlr.v4.Tool'
alias antlr4='java org.antlr.v4.Tool'

echo antlr4 -Dlanguage=Python3 MultFirst.g4
antlr4 -Dlanguage=Python3 MultFirst.g4

echo python3 mult_calculator.py 
echo
python3 mult_calculator.py 
