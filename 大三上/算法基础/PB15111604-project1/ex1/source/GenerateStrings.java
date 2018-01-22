/*************************************************************************
	> File Name: GenerateStrings.java
	> Author: King.Zevin
	> Mail: jzw0222@mail.ustc.edu.cn
	> Created Time: Fri Oct 13 18:28:01 2017
 ************************************************************************/

import java.io.*;
import java.util.*;

public class GenerateStrings{
    public static void main(String[] args) throws IOException{
        PrintWriter outString = new PrintWriter("../input/input_strings.txt", "UTF-8");
        for(int i = 0; i < (1 << 17) ; i++){
            int l = (int)(Math.random() * 32 + 1);
            String s = "";
            for(int j = 0; j < l; j++){
                int k = (int)(Math.random() * 26);
                char c = (char)('a' + k);
                s += c;
            }
            outString.println(s);
            outString.flush();
        } 
    }
}

