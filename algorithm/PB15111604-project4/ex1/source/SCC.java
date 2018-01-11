
/*************************************************************************
 > File Name: SCC.java
 > Author: King.Zevin
 > Mail: jzw0222@mail.ustc.edu.cn
 ************************************************************************/

import java.io.*;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.Scanner;


public class SCC {
    public static boolean CHECKMODE = true;
    private static boolean ifIntelliJ = true;
    private static final String ABSPATH = "G:/PB15111604-project4/ex1/";
    private static final int[] sizes = {1,2,3,4,5,6};
    private static int nlogn;

    private static int[] originalInts ;
    private static Graph G, GT;

    private static PrintWriter printTime;
    private static PrintWriter printOutcome;
    private static PrintWriter printDot;
    private static Scanner inputIntegers;

    public static void main(String[] args)throws IOException{
        if(args.length!=0) {
            CHECKMODE = true;
        }
        if(CHECKMODE == true)
            ifIntelliJ = false;
        // 迭代处理
        for(int size : sizes){
            // 初始化
            init(size);
            long start, end;
            // 开始计时

            start = System.nanoTime();

            process(size);

            // 结束计时
            end = System.nanoTime();

            printOutput(size);
            printTime.printf("%9d nanoseconds.\n", end -
                    start);
            printTime.flush();
            System.out.printf("%9d nanoseconds.\n", end -
                    start);
        }
    }

    // 初始化
    private static void init(int size)throws IOException{
        nlogn = (1<<(size+2))*(size+2);
        G = new Graph(1<<(size+2));
        if(!ifIntelliJ){
            inputIntegers = new Scanner(Paths.get("../size" + size + "/input/input.txt"), "utf-8");
            input(nlogn);
            printTime = new PrintWriter("../size" + size + "/output/time1.txt", "utf-8");
            printOutcome = new PrintWriter("../size" + size + "/output/output1.txt", "utf-8");
            printDot = new PrintWriter("../size" + size + "/output/output1.dot", "utf-8");
        }
        else {
            inputIntegers = new Scanner(Paths.get(ABSPATH + "size" + size + "/input/input.txt"), "utf-8");
            input(nlogn);
            printTime = new PrintWriter(ABSPATH + "size" + size + "/output/time1.txt", "utf-8");
            printOutcome = new PrintWriter(ABSPATH + "size" + size + "/output/output1.txt", "utf-8");
            printDot = new PrintWriter(ABSPATH + "size" + size + "/output/output1.dot", "utf-8");
        }
        // 处理原始图G
        for(int i = 0; i < 2*nlogn; i+=2){
            G.addEdge(originalInts[i], originalInts[i+1]);
        }
    }

    // 输入
    public static void input(int n)throws IOException{
        originalInts  = new int[2*n];
        for(int i = 0; i < 2*n; i++){
            originalInts[i] = inputIntegers.nextInt();
        }
    }

    // 针对每个size进行处理的主力函数.
    public static void process(int size){
        G.dfs();
        GT = getGT(G);
        GT.dfs(G.f);
    }

    // 生成图G的转置GT
    public static Graph getGT(Graph G){
        // O(E)
        Graph GT = new Graph(G);
        for(int i= 0; i < G.n; i++){
            for(Graph.Node v: G.vertices[i].Adj){
                GT.addEdge(v.key, i);
            }
        }
        return GT;
    }

    // 生成dot再生成svg.
    private static void printOutput(int size)throws  IOException{
        String[] colors = {"red", "black", "orange", "yellow", "green", "blue", "purple", "grey", "white"};
        int i = 0;
        // dot : digraph
        printDot.printf("digraph {\n");
        printDot.flush();
        for(ArrayList<Graph.Node> tree: GT.forest){
            printOutcome.printf("("); printOutcome.flush();
//            System.out.printf("(");
            String color = colors[i++];
            for(Graph.Node node: tree){
                printOutcome.printf("%5d", node.key);
                printOutcome.flush();
//                System.out.printf("%5d", node.key);
                // dot : color
                printDot.printf("    %d [style=filled color=\"%s\"];\n", node.key, color); printDot.flush();
            }
            printOutcome.printf(")\n"); printOutcome.flush();
//            System.out.printf(")\n");
        }
        // dot : edge
        int n = originalInts.length;
        for(i = 0; i < n; i+=2){
            printDot.printf( "    %d -> %d;\n", originalInts[i], originalInts[i+1] ); printDot.flush();
        }
        printDot.printf("}"); printDot.flush();
        // 对于size>4,生成svg要很久,所以这个可以当做选择项,如果要生成,请去掉if
        if(size < 5)
            Runtime.getRuntime().exec("dot -Tsvg ../size" + size + "/output/output1.dot -o ../size" + size +
                "/output/output1.svg");
    }
}

// 图类
class Graph{
    public Node[] vertices;                     // 邻接表
    public int n;                               // 顶点数
    public int[] f;                             // finish数组,方便最后不用排序,直接按降序遍历
    private int time;                           // 全局time
    enum COLOR{WHITE, GREY, BLACK};
    public ArrayList<ArrayList<Node>> forest;

    // 生成图g的copy
    public Graph(Graph g){
        this.n = g.n;
        this.vertices = new Node[g.n];
        for(int i = 0; i < g.n; i++){
            vertices[i] = new Node(i);
        }
        this.f = g.f.clone();
        this.forest = g.forest;
    }

    // 生成n个节点的图
    public Graph(int n){
        this.vertices = new Node[n];
        for(int i = 0; i < n; i++){
            vertices[i] = new Node(i);
        }
        this.n = n;
        this.f = new int[n];
        this.forest = new ArrayList<>();
    }

    // 添加边
    public void addEdge(int x, int y){
        Node nodeX = vertices[x];
        Node nodeY = vertices[y];
        nodeX.Adj.add(nodeY);
    }

    // G的深度优先
    public void dfs(){
        for(Node node : vertices){
            node.color = COLOR.WHITE;
            node.parent = null;
        }
        time = 0;
        for(Node node: vertices){
            if(node.color == COLOR.WHITE)
                dfsVist(node);
        }
    }

    // GT的深度优先-按照finish数组的逆序遍历
    public void dfs(int[] finish){
        int n = finish.length;
        for(Node node:vertices){
            node.color = COLOR.WHITE;
            node.parent = null;
        }
        time = 0;
        for(int i = n-1; i >= 0; i--){
            Node node = vertices[f[i]];
            if(node.color == COLOR.WHITE) {
                ArrayList<Node> scc = new ArrayList<>();
                dfsVist(node, scc);
                forest.add(scc);
            }
        }
    }

    // G的深度优先递归部分
    private void dfsVist(Node u){
        u.color = COLOR.GREY;
        for(Node v : u.Adj){
            if(v.color == COLOR.WHITE){
                v.parent = u;
                dfsVist(v);
            }
        }
        u.color = COLOR.BLACK;
        u.f = time;
        f[time] = u.key;
        time ++;
    }

    // GT的深度优先递归部分,将访问到的节点添加到scc连通分量里.
    private void dfsVist(Node u, ArrayList<Node> scc){
        u.color = COLOR.GREY;
        scc.add(u);
        for(Node v : u.Adj){
            if(v.color == COLOR.WHITE){
                v.parent = u;
                dfsVist(v, scc);
            }
        }
        u.color = COLOR.BLACK;
    }

    // 节点类
    public class Node{
        int key;                            // 图中index
        public COLOR color;                 // 颜色,白灰黑
        public int f;                       // 表示finish的时间
        public Node parent;                 // parent
        public ArrayList<Node> Adj;         // 邻接表的链表

        public Node(int key){
            this.key = key;
            this.Adj = new ArrayList<>();
        }
    }
}


