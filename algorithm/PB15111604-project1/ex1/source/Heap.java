/*************************************************************************
	> File Name: Heap.java
	> Author: King.Zevin
	> Student Number: PB15111604
	> Mail: jzw0222@mail.ustc.edu.cn
    > QQ: 1033329461

 ************************************************************************/

import java.util.*;
import java.nio.file.*;
import java.io.*;

public class Heap{

    // 为了避免单独为了heapSize弄个class，
    // 所以设置为函数外变量
    public static int heapSize = 0;
    
    public static void main(String[] args) throws IOException{
        /* 初始化:读入所有数据到origin数组中.*/
        Scanner in = new Scanner(Paths.get("../input/input_strings.txt"), "UTF-8");
        PrintWriter outTime = new PrintWriter("../output/heap_sort/time.txt", "UTF-8");
        String[] origin=new String[1<<17];
        for(int i = 0; i < 1<<17; i++){
            origin[i] = in.nextLine();
        }

        int[] exp={2, 5, 8, 11, 14, 17};
        
        // 开始调用函数进行排序.
        for(int index : exp){
            String[] partArray = Arrays.copyOf(origin, 1<<index);
            // 取微秒级，因为发现纳秒后三位都是0.
            long enduration = sort(partArray)/1000;
            
            // 输出时间到time.txt，注意flush().
            outTime.println("index: " + index + "\ntime: " + enduration + "\tmicroseconds.");
            outTime.flush();

            // 输出排好序的数组到result中
            System.out.println("index: " + index + "\ntime: " + enduration + "\tmicroseconds.");
            PrintWriter outSort = new PrintWriter("../output/heap_sort/result_"+index+".txt", "UTF-8");
            for(int j = 0; j < 1<<index; j++){
                outSort.println(partArray[j]);
                outSort.flush();
            }

        }
        
    }
    
    // 用于比较字符串大小的函数
    // 小则-1 大则1 相等则0
    public static int compare(String a, String b){
        if(a.length() < b.length())
            return -1;
        else if(a.length() > b.length())
            return 1;
        else
            return a.compareTo(b);
    }

    // 排序函数，返回纳秒数，便于计时。
    public static long sort(String[] A){
        // 开始计时
        long startTime = System.nanoTime();
        // 排序
        // 算法之间主要只有这里不同。
        heap_sort(A);

        // 结束计时，返回时间差。
        long endTime = System.nanoTime();
        return endTime - startTime;
    }

    public static int left(int i){
        return 2 * i + 1;
    }

    public static int right(int i){
        return 2 * i + 2;
    }

    public static int parent(int i){
        return (i + 1) / 2 - 1;
    }

    public static void max_heapify(String[] A, int i){
        int largest = i;
        int l = left(i);
        int r = right(i);
        String tmp;
        if(l < heapSize && compare(A[l], A[i]) > 0)
            largest = l;
        if(r < heapSize && compare(A[r], A[largest]) > 0)
            largest = r;
        if(largest != i){
            tmp = A[largest];
            A[largest] = A[i];
            A[i] = tmp;
            max_heapify(A, largest);
        }
    }

    public static void build_max_heap(String[] A){
        for(int i = A.length / 2 - 1; i >=0; i--){
            max_heapify(A, i);
        }
    }

    public static void heap_sort(String[] A){
        String tmp;

        heapSize = A.length;
        build_max_heap(A);

        for(int i = A.length - 1; i >= 1; i--){
            // 交换A[0],A[i]
            tmp = A[i];
            A[i] = A[0];
            A[0] = tmp;
            heapSize --;
            max_heapify(A, 0);
        }
    }
}

