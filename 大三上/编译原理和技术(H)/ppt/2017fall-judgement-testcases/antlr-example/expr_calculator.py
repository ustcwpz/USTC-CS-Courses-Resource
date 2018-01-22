'''Expression recognizer.
Handles expression described in expr.g4.
Grammar file should be compiled by antlr4 with option '-Dlanguage=Python3' before executing this.
Module 'antlr4' is required.
'''
import antlr4
import exprLexer
import exprParser
import exprListener
from typing import Mapping


class Listener(exprListener.exprListener):
    '''Listener doing calculation based on recognized input.
    '''

    def __init__(self, var_value_source: Mapping[str, int]):
        self.var_value_source = var_value_source

    def exitMult(self, ctx: exprParser.exprParser.MultContext):
        ctx.value = ctx.getChild(0).value * ctx.getChild(2).value

    def exitNum(self, ctx: exprParser.exprParser.NumContext):
        ctx.value = int(str(ctx.getChild(0)))

    def exitId(self, ctx: exprParser.exprParser.IdContext):
        ctx.value = self.var_value_source[str(ctx.getChild(0))]

    def exitPlus(self, ctx: exprParser.exprParser.PlusContext):
        ctx.value = ctx.getChild(0).value + ctx.getChild(2).value

    def exitBrac(self, ctx: exprParser.exprParser.BracContext):
        ctx.value = ctx.getChild(1).value


class LazyInputDict(dict):
    '''A lazy dictionary asking for input when a new item is queried.'''

    def __getitem__(self, key):
        try:
            return dict.__getitem__(self, key)
        except KeyError:
            self[key] = int(
                input('Please enter value for variable \'{}\': '.format(key)))
        return dict.__getitem__(self, key)


if __name__ == '__main__':
    PARSER = exprParser.exprParser(antlr4.CommonTokenStream(exprLexer.exprLexer(
        antlr4.InputStream(input('Please enter a expression: ')))))
    PARSER.addParseListener(Listener(LazyInputDict()))
    print(PARSER.expr().value)
