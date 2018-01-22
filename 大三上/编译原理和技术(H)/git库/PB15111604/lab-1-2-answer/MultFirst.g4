grammar MultFirst;

Identifier: [a-zA-Z_] [a-zA-Z_0-9]*;
Number: [1-9] [0-9]*;
Plus: '+';
Multiply: '*';
WhiteSpace: [ \t\n\r]+ -> skip;

expr: expr Multiply expr # Mult
    | expr Plus expr # Plus
    | '(' expr ')' # Brac
    | Identifier # Id
    | Number # Num
    ;
