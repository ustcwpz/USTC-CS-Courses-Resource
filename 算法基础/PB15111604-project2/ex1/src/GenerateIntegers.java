/*************************************************************************
 > File Name: GenerateIntegers.java
 > Author: King.Zevin
 > Mail: jzw0222@mail.ustc.edu.cn
 ************************************************************************/

import java.io.*;

public class GenerateIntegers {
    public static void main(String[] args) throws IOException{
        PrintWriter outString;
        if(DynamicProgramming.CHECKMODE)
            outString= new PrintWriter("../input/input.txt", "utf-8");
        else{
            outString= new PrintWriter("D:/USTC/algorithm/PB15111604-project2/ex1/input/input.txt", "utf-8");
        }
        for (int i = 0; i < 31; i++){
            // 范围为1-32767.
            int r = (int)(Math.random() * 32767 + 1);
            outString.println(r);
            outString.flush();
        }
    }
}
