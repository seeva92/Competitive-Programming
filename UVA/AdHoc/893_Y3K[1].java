import java.util.*;
import java.io.*;
public class 893Y3K {
	public static void main(String args[]) throws Exception {
		System.setIn(new FileInputStream("1.txt"));
		// System.setOut(new PrintStream("2.txt"));
		PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out));
		out.println("wow");
		MyScanner st = new MyScanner();
		String str = st.nextLine();
		out.println(st.nextLine());
		out.println("wow");
	}
}

//-----------PrintWriter for faster output---------------------------------

//-----------MyScanner class for faster input----------
class MyScanner {
	BufferedReader br;
	StringTokenizer st;

	public MyScanner() {
		br = new BufferedReader(new InputStreamReader(System.in));
	}

	String next() {
		while (st == null || !st.hasMoreElements()) {
			try {
				st = new StringTokenizer(br.readLine());
			} catch (IOException e) {
				e.printStackTrace();
			}
		}
		return st.nextToken();
	}

	int nextInt() {
		return Integer.parseInt(next());
	}

	long nextLong() {
		return Long.parseLong(next());
	}

	double nextDouble() {
		return Double.parseDouble(next());
	}

	String nextLine() {
		String str = "";
		try {
			str = br.readLine();
		} catch (IOException e) {
			e.printStackTrace();
		}
		return str;
	}

}
