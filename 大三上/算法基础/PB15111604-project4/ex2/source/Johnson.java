
/*************************************************************************
 > File Name: Johnson.java
 > Author: King.Zevin
 > Mail: jzw0222@mail.ustc.edu.cn
 ************************************************************************/

import jdk.nashorn.internal.ir.VarNode;

import java.io.*;
import java.lang.reflect.Array;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.Scanner;


public class Johnson {
    public static boolean CHECKMODE = true;
    private static boolean ifIntelliJ = true;
    private static final String ABSPATH = "G:/PB15111604-project3/ex2/";
    private static final int[] sizes = {1,2,3,4,5,6};
    private static int nlogn;
    public static final int MAX_NUM = 10000000;

    private static int[] originalInts ;
    private static Graph G;
    private static long start, endurance;

    private static PrintWriter printTime;
    private static PrintWriter printOutcome;
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

            // 开始计时
            endurance = 0;
            start = System.nanoTime();

            process(size);

            // 结束计时
            endurance += System.nanoTime() - start;

            printTime.printf("%9d nanoseconds.\n", endurance);
            printTime.flush();
            System.out.printf("%9d nanoseconds.\n", endurance);
        }
    }

    // 初始化
    private static void init(int size)throws IOException{
        nlogn = (1<<(size+2))*(size+2);
        G = new Graph(1<<(size+2));
        if(!ifIntelliJ){
            inputIntegers = new Scanner(Paths.get("../size" + size + "/input/input.txt"), "utf-8");
            input(nlogn);
            printTime = new PrintWriter("../size" + size + "/output/time2.txt", "utf-8");
            printOutcome = new PrintWriter("../size" + size + "/output/output2.txt", "utf-8");
        }
        else {
            inputIntegers = new Scanner(Paths.get(ABSPATH + "size" + size + "/input/input.txt"), "utf-8");
            input(nlogn);
            printTime = new PrintWriter(ABSPATH + "size" + size + "/output/time2.txt", "utf-8");
            printOutcome = new PrintWriter(ABSPATH + "size" + size + "/output/output2.txt", "utf-8");
        }
        // 处理原始图G
        for(int i = 0; i < 3*nlogn; i+=3){
            G.addEdge(originalInts[i], originalInts[i+1], originalInts[i+2]);
        }
    }

    // 输入
    public static void input(int n){
        originalInts  = new int[3*n];
        for(int i = 0; i < 3*n; i++){
            originalInts[i] = inputIntegers.nextInt();
        }
    }

    // 输出最短路径
    private static void printOutput(String path)throws  IOException{
        printOutcome.println(path);
        printOutcome.flush();
    }

    // 针对每个size进行处理的主力函数.
    public static void process(int size)throws IOException{
        for(int i = 0; i < G.n; i ++){
            dijkstra(i);
            String path;
            for(int j = 0; j < G.n; j++){
                path = i + "->" + j + " (";
                path = path + shortestPath(j);
                path = path + ")" + " length: " + G.vertices[j].d;
                endurance += System.nanoTime() - start;
                printOutput(path);
//                System.out.println(path);
                start = System.nanoTime();
            }
        }
    }

    // 初始化源节点,同教材
    private static void initializeSingleSource(int s){
        int n = G.n;
        for(int i = 0; i < n; i++){
            G.vertices[i].d = MAX_NUM;
            G.vertices[i].parent = -1;
        }
        G.vertices[s].d = 0;
    }

    // 松弛操作,同教材
    private static void relax(int u, int v, int w){
        if(G.vertices[v].d > G.vertices[u].d + w){
            G.vertices[v].d = G.vertices[u].d + w;
            G.vertices[v].parent = u;
        }
    }

    // 得到最短路径字符串
    private static String shortestPath(int v){
        if(v == -1)
            return "";
        return shortestPath(G.vertices[v].parent) + " " + v;

    }

    // dijkstra算法, int s 为源节点
    private static void dijkstra(int s){
        int n = G.n;
        Integer u = 0, min;

        ArrayList<Integer> q = new ArrayList<>();
        for(int i = 0; i < n; i++)
            q.add(new Integer(i));

        initializeSingleSource(s);
        while(n > 0){
            // extract-min
            min = MAX_NUM;
            for(Integer i : q)
                if(G.vertices[i].d < min){
                    u = i;
                    min = G.vertices[i].d;
                }
            // u = minimum, min = minimun
            q.remove(u);
            n--;

            for(Graph.ENode v: G.vertices[u].Adj){
                relax(u, v.ivex, v.weight);
            }
        }
    }

}

class Graph{
    public VNode[] vertices;      // 邻接表
    public int n;                // 顶点数

    // 生成n个节点的图
    public Graph(int n){
        this.vertices = new VNode[n];
        for(int i = 0; i < n; i++){
            vertices[i] = new VNode(i);
        }
        this.n = n;
    }

    // 添加边
    public void addEdge(int x, int y, int w){
        VNode nodeX = vertices[x];
        VNode nodeY = vertices[y];
        ENode enodeX = new ENode(x, w);
        ENode enodeY = new ENode(y, w);
        nodeX.Adj.add(enodeY);
        nodeY.Adj.add(enodeX);
    }

    // 邻接表中表对应的链表的顶点
    public class ENode {
        int ivex;       // 该边所指向的顶点的位置
        int weight;     // 该边的权

        public ENode(int key, int w){
            this.ivex = key;
            this.weight = w;
        }
    }

    // 邻接表中表的顶点
    public class VNode {
        int key;            // 顶点信息
        int d;              // 到s的距离
        int parent;
        int degree;         // 出度
        ArrayList<ENode> Adj;

        public VNode(int key){
            this.key = key;
            this.Adj = new ArrayList<>();
        }
    }
}

