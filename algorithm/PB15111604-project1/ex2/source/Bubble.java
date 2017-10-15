/*************************************************************************
	> File Name: Bubble.java
	> Author: King.Zevin
	> Student Number: PB15111604
	> Mail: jzw0222@mail.ustc.edu.cn
    > QQ: 1033329461

 ************************************************************************/

import java.util.*;
import java.nio.file.*;
import java.io.*;

public class Bubble{

    public static void main(String[] args) throws IOException{
        /* 初始化:读入所有数据到origin数组中.*/
        Scanner in = new Scanner(Paths.get("../input/input_integers.txt"), "UTF-8");
        PrintWriter outTime = new PrintWriter("../output/bubble_sort/time.txt", "UTF-8");
        int[] origin=new int[1<<17];
        for(int i = 0; i < 1<<17; i++){
            origin[i] = in.nextInt();
        }

        int[] exp={2, 5, 8, 11, 14, 17};
        // 开始调用函数进行排序.
        for(int index : exp){
            int[] partArray = Arrays.copyOf(origin, 1<<index);
            
            // 取微秒级，因为发现纳秒后三位都是0.
            long enduration = sort(partArray)/1000;
            
            // 输出时间到time.txt，注意flush().
            outTime.println("index: " + index + "\ntime: " + enduration + "\tmicroseconds.");
            outTime.flush();

            // 输出排好序的数组到result中
            System.out.println("index: " + index + "\ntime: " + enduration + "\tmicroseconds.");
            PrintWriter outSort = new PrintWriter("../output/bubble_sort/result_"+index+".txt", "UTF-8");
            for(int j = 0; j < 1<<index; j++){
                outSort.println(partArray[j]);
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
        bubble_sort(A);

        // 结束计时，返回时间差。
        long endTime = System.nanoTime();
        return endTime - startTime;
    }

    public static void bubble_sort(int[] A){
        int tmp;
        int l = A.length;
        for(int i = 0; i < l - 1; i++){
            for(int j = 1; j < l; j++){
                if(A[j - 1] > A[j]){
                    // 交换A[j], A[j - 1]
                    tmp = A[j];
                    A[j] = A[j - 1];
                    A[j - 1] = tmp;
                }
            }
        }
    }
}

