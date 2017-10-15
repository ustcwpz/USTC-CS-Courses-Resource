/*************************************************************************
	> File Name: GenerateInteger.java
	> Author: King.Zevin
	> Mail: jzw0222@mail.ustc.edu.cn
	> Created Time: Fri Oct 13 18:28:01 2017
 ************************************************************************/

import java.io.*;
import java.util.*;

public class GenerateInteger{
    public static void main(String[] args) throws IOException{
        PrintWriter outInt = new PrintWriter("../input/input_integers.txt", "UTF-8");
        for(int i = 0; i < (1 << 25) ; i++){
            int r = (int)(Math.random() * 65535 + 1);
            outInt.println(r);
            outInt.flush();
        } 
    }
}

