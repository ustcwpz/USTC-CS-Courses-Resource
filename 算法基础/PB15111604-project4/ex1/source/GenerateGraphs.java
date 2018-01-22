
/*************************************************************************
 > File Name: GenerateGraphs.java
 > Author: King.Zevin
 > Mail: jzw0222@mail.ustc.edu.cn
 ************************************************************************/
import java.io.IOException;
import java.io.PrintWriter;

public class GenerateGraphs {
    private static PrintWriter outString;
    private static final int[] sizes = {1,2,3,4,5,6};

    public static void main(String[] args) throws IOException {
        // 迭代生成各个input
        for(int size:sizes){
            generateSize(size);
        }
    }

    private static void generateSize(int size) throws IOException {
        if(SCC.CHECKMODE)
            outString = new PrintWriter("../size" + size + "/input/input.txt", "utf-8");
        else{
            outString = new PrintWriter("G:/PB15111604-project4/ex1/size" + size + "/input/input.txt", "utf-8");
        }

        int vertices = 4 << size;
        // vertices 是顶点个数V
        int nlogn = (size+2)*vertices;
        // nlogn 即为 NlogN

        for(int i = 0; i < nlogn; i++){
            int a = (int)(Math.random() * vertices);
            int b = (int)(Math.random() * vertices);
            outString.printf("%d %d\n", a, b);
            outString.flush();
        }

    }
}


