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
        // 初始化:读入所有数据到origin数组中.
        Scanner in = new Scanner(Paths.get("../input/input_strings.txt"), "UTF-8");
        String[] origin=new String[1<<17];
        for(int i = 0; i < 1<<17; i++){
            origin[i]=in.nextLine();
        }

        // 开始调用函数进行排序.
        // 2^2

        // 2^5
        
        // 2^8
        
        // 2^11
        
        // 2^14
        
        // 2^17
        
        System.out.println(origin[(1<<17) - 1]);
    }
    
    // 排序函数，返回纳秒数，便于计时。
    public static double sort(String[] A){

    }
}

