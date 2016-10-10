import java.util.*;
import java.io.*;
class OZStrings {
	static int f(int o, int z, int n, String line[]) {
		if (n == 0) return 0;
		if (o == 0 && z == 0) return 0;
		int to = 0, tz = 0;
		String str = line[n - 1];
		for (int i = 0; i < str.length(); i++)
				if (str.charAt(i) == 'O') to++; else tz++;
		if (to > o || tz > z) return f(o, z, n - 1, line);
		// System.out.println(o + " " + z + " " + n + " ");
		return Math.max(f(o, z, n - 1, line), 1 + f(o - to, z - tz, n - 1, line));
	}
	public static void main(String[] args) throws Exception {
		// System.setIn(new FileInputStream("/home/shiva/Learning/1.txt"));
		// System.setOut(new PrintStream("/home/shiva/Learning/2.txt"));
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int t = Integer.parseInt(br.readLine());
		while (t > 0) {
			String line[] = br.readLine().split(" ");
			int n = Integer.parseInt(line[0]);
			int o = Integer.parseInt(line[1]);
			int z = Integer.parseInt(line[2]);
			// System.out.println(o + " " + z + " " + n + " ");

			line = br.readLine().split(" ");
			System.out.println(f(o, z, n, line));
			t--;
		}
	}
}
