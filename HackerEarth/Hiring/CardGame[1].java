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
public class CardGame {

    public static void main(String args[]) throws Exception {
        // System.setIn(new FileInputStream("/home/shiva/Learning/1.txt"));
        // System.setOut(new PrintStream("/home/shiva/Learning/2.txt"));
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        int n;
        int count; String player;
        for (; t > 0; t--) {
            count = 0;
            n = Integer.parseInt(br.readLine());
            int p[] = new int[n];
            int s[] = new int[n];
            String pstr[] = br.readLine().split(" ");
            String sstr[] = br.readLine().split(" ");
            for (int i = 0; i < n; i++) {
                p[i] = Integer.parseInt(pstr[i]);
                s[i] = Integer.parseInt(sstr[i]);
                if (p[i] != s[i]) count++;
            }
            player = br.readLine();
            if((player.equals("Devu") && count/2==1) || (n==2)) System.out.printf("Devu\n");
            else System.out.printf("Churu\n");
        }
    }
}
