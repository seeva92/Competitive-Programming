import java.util.*;
import java.io.*;
class Paintings {
	public static void main(String args[]) throws Exception {
		System.setIn(new FileInputStream("/home/shiva/Learning/1.txt"));
		System.setOut(new PrintStream("/home/shiva/Learning/2.txt"));
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int t = Integer.parseInt(br.readLine());
		for (int a = 0; a < t; a++) {
			int x, y, z;
			String [] inp = br.readLine().split(" ");
			x = Integer.parseInt(inp[0]); y = Integer.parseInt(inp[1]); z = Integer.parseInt(inp[2]);
			long total = 0;
			int temp =  Math.min(x,Math.min(y,z));
			total += temp;
			x-= temp; y-= temp; z-= temp;
			total += x/3;
			total += y/3;
			total += z/3;
			System.out.println(total);
		}
	}
}