import java.util.*;
import java.io.*;
import java.text.*;
// class Dummy {
//  public static void main(String args[]) throws Exception {
//      System.setIn(new FileInputStream("/home/shiva/Learning/1.txt"));
//      System.setOut(new PrintStream("/home/shiva/Learning/2.txt"));
//      BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
//      System.out.println(br.readLine());
//      System.out.println("Get ready folks");
//  }
// }
public class ProductSquare {

    public static void main(String args[]) throws Exception {
        System.setIn(new FileInputStream("/home/shiva/Learning/1.txt"));
        System.setOut(new PrintStream("/home/shiva/Learning/2.txt"));
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int arr[] = new int[n];
        int count[] = new int[5010];        
        for (int i = 0; i < n; i++) {
            arr[i] = Integer.parseInt(br.readLine());
            count[arr[i]]++;
        }
        int samplespace = (n * (n - 1)) / 2;
        int total = 0;
        for (int i = 1; i <= 5000; i++) {
            if (count[i] > 1) {
                total += ((count[i] * (count[i] - 1)) / 2);
            }
        }
        double sd = (double)samplespace;
        double out = (double)total;
        double res = out/sd;
        NumberFormat formatter = new DecimalFormat("#0.000000");
        System.out.println(formatter.format(res));
        System.out.printf("%.5f",res);
    }
}
