/*************************************************************************
 > File Name: DynamicProgramming.java
 > Author: King.Zevin
 > Mail: jzw0222@mail.ustc.edu.cn
 ************************************************************************/

import java.io.IOException;
import java.io.PrintWriter;
import java.nio.file.Paths;
import java.util.Arrays;
import java.util.Scanner;

public class DynamicProgramming {

    public static final boolean CHECKMODE = true;

    private static int[] p;
    private static int[][] m;
    private static int[][] s;
    private static long start;
    private static long end;
    private static long endurance;
    private static PrintWriter printResult;
    private static PrintWriter printTime;
    private static Scanner inputIntegers;

    public static void main(String[] args)throws IOException{
        // 初始化
        if(CHECKMODE){
            inputIntegers = new Scanner(Paths.get("../input/input.txt"), "utf-8");
            input();
            printResult = new PrintWriter("../output/result.txt", "utf-8");
            printTime = new PrintWriter("../output/time.txt", "utf-8");
        }
        else {
            inputIntegers = new Scanner(Paths.get("D:/USTC/algorithm/PB15111604-project2/ex1/input/input.txt"), "utf-8");
            input();
            printResult = new PrintWriter("D:/USTC/algorithm/PB15111604-project2/ex1/output/result.txt", "utf-8");
            printTime = new PrintWriter("D:/USTC/algorithm/PB15111604-project2/ex1/output/time.txt", "utf-8");
        }

        int[] tasks = {30, 20, 10, 5};
//        int[] tasks = {6};
        // 迭代处理
        for(int task : tasks){
            int[] tmpChain = Arrays.copyOf(p, task+1);
//            int[] tmpChain = {30, 35, 15, 5, 10, 20, 25};
            // 开始计时
            start = System.nanoTime();
            // 运行
            matrix(tmpChain);
            // 结束计时
            end = System.nanoTime();
            endurance = end - start;
            // 输出
            output(task);
        }
    }

    // 输入
    public static void input()throws IOException{
        p = new int[31];
        for(int i = 0; i < 31; i++){
            p[i] = inputIntegers.nextInt();
        }
    }

    // 输出
    public static void output(int n)throws IOException{
        // 得到形如((((A1,A2),A3),A4),A5)的串
        String result = printResultAug(1, n);
        // 用正则表达式匹配替换，以使输出更加美观
        result = result.replaceAll("(\\d+)(A)", "$1,$2");
        result = result.replaceAll("(\\))(\\()", "$1,$2");
        result = result.replaceAll("(\\))(A)", "$1,$2");
        result = result.replaceAll("(A)(\\()", "$1,$2");
        result = result.replaceAll("(\\d+)(\\()", "$1,$2");

        System.out.println("number of tasks: " + n);
        printResult.println("number of tasks: " + n);
        System.out.println("        result: " + result);
        printResult.println("        result: " + result);
        printResult.flush();
        System.out.println("number of tasks: " + n);
        printTime.println("number of tasks: " + n);
        System.out.println("        time: " + endurance  + "\tnanoseconds.");
        printTime.println("        time: " + endurance  + "\tnanoseconds.");
        printTime.flush();

    }

    // 动态规划算法实现
    public static void matrix(int[] p){
        int n = p.length - 1;
        m = new int[n+1][n+1];
        s = new int[n][n+1];
        for(int l = 2; l <= n; l++){
            for(int i = 1; i <= n-l+1; i++){
                int j = i + l - 1;
                m[i][j] = 2_147_483_647; //max
                for(int k = i; k <= j-1; k++){
                    int q = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
                    if (q < m[i][j]){
                        m[i][j] = q;
                        s[i][j] = k;
                    }
                }
            }
        }
    }

    // 递归生成次序串
    private static String printResultAug(int i, int j){
        if( i == j ){
            return "A"+i;
        }
        else{
            String l = printResultAug(i, s[i][j]);
            String r = printResultAug(s[i][j]+1, j);
            return "("+l+r+")";
        }
    }
}
