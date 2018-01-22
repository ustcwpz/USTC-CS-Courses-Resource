grammar PlusFirst;

Identifier: [a-zA-Z_] [a-zA-Z_0-9]*;
Number: [1-9] [0-9]*;
Plus: '+';
Multiply: '*';
WhiteSpace: [ \t\n\r]+ -> skip;

expr: expr Plus expr # Plus
    | expr Multiply expr # Mult
    | '(' expr ')' # Brac
    | Identifier # Id
    | Number # Num
    ;
