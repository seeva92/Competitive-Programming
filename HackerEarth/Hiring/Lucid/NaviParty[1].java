import java.util.*;
import java.io.*;
class NaviParty {
    public static void main(String args[] ) throws Exception {

        // * Read input from stdin and provide input before running
        // System.setIn(new FileInputStream("/home/shiva/Learning/1.txt"));
        // System.setOut(new PrintStream("/home/shiva/Learning/2.txt"));
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String line[] = br.readLine().split(" ");
        int N = Integer.parseInt(line[0]);
        int Q = Integer.parseInt(line[1]);
        HashSet<String> mp = new HashSet<String>();
        for (int i = 0; i < N; i++)
            mp.add(br.readLine());

        String regex = "[0-9]+";
        int invited = 0;
        for (int i = 0; i < Q; i++) {
            String temp = br.readLine();
            if (!temp.matches(regex)) {
                if (mp.contains(temp)) {
                    invited++;
                }
            } else {
                int a = Integer.parseInt(temp);
                if (a > 20) invited++;
            }
        }
        System.out.println(Q - invited);
    }
}
