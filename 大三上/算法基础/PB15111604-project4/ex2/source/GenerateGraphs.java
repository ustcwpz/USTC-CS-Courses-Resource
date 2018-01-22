
/*************************************************************************
 > File Name: GenerateGraphs.java
 > Author: King.Zevin
 > Mail: jzw0222@mail.ustc.edu.cn
 ************************************************************************/
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;

public class GenerateGraphs {
    private static PrintWriter outString;
    private static final int[] sizes = {1,2,3,4,5,6};
    private static ArrayList<Tuple> edges;

    public static void main(String[] args) throws IOException {
        while(true) {
            // 迭代生成各个input
            for (int i = 0; i < 6; i++) {
                int size = sizes[i];
                generateSize(size);
            }
            SCC scc = new SCC();
            if(scc.test()==0)break;
        }

    }

    private static void generateSize(int size) throws IOException {
        if (Johnson.CHECKMODE)
            outString = new PrintWriter("../size" + size + "/input/input.txt", "utf-8");
        else {
            outString = new PrintWriter("G:/PB15111604-project4/ex2/size" + size + "/input/input.txt", "utf-8");
        }

        int vertices = 4 << size;
        // vertices 是顶点个数V
        int nlogn = (size + 2) * vertices;
        // nlogn 即为 NlogN

        edges = new ArrayList<>();

        for (int i = 0; i < nlogn; i++) {
            int a = (int) (Math.random() * vertices);
            int b = (int) (Math.random() * vertices);
            int w = (int) (Math.random() * vertices + 1);
            Tuple t = new Tuple(a, b);
            if (contains(t))
                i--;
            else {
                edges.add(t);
                outString.printf("%d %d %d\n", a, b, w);
                outString.flush();
            }
        }
    }

    private static boolean contains(Tuple n){
        for(Tuple t: edges){
            if(t.isEqual(n))
                return true;
        }
        return false;
    }


}
class Tuple{
    int a;
    int b;

    public  Tuple(int A, int B){
        this.a = A;
        this.b = B;
    }

    public boolean isEqual(Tuple t){
        if(t.a == this.a && t.b == this.b)
            return true;
        if(t.a == this.b && t.b == this.a)
            return true;
        return false;
    }
}

