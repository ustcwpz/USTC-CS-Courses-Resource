all: RedBlack
	java RedBlack 

gen: GenerateIntegers.java
	javac GenerateIntegers.java

RedBlack: RedBlack.java
	javac RedBlack.java

check:
	javac RedBlack.java
	java RedBlack check

.SILENT:
help:
	echo 'make                - 只生成class并且运行ex1,ex2相关代码'
	echo 'make RedBlack       - 只生成class并且运行ex1,ex2相关代码'
	echo 'make RedBlack check - 每次insert,delete都会输出红黑树'
	echo 'make gen            - 生成随机数存到input中'
	echo 'make clean          - 删除*.class'
	echo 'make help           - 打印以上信息'
clean:
	rm -rf *.class

