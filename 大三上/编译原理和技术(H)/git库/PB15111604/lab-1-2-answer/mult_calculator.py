'''Expression recognizer.
Handles expression described in expr.g4.
Grammar file should be compiled by antlr4 with option '-Dlanguage=Python3' before executing this.
Module 'antlr4' is required.
'''
import antlr4
import MultFirstLexer
import MultFirstParser
import MultFirstListener
from typing import Mapping


class Listener(MultFirstListener.MultFirstListener):
    '''Listener doing calculation based on recognized input.
    '''

    def __init__(self, var_value_source: Mapping[str, int]):
        self.var_value_source = var_value_source
        
    def exitMult(self, ctx: MultFirstParser.MultFirstParser.MultContext):
        print('(%d*%d)'% (ctx.getChild(0).value, ctx.getChild(2).value))
        ctx.value = ctx.getChild(0).value * ctx.getChild(2).value

    def exitNum(self, ctx: MultFirstParser.MultFirstParser.NumContext):
        ctx.value = int(str(ctx.getChild(0)))

    def exitId(self, ctx: MultFirstParser.MultFirstParser.IdContext):
        ctx.value = self.var_value_source[str(ctx.getChild(0))]

    def exitPlus(self, ctx: MultFirstParser.MultFirstParser.PlusContext):
        print('(%d+%d)'% (ctx.getChild(0).value, ctx.getChild(2).value))
        ctx.value = ctx.getChild(0).value + ctx.getChild(2).value

    def exitBrac(self, ctx: MultFirstParser.MultFirstParser.BracContext):
        ctx.value = ctx.getChild(1).value
        print('(%d)'% ctx.getChild(1).value)

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
    PARSER = MultFirstParser.MultFirstParser(antlr4.CommonTokenStream(MultFirstLexer.MultFirstLexer(
        antlr4.InputStream(input('Please enter a expression: ')))))
    PARSER.addParseListener(Listener(LazyInputDict()))
    print(PARSER.expr().value)
