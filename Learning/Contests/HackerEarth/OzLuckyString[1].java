import java.util.*;
import java.io.*;
import java.text.*;

public class OzLuckyString {

    // public static void compute(String str, int r, int k) {
    //     StringBuffer sb = new StringBuffer(str);
    //     while (sb.length() > 0) {
    //         if (r == k) {
    //             int ln = sb.length() / 2;
    //             int lr = 0, lk = 0;
    //             for (int i = 0; i < ln; i++)
    //                 if (sb.charAt(i) == 'R') lr++;
    //                 else break;
    //             if (lr == ln) {
    //                 for (int i = ln; i < (ln << 1); i++)
    //                     if (sb.charAt(i) == 'K') lk++;
    //                     else break;
    //                 if (lk == lr) {
    //                     System.out.println(lr + lk);
    //                     break;
    //                 }
    //             }
    //             int idx = sb.lastIndexOf("R");
    //             if (idx != -1) {sb.deleteCharAt(idx); r--;}
    //             idx = sb.indexOf("K");
    //             if (idx != -1) {sb.deleteCharAt(idx); k--;}
    //         } else if (r > k) {
    //             int idx = sb.lastIndexOf("R");
    //             if (idx != -1) {sb.deleteCharAt(idx); r--;}
    //         } else {
    //             int idx = sb.indexOf("K");
    //             if (idx != -1) {sb.deleteCharAt(idx); k--;}
    //         }
    //         // System.out.println(r + " " + k);
    //         // System.out.println(sb.toString());
    //     }
    //     if (r == 0 && k == 0) System.out.println("0");
    // }
    public static void find(String str, int r, int k) {
        StringBuffer sb = new StringBuffer(str);
        if (sb.length() % 2 != 0) {
            if (r > k) {
                int idx = sb.lastIndexOf("R");
                if (idx != -1) { sb.deleteCharAt(idx); r--;}
            } else if (k > r) {
                int idx = sb.indexOf("K");
                if (idx != -1) { sb.deleteCharAt(idx); k--;}
            }
        }

        int len = sb.length();
        int lk = 0, rr = 0;
        StringBuffer lb = new StringBuffer("");
        StringBuffer rb = new StringBuffer("");

        // System.out.println(sb.toString());
        for (int i = 0; i < (len >> 1); i++) if (sb.charAt(i) == 'R') lb.append(sb.charAt(i));
        for (int i = (len >> 1); i < len; i++) if (sb.charAt(i) == 'K') rb.append(sb.charAt(i));
        // System.out.println(lk + " " + rr);

        if (lb.length() == rb.length()) System.out.println(lb.length() + rb.length());
        else System.out.println("0");
    }
    public static void main(String args[]) throws Exception {
        // System.setIn(new FileInputStream("/home/shiva/Learning/1.txt"));
        // System.setOut(new PrintStream("/home/shiva/Learning/2.txt"));
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        while (t > 0) {
            String str = br.readLine();
            int len  = str.length();
            int r = 0, k = 0;
            for (int i = 0; i < len; i++) {
                if (str.charAt(i) == 'R') r++;
                else k++;
            }
            // compute(str, r, k);
            find(str, r, k);
            t--;
        }

    }
}
