/*************************************************************************
 > File Name: PolynomialMultiplication.java
 > Author: King.Zevin
 > Mail: jzw0222@mail.ustc.edu.cn
 ************************************************************************/

import java.io.IOException;
import java.io.PrintWriter;
import java.math.RoundingMode;
import java.nio.file.Paths;
import java.text.DecimalFormat;
import java.util.Arrays;
import java.util.Scanner;

public class PolynomialMultiplication {

    public static final boolean CHECKMODE = true;
    // 如果要在自己的机器上跑，请置为true

    private static double[] originalData;   // 存放原始数据
    private static double[] a;              // 存放扩充的系数数组a
    private static double[] b;              // 存放扩充的系数数组a
    private static Complex[] c;             // 存放结果数组c
    private static Complex[] A;             // a的DFT
    private static Complex[] B;             // b的DFT
    private static Complex[] C;             // a,b点乘之后再逆DFT处理
    private static double[] Normal;         // 存放普通乘法的结果
    private static boolean ifFFT;           // 用于输出的标志
    private static long start;              // 计时开始
    private static long end;                // 计时结束
    private static long endurance;          // 时长
    private static PrintWriter printResult; // result.txt
    private static PrintWriter printTime;   // time.txt
    private static Scanner inputDoubles;    // input.txt
    public static final int MAX = 65536;    // 为了观察更大的n的效果

    public static void main(String[] args)throws IOException{
        // 初始化
        init();

//        int[] coefficients = {MAX/2, MAX/4, MAX/16, MAX/32, 60,  32, 16, 4};      // 为了观察n比较大时，fft与普通乘法的效率。
        int[] coefficients = {60,  32, 16, 4};

        // 迭代处理
        for(int len_coef : coefficients){
            int len = 2*fix(len_coef);                              // 为了保证2的幂，同时扩展为2n
            a = Arrays.copyOfRange(originalData, 0, len);
            b = Arrays.copyOfRange(originalData, len_coef, len_coef+len);

            for(int i = len_coef; i < len; i++)
                a[i] = b[i] = 0;

            start = System.nanoTime();                          // 开始计时
            normalMul(a, b, len_coef);                              // 运行
            end = System.nanoTime();                            // 结束计时
            endurance = end - start;
            output(len_coef);                                       // 输出

        }
        // 迭代处理
        for(int len_coef : coefficients){
            int len = 2*fix(len_coef);                              // 为了保证2的幂，同时扩展为2n
            a = Arrays.copyOfRange(originalData, 0, len);
            b = Arrays.copyOfRange(originalData, len_coef, len_coef+len);

            for(int i = len_coef; i < len; i++)
                a[i] = b[i] = 0;

            start = System.nanoTime();                          // 开始计时
            fftMul(a, b, len_coef * 2 - 1);                 // 运行
            end = System.nanoTime();                            // 结束计时
            endurance = end - start;
            output(len_coef);                                       // 输出
        }
    }

    // 初始化
    private static void init()throws IOException{
        // 根据是否为检查模式，选择适合的路径
        if(CHECKMODE){
            // 检查模式，非IntelliJ Idea
            inputDoubles = new Scanner(Paths.get("../input/input.txt"), "utf-8");
            input();
            printResult = new PrintWriter("../output/result.txt", "utf-8");
            printTime = new PrintWriter("../output/time.txt", "utf-8");
        }

        else{
            // 非检查模式，IntelliJ Idea
            inputDoubles = new Scanner(Paths.get("D:/USTC/algorithm/PB15111604-project2/ex2/input/input.txt"), "utf-8");
            input();
            printResult = new PrintWriter("D:/USTC/algorithm/PB15111604-project2/ex2/output/result.txt", "utf-8");
            printTime = new PrintWriter("D:/USTC/algorithm/PB15111604-project2/ex2/output/time.txt", "utf-8");
        }
    }

    // 输入
    private static void input()throws IOException{

        originalData = new double[MAX];
        for(int i = 0; i < MAX; i++) {
            originalData[i] = inputDoubles.nextDouble();
        }
    }

    // 输出
    private static void output(int len_coef)throws IOException{
        int n = len_coef;
        String result = printResultAug();
        String typeMul = ifFFT ? "FFT   " : "Normal";

//        System.out.println("number of coefficients: " + n);
        printResult.println("number of coefficients: " + n);
//        System.out.println("    "+ typeMul + "\tresult: " + result);
        printResult.println("    "+ typeMul + "\tresult: " + result);
        printResult.flush();
        System.out.println("number of coefficients: " + n);
        printTime.println("number of coefficients: " + n);
        System.out.println("    "+ typeMul + "\ttime: " + endurance  + "\tnanoseconds.");
        printTime.println("    "+ typeMul + "\ttime: " + endurance  + "\tnanoseconds.");
        printTime.flush();
    }

    // 为了保证2的幂,扩展为len
    // len -- 输出，为2的幂
    private static int fix(int n){
        int len = 1;
        while(len < n)
            len <<= 1;
        return len;
    }

    // FFT相乘的框架
    // a,b -- 源数组
    // lenResult -- 最后输出所对应的数组长度
    //              ,为了避免扩充的影响而设置
    private static void fftMul(double[] a, double[] b, int lenResult){
        int n = a.length;
        A = new Complex[n];
        B = new Complex[n];
        for(int i = 0; i < n; i ++){
            A[i] = new Complex();
            B[i] = new Complex();
        }
        C = new Complex[n];
        iterativeFFT(a, A);
        iterativeFFT(b, B);
        plotMult(C, A, B);
        revFFT(C);
        c = Arrays.copyOfRange(c, 0, lenResult);
        ifFFT = true;
    }

    // 迭代FFT
    // a -- 源数组
    // A -- 目的数组
    private static void iterativeFFT(double[] a, Complex[] A){
        int n = a.length;
        int log = (int)Math.round(Math.log(n)/Math.log(2));

        bitReverseCopy(a, A, log);

        Complex wm = new Complex(), w = new Complex(), t = new Complex(), u = new Complex();
        for(int s = 2; s <= n; s <<= 1){
            int m = s;
            wm.r = Math.cos(2 * Math.PI / m);
            wm.i = Math.sin(2 * Math.PI / m);
            for(int k = 0; k < n; k += m){
                w.set(1, 0);
                for(int j = 0; j < m/2; j++){
                    t.set(w.mul(A[k+j+m/2]));
                    u.set(A[k+j]);
                    A[k+j] = u.add(t);
                    A[k+j+m/2] = u.minus(t);
                    w.set(w.mul(wm));
                }
            }
        }
    }

    // 针对FFT的逆序置换
    // a -- 源数组
    // A -- 目的数组
    // bits -- 位数
    private static void bitReverseCopy(double[]a, Complex[] A, int bits){
        int n = A.length;
        for(int i = 0; i < n; i++)
            A[bitRev(i, bits)].set(a[i], 0);
    }

    // 针对FFT的逆的逆序置换
    // a -- 源数组
    // A -- 目的数组
    // bits -- 位数
    private static void bitReverseCopy(Complex[]C, Complex[] c, int bits){
        int n = c.length;
        for(int i = 0; i < n; i++)
            c[bitRev(i, bits)] = C[i];
    }

    // 位的逆置换。(书上说的很“简单”的部分)
    // data -- 要置换的数
    // bits -- 数的位数
    private static int bitRev(int data, int bits){
        int low = 0;
        int high = bits-1;
        int bit_low;
        int bit_high;
        while(low < high){
            bit_low = data & (1<<low);
            bit_high = data & (1<<high);
            if(bit_low == 0){
                data &= ~(1 << high);               // set 0
            }
            else{
                data |= (1 << high);                // set 1
            }
            if(bit_high == 0){
                data &= ~(1 << low);               // set 0
            }
            else{
                data |= (1 << low);                // set 1
            }
            low ++;
            high --;
        }
        return data;
    }

    // 逐点相乘
    // C -- 结果存放
    // A,B -- 乘数数组
    private static void plotMult(Complex[] C, Complex[] A, Complex[] B){
        int n = A.length;
        for(int i = 0; i < n; i++){
            C[i] = new Complex(A[i].mul(B[i]));
        }
    }

    // FFT的逆
    // C -- 操作数
    // c -- 结果放在c
    private static void revFFT(Complex[] C){
        int n = C.length;
        c = new Complex[n];
        int log = (int)Math.round(Math.log(n)/Math.log(2));

        bitReverseCopy(C, c, log);

        Complex wm = new Complex(), w = new Complex(), t = new Complex(), u = new Complex();
        for(int s = 2; s <= n; s <<= 1){
            int m = s;
            wm.r = Math.cos(2 * Math.PI / m);
            wm.i = - Math.sin(2 * Math.PI / m);
            for(int k = 0; k < n; k += m){
                w.set(1, 0);
                for(int j = 0; j < m/2; j++){
                    t.set(w.mul(c[k+j+m/2]));
                    u.set(c[k+j]);
                    c[k+j] = u.add(t);
                    c[k+j+m/2] = u.minus(t);
                    w.set(w.mul(wm));
                }
            }
        }
        for(int i = 0; i < n; i++)
            c[i].r /= n;
    }

    // 普通的多项式乘法
    // a,b -- 相乘数组
    // n -- 未扩充时a的系数个数
    private static void normalMul(double[] a, double[] b, int n){
        int len = 2*n-1;
        Normal = new double[len];
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                Normal[i + j] += a[i] * b[j];
            }
        }
        ifFFT = false;
    }

    // 用于生成所要输出的系数字符串，
    // 形如(C0,C1,C2)
    private static String printResultAug(){
        String s = "(";
        int i;

        DecimalFormat df = new DecimalFormat("################################.00000");
        if(ifFFT){
            df.setRoundingMode(RoundingMode.CEILING);
            for(i = 0; i < c.length-1; i++){
                s += df.format(c[i].r) + ",";
            }
            s += df.format(c[i].r);
        }
        else{
            for(i = 0; i < Normal.length-1; i++){
                s += df.format(Normal[i]) + ",";
            }
            s += df.format(Normal[i]);
        }
        s += ")";
        return s;
    }
}

// 复数类
// 实现了简单的加减乘运算.
class Complex {
    public double r;           // 实部
    public double i;           // 虚部
    public Complex(double rr, double ii){
        r = rr;
        i = ii;
    }
    public Complex(){
        r = 0;
        i = 0;
    }

    public Complex(Complex c) {
        r = c.r;
        i = c.i;
    }

    public void set(double rr, double ii){
        r = rr;
        i = ii;
    }

    public void set(Complex c){
        r = c.r;
        i = c.i;
    }

    public Complex add(Complex c){
        return new Complex(r + c.r, i + c.i);
    }

    public Complex minus(Complex c){
        return new Complex(r - c.r, i - c.i);
    }

    public Complex mul(Complex c){
        double tr = r*c.r - i*c.i;
        double ti = i*c.r + r*c.i;
        return new Complex(tr, ti);
    }
}