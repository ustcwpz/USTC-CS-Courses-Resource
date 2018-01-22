/*************************************************************************
 > File Name: GenerateIntegers.java
 > Author: King.Zevin
 > Mail: jzw0222@mail.ustc.edu.cn
 ************************************************************************/

import java.io.*;
import java.util.*;

public class GenerateIntegers {

    public static void main(String[] args) throws IOException{
        PrintWriter outString;
        if(RedBlack.CHECKMODE)
            outString= new PrintWriter("../input/input.txt", "utf-8");
        else{
            outString= new PrintWriter("G:/PB15111604-project3/ex1/input/input.txt", "utf-8");
        }
//        List<int> list = new List<int>(N);
        ArrayDeque<Integer> list = new ArrayDeque<Integer>();
        while(list.size() < RedBlack.N){
            // 范围为1-32767.
            int r = (int)(Math.random() * 32767 + 1);
            if(!list.contains(r))
                list.add(r);
        }
        for (int i: list ) {
            outString.println(i);
            outString.flush();
        }
    }
}
