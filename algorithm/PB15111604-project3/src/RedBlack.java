/*************************************************************************
 > File Name: RedBlack.java
 > Author: King.Zevin
 > Mail: jzw0222@mail.ustc.edu.cn
 ************************************************************************/

import java.io.*;
import java.nio.file.Paths;
import java.util.Arrays;
import java.util.Scanner;

public class RedBlack {

    private static boolean ifIntelliJ = false;
    public static boolean CHECKMODE = false;
    public static final int N = 100;
    private static final String ABSPATH = "G:/PB15111604-project3/";

    private static RBTree tree;
    private static int[] originalInts ;

    private static PrintWriter printPreOrder;
    private static PrintWriter printInOrder;
    private static PrintWriter printPostOrder;
    private static PrintWriter printTime1;
    private static PrintWriter printTime2;
    private static PrintWriter printDelete;
    private static Scanner inputIntegers;

    public static void main(String[] args)throws IOException{
        if(args.length!=0) {
            CHECKMODE = true;
        }
        if(CHECKMODE == true)
            ifIntelliJ = false;
         int[] tasks = {100, 60, 48, 36, 24, 12};
//       int[] tasks = {6, 12};
//        int[] tasks = {12};
        // 迭代处理
        for(int task : tasks){
            // 初始化
            init(task);
            int[] tmpArray = Arrays.copyOf(originalInts , task);

            process(tmpArray);
        }
    }

    private static void init(int size)throws IOException{
        if(!ifIntelliJ){
            inputIntegers = new Scanner(Paths.get("../input/input.txt"), "utf-8");
            input();
            printPreOrder = new PrintWriter("../output/size" + size + "/preorder.txt", "utf-8");
            printInOrder = new PrintWriter("../output/size" + size + "/inorder.txt", "utf-8");
            printPostOrder = new PrintWriter("../output/size" + size + "/postorder.txt", "utf-8");
            printTime1 = new PrintWriter("../output/size" + size + "/time1.txt", "utf-8");
            printTime2 = new PrintWriter("../output/size" + size + "/time2.txt", "utf-8");
            printDelete = new PrintWriter("../output/size" + size + "/delete_data.txt", "utf-8");
        }
        else {
            inputIntegers = new Scanner(Paths.get(ABSPATH + "input/input.txt"), "utf-8");
            input();
            printPreOrder = new PrintWriter(ABSPATH + "output/size" + size + "/preorder.txt", "utf-8");
            printInOrder = new PrintWriter(ABSPATH + "output/size" + size + "/inorder.txt", "utf-8");
            printPostOrder = new PrintWriter(ABSPATH + "output/size" + size + "/postorder.txt", "utf-8");
            printTime1 = new PrintWriter(ABSPATH + "output/size" + size + "/time1.txt", "utf-8");
            printTime2 = new PrintWriter(ABSPATH + "output/size" + size + "/time2.txt", "utf-8");
            printDelete = new PrintWriter(ABSPATH + "output/size" + size + "/delete_data.txt", "utf-8");
        }
    }

    // 输入
    public static void input()throws IOException{
        originalInts  = new int[N];
        for(int i = 0; i < N; i++){
            originalInts[i] = inputIntegers.nextInt();
        }
    }

    // 针对每个size进行处理的主力函数.
    public static void process(int[] array){
        long start, end, tenStart = 0, tenEnd;
        int n = array.length, j = 0;
        long[] tenArray = new long[n/10];
        // 开始计时
        start = System.nanoTime();

        // 初始化树
        tree = new RBTree();
        for(int i = 0; i < n; i++) {
            if (i % 10 == 0)
                // 十个记一次
                tenStart = System.nanoTime();
            // 插入i
            tree.insert(array[i]);
            check();
            if ((i + 1) % 10 == 0) {
                tenEnd = System.nanoTime();
                tenArray[j++] = tenEnd - tenStart;
            }
        }
        // 结束计时
        end = System.nanoTime();

        for(int i = 0; i < tenArray.length; i++){
            printTime1.printf("%2d - %2d slice:  %9d nanoseconds.\n", 10*i+1, 10*(i+1), tenArray[i]);
            printTime1.flush();
        }

        printTime1.printf("Total building: %9d nanoseconds.\n", end -
                start);
        printTime1.flush();

        // 遍历输出
        tree.printPreOrder(printPreOrder);
        tree.printInOrder(printInOrder);
        tree.printPostOrder(printPostOrder);

        // 删除节点
        int[] tmpDelete = {3,4};
        for(int i : tmpDelete){
            start = System.nanoTime();
            RBNode node = tree.osSlect(tree.root, n/i);
            tree.delete(node);
            end = System.nanoTime();

            check();
            printTime2.printf("Time to delete node %d/%d: %9d nanoseconds.\n", n, i, end - start);
            printTime2.flush();
            printDelete.printf("key:%5d, color:%s, size:%2d\n", node.key, (node.color == tree.RED ? "red  ":"black"), node
                    .size);
            printDelete.flush();

            // 通过select(a,p,r,i)检查是否删除正确.
            int s = select(array, 0, array.length-1, n/i);
            System.out.printf("%d/%d:\n", n, i);
            System.out.printf("    Selected from the input data by select(a, p, r, i): %d\n", s);
            System.out.printf("    Deleted from the RedBlack tree with osSelect:       %d\n", node.key);
            n--;
        }
    }

    // select(a, p, r, i)
    private static int select(int[] a, int p, int r, int i){
        if(p == r)
            return a[p];
        int q = parition(a, p, r);
        int k = q - p + 1;
        if (i ==k){
            return a[q];
        }
        else if (i < k)
            return select(a, p, q-1, i);
        else
            return select(a, q+1, r, i-k);
    }

    // 快排对应的partition函数
    private static int parition(int[] a, int p, int r){
        int x = a[r];
        int i = p-1;
        int tmp;
        for(int j = p; j <= r-1; j++) {
            if (a[j] <= x){
                i++;
                tmp = a[i];
                a[i] = a[j];
                a[j] = tmp;
            }
        }
        tmp = a[i+1];
        a[i+1] = a[r];
        a[r] = tmp;
        return i+1;
    }

    private static void check(){
        if(CHECKMODE == false)
            return;
        System.out.println();
        print(tree.root, 0);
    }

    private static void print(RBNode node, int depth){
        if(node == tree.NIL)
            return;
        System.out.print("|");
        for(int i = 0; i < depth; i ++)
            System.out.print("__");
        System.out.printf("_key:%5d, color:%s, size:%2d\n", node.key, (node.color == tree.RED ? "red  ":"black"),
                node.size);
        print(node.left, depth+1);
        print(node.right, depth+1);

    }

}


class RBTree{
    public RBNode root;                         // 根节点
    public RBNode NIL;                          // NIL节点

    public static final boolean RED    = false;
    public static final boolean BLACK  = true;

    // 构造函数
    // 初始化root,NIL
    public RBTree(){
        NIL = new RBNode(0, BLACK, 0, null, null, null);
        NIL.parent = NIL;
        NIL.left = NIL;
        NIL.right = NIL;
        root = NIL;
    }

    // 左旋,以x为开始的子树父节点
    private void leftRotate(RBNode x){
        // y是x的右孩子
        RBNode y = x.right;

        // y的左孩子给x当右孩子
        x.right = y.left;

        // 如果y有左孩子,新爸爸是x
        if(y.left != NIL)
            y.left.parent = x;

        y.parent = x.parent;

        if(x.parent == NIL)
            root = y;              // 如果x是根,y成为根
        else{
            if(x.parent.left == x)      // 如果x是左孩子
                x.parent.left = y;      // y成为左孩子
            else
                x.parent.right = y;     // 否则,y是右孩子
        }

        y.left = x;
        x.parent = y;
        y.size = x.size;
        x.size = 1;
        x.size += x.left == NIL ? 0:x.left.size;
        x.size += x.right == NIL ? 0:x.right.size;
    }

    // 右旋,以y为开始的子树父节点
    private void rightRotate(RBNode y){
        // x是y的左孩子
        RBNode x = y.left;

        // x的右孩子给y当左孩子
        y.left = x.right;

        // 如果x有右孩子,新爸爸是y
        if(x.right != NIL)
            x.right.parent = y;

        x.parent = y.parent;

        if(y.parent == NIL)
            // 如果x是根,y成为根
            root = x;
        else{
            if(y.parent.right == y)      // 如果y是右孩子
                y.parent.right = x;     // x成为右孩子
            else
                y.parent.left = x;      // 否则,x是左孩子
        }

        x.right = y;
        y.parent = x;
        x.size = y.size;
        y.size = 1;
        y.size += y.left == NIL ? 0:y.left.size;
        y.size += y.right == NIL ? 0:y.right.size;
    }

    // API - 插入大小为key的node
    public void insert(int key) {
        RBNode node = new RBNode(key, RED, 1,null,null,null);
        node.parent = NIL;
        node.left = NIL;
        node.right = NIL;
        insert(node);
    }

    // 插入一个node,内部调用
    private void insert(RBNode node){
        RBNode y = NIL;
        RBNode x = root;

        int key = node.key;
        while(x != NIL){
            y = x;
            y.size++;
            if(key < x.key)
                x = x.left;
            else
                x = x.right;
        }

        node.parent = y;
        if(y != NIL){
            // 如果y不是根
            if(key < y.key)
                y.left = node;
            else
                y.right = node;
        }
        else
            // 如果是,那node就是根
            root = node;

        insertFixUp(node);
        // 修正
    }

    // insert函数调整颜色的的fixup
    private void insertFixUp(RBNode node){
        RBNode parent, gparent, uncle;

        while((parent = node.parent) != NIL && parent.color == RED){
            // parent是红色
            gparent = parent.parent;

            if(parent == gparent.left){
                // 如果parent是左孩子
                uncle = gparent.right;

                if(uncle != NIL && uncle.color == RED){
                    // uncle是红色,进入case1
                    parent.color = BLACK;       // case1
                    uncle.color = BLACK;        // case1
                    gparent.color = RED;        // case1
                    node = gparent;             // case1
                    continue;
                }
                else if(node == parent.right){
                    // uncle是黑色,node是右孩子,进入case2
                    leftRotate(parent);
                    node = parent;
                    parent = node.parent;
                }
                // uncle是黑色,node是左孩子,进入case3
                parent.color = BLACK;           // case3
                gparent.color = RED;            // case3
                rightRotate(gparent);           // case3
            }
            else{
                // 否则parent是右孩子
                uncle = gparent.left;

                if(uncle != NIL && uncle.color == RED){
                    // uncle是红色,进入case1
                    parent.color = BLACK;       // case1
                    uncle.color = BLACK;        // case1
                    gparent.color = RED;        // case1
                    node = gparent;             // case1
                    continue;
                }
                else if(node == parent.left){
                    // uncle是黑色,node是左孩子,进入case2
                    rightRotate(parent);
                    node = parent;
                    parent = node.parent;
                }
                // uncle是黑色,node是右孩子,进入case3
                parent.color = BLACK;           // case3
                gparent.color = RED;            // case3
                leftRotate(gparent);            // case3
            }
        }
        root.color = BLACK;
    }

    // 返回以root节点为根节点的树的最小节点.
    private RBNode minimum(RBNode root){
        if(root == NIL)
            return NIL;
        while(root.left != NIL)
            root = root.left;
        return root;
    }

    // u是要被删除的,用v代替u
    private void Transplant(RBNode u, RBNode v){
        if(u.parent == NIL)
            root = v;
        else if(u == u.parent.left)
            u.parent.left = v;
        else
            u.parent.right = v;
        v.parent = u.parent;
    }

    // API - 删除节点node
    public void delete(RBNode node){
        RBNode y = node;
        RBNode x;
        boolean originalColor = node.color;

        if(node != NIL && node.left == NIL){
            // node最多有一个右孩子
            x = node.right;
            Transplant(node, x);
        }
        else if(node != NIL && node.right == NIL) {
            // node最多有一个左孩子
            x = node.left;
            Transplant(node, x);
        }
        else{
            // node有两个孩子
            y = minimum(node.right);
            // y是node后继,将被换上来.
            originalColor = y.color;
            x = y.right;
            if(y.parent == node)
                x.parent = y;
            else{
                Transplant(y, x);
                y.right = node.right;
                y.right.parent = y;
            }
            Transplant(node, y);
            y.size = node.size;
            y.left = node.left;
            y.left.parent = y;
            y.color = node.color;
        }

        // 调整size
        RBNode tmp = x.parent;
        while(tmp != NIL){
            tmp.size--;
            tmp = tmp.parent;
        }
        // 如果原颜色为黑色,修补
        if (originalColor == BLACK)
            deleteFixUp(x);
    }

    // delete函数调整颜色的fixup
    private void deleteFixUp(RBNode node){
        RBNode sibling, parent = node.parent;
        while (node != root && (node.color == BLACK )){
            if(node == parent.left){
                // node是左孩子
                sibling = parent.right;                     // case1
                if(sibling.color == RED){
                    // 兄弟红色,进入case1
                    sibling.color = BLACK;                  // case1
                    parent.color = RED;                     // case1
                    leftRotate(parent);                     // case1
                    sibling = parent.right;                 // case1
                }
                if(sibling.left.color == BLACK && sibling.right.color == BLACK){
                    // 兄弟黑色,兄弟双子黑色,进入case2
                    sibling.color = RED;                    // case2
                    node = parent;                          // case2
                    parent = parent.parent;                 // case2
                }
                else{
                    if(sibling.right.color == BLACK){
                        // 兄弟黑色,兄弟右孩子黑色,进入case3
                        sibling.left.color = BLACK;         // case3
                        sibling.color = RED;                // case3
                        rightRotate(sibling);               // case3
                        sibling = parent.right;             // case3
                    }
                    // 兄弟红色,兄弟右孩子红色,进入case4
                    sibling.color = parent.color;           // case4
                    parent.color = BLACK;                   // case4
                    sibling.right.color = BLACK;            // case4
                    leftRotate(parent);                     // case4
                    node = root;                            // case4
                }
            }
            else{
                // node是右孩子
                sibling = parent.left;
                if(sibling.color == RED){
                    // 兄弟红色,进入case1
                    sibling.color = BLACK;                  // case1
                    parent.color = RED;                     // case1
                    rightRotate(parent);                    // case1
                    sibling = parent.left;                  // case1
                }
                if(sibling.right.color == BLACK && sibling.left.color == BLACK){
                    // 兄弟黑色,兄弟双子黑色,进入case2
                    sibling.color = RED;                    // case2
                    node = parent;                          // case2
                    parent = parent.parent;                 // case2
                }
                else{
                    if(sibling.left.color == BLACK){
                        // 兄弟黑色,兄弟左孩子黑色,进入case3
                        sibling.right.color = BLACK;        // case3
                        sibling.color = RED;                // case3
                        leftRotate(sibling);                // case3
                        sibling = parent.left;              // case3
                    }
                    // 兄弟红色,兄弟左孩子红色,进入case4
                    sibling.color = parent.color;           // case4
                    parent.color = BLACK;                   // case4
                    sibling.left.color = BLACK;             // case4
                    rightRotate(parent);                    // case4
                    node = root;                            // case4
                }
            }
        }
        node.color = BLACK;
    }

    public RBNode osSlect(RBNode x, int i){
        int r = x.left.size + 1;
        if(i == r)
            return x;
        else if(i < r)
            return osSlect(x.left, i);
        else
            return osSlect(x.right, i - r);
    }

    // API - 先序遍历
    public void printPreOrder(PrintWriter pw){
        printPreOrder(root, pw);
    }

    // 先序遍历
    private void printPreOrder(RBNode node, PrintWriter pw){
        if(node == NIL)
            return;
        pw.printf("key:%5d, color:%s, size:%2d\n", node.key, (node.color == RED ? "red  ":"black"), node.size);
        pw.flush();
        printPreOrder(node.left, pw);
        printPreOrder(node.right, pw);
    }

    // API - 中序遍历
    public void printInOrder(PrintWriter pw){
        printInOrder(root, pw);
    }

    // 中序遍历
    private void printInOrder(RBNode node, PrintWriter pw){
        if(node == NIL)
            return;
        printInOrder(node.left, pw);
        pw.printf("key:%5d, color:%s, size:%2d\n", node.key, (node.color == RED ? "red  ":"black"), node.size);
        pw.flush();
        printInOrder(node.right, pw);
    }

    // API - 后序遍历
    public void printPostOrder(PrintWriter pw){
        printPostOrder(root, pw);
    }

    // 后序遍历
    private void printPostOrder(RBNode node, PrintWriter pw){
        if(node == NIL)
            return;
        printPostOrder(node.left, pw);
        printPostOrder(node.right, pw);
        pw.printf("key:%5d, color:%s, size:%2d\n", node.key, (node.color == RED ? "red  ":"black"), node.size);
        pw.flush();
    }
}

class RBNode{
    int key;
    boolean color;
    int size = 0;
    RBNode left;
    RBNode right;
    RBNode parent;

    // 构造函数
    public RBNode(int KEY, boolean COLOR, int SIZE, RBNode PARENT, RBNode LEFT, RBNode RIGHT){
        key = KEY;
        color = COLOR;
        size = SIZE;
        parent = PARENT;
        left = LEFT;
        right = RIGHT;
    }
}