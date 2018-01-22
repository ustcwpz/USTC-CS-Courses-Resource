all: johnson
	java Johnson

gen: GenerateGraphs.java SCC.java
	javac *.java
	java GenerateGraphs

johnson: Johnson.java
	javac Johnson.java

.SILENT:
help:
	echo 'make                - 只生成Johnson.class并且运行'
	echo 'make johnson        - 同上'
	echo 'make gen            - 生成随机图存到input中,确保连通且无重边'
	echo 'make clean          - 删除*.class'
	echo 'make help           - 打印以上信息'

clean:
	rm -rf *.class
