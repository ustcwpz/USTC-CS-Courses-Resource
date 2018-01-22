
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
    private static boolean ifIntelliJ = true;
    public static boolean CHECKMODE = Johnson.CHECKMODE;
    private static final String ABSPATH = "G:/PB15111604-project4/ex2/";
    private static final int[] sizes = {1,2,3,4,5,6};
    private static int nlogn;

    private static int[] originalInts ;
    private static testGraph G, GT;

    private static Scanner inputIntegers;

    // 测试是否连通图,
    //   如果是,返回0,
    //   如果不是,返回对应的size
    public static int test()throws IOException{
        if(CHECKMODE == true)
            ifIntelliJ = false;
        // 迭代处理
        for(int size : sizes){
            // 初始化
            init(size);
            process(size);

            if(GT.forest.size() > 1)
                return size;
        }
        return 0; // 0 - 表示连通图
    }

    // 初始化
    private static void init(int size)throws IOException{
        nlogn = (1<<(size+2))*(size+2);
        G = new testGraph(1<<(size+2));
        if(!ifIntelliJ){
            inputIntegers = new Scanner(Paths.get("../size" + size + "/input/input.txt"), "utf-8");
            input(nlogn);
        }
        else {
            inputIntegers = new Scanner(Paths.get(ABSPATH + "size" + size + "/input/input.txt"), "utf-8");
            input(nlogn);
        }
        // 处理原始图G
        for(int i = 0; i < 3*nlogn; i+=3){
            G.addEdge(originalInts[i], originalInts[i+1]);
        }
    }

    // 输入
    public static void input(int n)throws IOException{
        originalInts  = new int[3*n];
        for(int i = 0; i < 3*n; i++){
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
    public static testGraph getGT(testGraph G){
        // O(E)
        testGraph GT = new testGraph(G);
        for(int i= 0; i < G.n; i++){
            for(testGraph.Node v: G.vertices[i].Adj){
                GT.addEdge(v.key, i);
            }
        }
        return GT;
    }
}

class testGraph{
    public Node[] vertices;      // 邻接表
    public int n;                // 顶点数
    public int[] f;              // finish数组,方便最后不用排序,直接按降序遍历
    private int time;            // 全局time
    enum COLOR{WHITE, GREY, BLACK};
    public ArrayList<ArrayList<Node>> forest;

    public testGraph(testGraph g){
        this.n = g.n;
        this.vertices = new Node[g.n];
        for(int i = 0; i < g.n; i++){
            vertices[i] = new Node(i);
        }
        this.f = g.f.clone();
        this.forest = g.forest;
    }

    public testGraph(int n){
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
        nodeY.Adj.add(nodeX);
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
        int key;
        public COLOR color;
        public int f;
        public Node parent;
        public ArrayList<Node> Adj;

        public Node(int key){
            this.key = key;
            this.Adj = new ArrayList<>();
        }
    }

}