/*************************************************************************
	> File Name: Insert.java
	> Author: King.Zevin
	> Student Number: PB15111604
	> Mail: jzw0222@mail.ustc.edu.cn
    > QQ: 1033329461

 ************************************************************************/

import java.util.*;
import java.nio.file.*;
import java.io.*;

public class Insert{
    public static void main(String[] args) throws IOException{
        /* 初始化:读入所有数据到origin数组中.*/
        Scanner in = new Scanner(Paths.get("../input/input_strings.txt"), "UTF-8");
        PrintWriter outTime = new PrintWriter("../output/insert_sort/time.txt", "UTF-8");
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
            PrintWriter outSort = new PrintWriter("../output/insert_sort/result_"+index+".txt", "UTF-8");
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
        // 初始化        
        int l = A.length;
        int min;
        String tmp; 

        for(int i = 0; i < l - 1; i++){
            min = i;
            for(int j = i+1 ; j < l; j++){
                if(compare(A[min], A[j]) > 0){
                    min = j;
                }
            }
            // 交换
            tmp = A[min];
            A[min] = A[i];
            A[i] = tmp;
        }

        // 结束计时，返回时间差。
        long endTime = System.nanoTime();
        return endTime - startTime;
    }
}

