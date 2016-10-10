import java.util.*;
import java.io.*;
import java.text.*;
class Main {
	public static void main(String args[]) throws Exception {
		// System.setIn(new FileInputStream("1.txt"));
		// System.setOut(new PrintStream("2.txt"));
		MyScanner st = new MyScanner();
		int n = st.nextInt();
		int d = st.nextInt(); int m = st.nextInt(); int yr = st.nextInt();
		Calendar cal;
		SimpleDateFormat sdf = new SimpleDateFormat("d M yyyy");
		while (n != 0 || d != 0 || m != 0 || yr != 0) {
			cal = new GregorianCalendar(yr, m - 1, d);
			// System.out.println(sdf.format(cal.getTime()));

			cal.add(Calendar.DATE, n);

			System.out.println(sdf.format(cal.getTime()));


			n = st.nextInt();
			d = st.nextInt(); m = st.nextInt(); yr = st.nextInt();
		}
	}
	//-----------PrintWriter for faster output---------------------------------

//-----------MyScanner class for faster input----------
	static class MyScanner {
		BufferedReader br;
		StringTokenizer st;
		PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out));

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

}

