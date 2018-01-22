/*************************************************************************
	> File Name: Quick.java
	> Author: King.Zevin
	> Student Number: PB15111604
	> Mail: jzw0222@mail.ustc.edu.cn
    > QQ: 1033329461

 ************************************************************************/

import java.util.*;
import java.nio.file.*;
import java.io.*;

public class Quick{

    public static void main(String[] args) throws IOException{
        /* 初始化:读入所有数据到origin数组中.*/
        Scanner in = new Scanner(Paths.get("../input/input_strings.txt"), "UTF-8");
        PrintWriter outTime = new PrintWriter("../output/quick_sort/time.txt", "UTF-8");
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
            PrintWriter outSort = new PrintWriter("../output/quick_sort/result_"+index+".txt", "UTF-8");
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
        quick_sort(A, 0, A.length - 1);

        // 结束计时，返回时间差。
        long endTime = System.nanoTime();
        return endTime - startTime;
    }

    // partition
    public static int partition(String[] A, int p, int r){
        String x = A[r];
        String tmp;
        int i = p - 1;
        for(int j = p; j < r; j++){
            if(compare(A[j], x) <= 0){
                i++;
                // exchange A[i], A[j]
                // 确保A[i]是小于等于x的.
                tmp = A[j];
                A[j] = A[i];
                A[i] = tmp;
            }
        }
        i++;
        A[r] = A[i];
        A[i] = x;
        return i;
    }

    public static void quick_sort(String[] A, int p, int r){
        if(p < r){
            int q = partition(A, p, r);
            quick_sort(A, p, q-1);
            quick_sort(A, q+1, r);
        }
    }
}

