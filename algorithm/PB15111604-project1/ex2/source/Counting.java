/*************************************************************************
	> File Name: Counting.java
	> Author: King.Zevin
	> Student Number: PB15111604
	> Mail: jzw0222@mail.ustc.edu.cn
    > QQ: 1033329461

 ************************************************************************/

import java.util.*;
import java.nio.file.*;
import java.io.*;

public class Counting{

    // 由于计数排序不是就地排序，
    // 所以需要在函数外,单独设置
    // 一个用于存储排好序的数组的B。
    public static int[] B;
    // public static long t;
    public static void main(String[] args) throws IOException{
        /* 初始化:读入所有数据到origin数组中.*/
        Scanner in = new Scanner(Paths.get("../input/input_integers.txt"), "UTF-8");
        PrintWriter outTime = new PrintWriter("../output/counting_sort/time.txt", "UTF-8");
        int[] origin=new int[1<<23];
        for(int i = 0; i < 1<<23; i++){
            origin[i] = in.nextInt();
        }

        // int[] exp={17, 14, 11, 8, 5, 2};
        int[] exp={2, 5, 8, 11, 14, 17/*, 18, 19, 20, 21, 22, 23*/};
        // int[] exp={2};
        // 开始调用函数进行排序.
        for(int index : exp){
            int[] partArray = Arrays.copyOf(origin, 1<<index);
            
            // 取微秒级，因为发现纳秒后三位都是0.
            long enduration = sort(partArray)/1000;
            partArray = B;

            // 输出时间到time.txt，注意flush().
            outTime.println("index: " + index + "\ntime: " + enduration + "\tmicroseconds.");
            outTime.flush();

            // 输出排好序的数组到result中
            System.out.println("index: " + index + "\ntime: " + enduration + "\tmicroseconds.\n");
            // System.out.println("t   : " + (enduration-t) + "\tmicroseconds.\n");
            PrintWriter outSort = new PrintWriter("../output/counting_sort/result_"+index+".txt", "UTF-8");
            for(int j = 0; j < 1<<index; j++){
                outSort.printf("%8x\n", partArray[j]);
                // outSort.println(partArray[j]);
                outSort.flush();
            }
        }
    }
    
    // 排序函数，返回纳秒数，便于计时。
    public static long sort(int[] A){
        // 开始计时
        long startTime = System.nanoTime();
        // 排序
        // 算法之间主要只有这里不同。
        // for(int i = 0; i < 10000; i++)
            counting_sort(A);

        // 结束计时，返回时间差。
        long endTime = System.nanoTime();
        return endTime - startTime;
    }

    public static void counting_sort(int[] A){
        long s;
        long e;
        s = System.nanoTime();
        
        int tmp;
        int l = A.length;
        B = new int[l];
        int[] C = new int[65535];
        e = System.nanoTime();
        System.out.println("init:81 " + (e-s)/1000 + "\tmicroseconds.");
        // t = (e-s)/1000;

        s = System.nanoTime();
        for(int i = 0; i < l; i++){
            C[A[i]-1]++;
        }
        // C[i] 的值即为大小为i-1的值的个数
        e = System.nanoTime();
        System.out.println("init:90 " + (e-s)/1000 + "\tmicroseconds.");       

        s = System.nanoTime();
        for(int i = 1; i < 65535; i++){
            C[i] += C[i-1];
        }
        // C[i] 的值即为大小为小于等于i-1的值的个数
        e = System.nanoTime();
        System.out.println("init:65535 " + (e-s)/1000 + "\tmicroseconds.");       
        // t += (e-s)/1000;

        s = System.nanoTime();
        for(int i = l-1; i >= 0; i--){
            B[C[A[i]-1]-1] = A[i];
            C[A[i]-1] --;
        }
        e = System.nanoTime();
        System.out.println("[][][] " + (e-s)/1000 + "\tmicroseconds.");
    }
}

