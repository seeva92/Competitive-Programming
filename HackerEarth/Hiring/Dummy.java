import java.util.*;
import java.io.*;
import java.text.*;
// class Dummy {
// 	public static void main(String args[]) throws Exception {
// 		System.setIn(new FileInputStream("/home/shiva/Learning/1.txt"));
// 		System.setOut(new PrintStream("/home/shiva/Learning/2.txt"));
// 		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
// 		System.out.println(br.readLine());
// 		System.out.println("Get ready folks");
// 	}
// }
public class Dummy {
    private int value = 4;

    public int getValue() {
        return value;
    }

    public void changeVal(int value) {
        value = value;
    }

    public static void main(String args[]) {
        int a = 1;
        Dummy c = new Dummy();
        c.changeVal(a);
        System.out.print(c.getValue());
    }
}
