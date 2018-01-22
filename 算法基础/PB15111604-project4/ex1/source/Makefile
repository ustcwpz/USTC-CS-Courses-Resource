all: scc
	java SCC 

gen: GenerateGraphs.java SCC.java
	javac GenerateGraphs.java 
	java GenerateGraphs

scc: SCC.java
	javac SCC.java

.SILENT:
help:
	echo 'make                - 只生成SCC.class并且运行'
	echo 'make scc            - 同上'
	echo 'make gen            - 生成随机图存到input中'
	echo 'make clean          - 删除*.class'
	echo 'make help           - 打印以上信息'

clean:
	rm -rf *.class

