grammar UnsupportedLeftRecursive;

Identifier: [a-zA-Z_] [a-zA-Z_0-9]*;
Number: [1-9] [0-9]*;
Plus: '+';
Multiply: '*';
WhiteSpace: [ \t\n\r]+ -> skip;

s: a s | Number;
a: s a | ;

m: m? b;
b: Number;

n: n* b;

o: o+ b;

p: p?? b;

q: q*? b;

r: r+? b;

