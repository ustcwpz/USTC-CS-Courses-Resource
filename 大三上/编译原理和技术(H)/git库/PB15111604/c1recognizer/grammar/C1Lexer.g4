lexer grammar C1Lexer;

tokens {
    Comma,
    SemiColon,
    Assign,
    LeftBracket,
    RightBracket,
    LeftBrace,
    RightBrace,
    LeftParen,
    RightParen,
    If,
    Else,
    While,
    Const,
    Equal,
    NonEqual,
    Less,
    Greater,
    LessEqual,
    GreaterEqual,
    Plus,
    Minus,
    Multiply,
    Divide,
    Modulo,

    Int,
    Void,

    Identifier,
    Number
}

Comma: ',' ;
SemiColon: ';' ;
Assign: '=' ;
LeftBracket: '[' ;
RightBracket: ']' ;
LeftBrace: '{' ;
RightBrace: '}' ;

LeftParen: '(' ;
RightParen: ')' ;

If: 'if' ;
Else: 'else' ; 
While: 'while' ;
Const: 'const' ;
Equal: '==' ;
NonEqual: '!=' ;
Less: '<' ;
Greater: '>' ;
LessEqual: '<=' ;
GreaterEqual: '>=' ;

Plus: '+'  ;
Minus: '-' ;
Multiply: '*' ;
Divide: '/' ;
Modulo: '%' ;

Int: 'int' ;
Void: 'void' ;

Identifier: [a-zA-Z_] [a-zA-Z0-9_]* ;

Number: [0-9]+ | '0' [xX] [0-9a-fA-F]+ ;

Comment_inline: '//' ~[\n]*? ( '\\' '\r'* '\n' ~[\n]*?)* '\r'* '\n' -> skip ;
Comment_block: '/*' .*? '*/' -> skip ;

WhiteSpace: [ \t\r\n]+ -> skip ;

