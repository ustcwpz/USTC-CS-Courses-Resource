/*************************************************************************
 > File Name: GenerateDoubles.java
 > Author: King.Zevin
 > Mail: jzw0222@mail.ustc.edu.cn
 ************************************************************************/

import java.io.*;

public class GenerateDoubles {
    public static void main(String[] args) throws IOException {
        PrintWriter outString;
        if(PolynomialMultiplication.CHECKMODE)
            outString = new PrintWriter("../input/input.txt", "utf-8");
        else
            outString = new PrintWriter("D:/USTC/algorithm/PB15111604-project2/ex2/input/input.txt", "utf-8");
        for (int i = 0; i < PolynomialMultiplication.MAX; i++){
            // 范围为1-32767.
            double r = Math.random() * 32767 + 1;
            outString.println(r);
            outString.flush();
        }
    }
}
