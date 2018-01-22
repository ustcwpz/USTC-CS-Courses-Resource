**语言**：python3

**结构**：

​	6个状态转换函数：smton(dq, alpha)判断接收的字母是否符合转换

​	1个nfa函数：nfa(word)判断接收的子川是否符合nfa

​	主体：依次判断子串，并输出

**使用**：

​	python3 tokens.py

​	输入字符串

**实例(aaab)**：

​	nfa('aaab')		0-1-2-2-2-x

​					0-1-2-2-x

​					0-1-2-x

​					0-1-x

​					0-x

​	nfa('aaa')		0-1-2-2-2

​	nfa('b')			0-3-4

