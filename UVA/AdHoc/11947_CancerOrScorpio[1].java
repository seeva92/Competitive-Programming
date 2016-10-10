import java.util.*;
import java.io.*;
import java.text.*;
class Main {
	static String getSign(int month, int day, int year) {
		boolean flag = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0) ? true : false;
		// System.out.println("Month " + month + "Day " + day);
		if ((month == 0 && day >= 21 && day <= 31) || (month == 1 && day >= 1 && day <= 19))
			return "aquarius";
		else if ((month == 1 && day >= 20 && day <= 29) || (month == 2 && day >= 1 && day <= 20))
			return "pisces";
		else if ((month == 2 && day >= 21 && day <= 31) || (month == 3 && day >= 1 && day <= 20))
			return "aries";
		else if ((month == 3 && day >= 21 && day <= 30) || (month == 4 && day >= 1 && day <= 21))
			return "taurus";
		else if ((month == 4 && day >= 22 && day <= 31) || (month == 5 && day >= 1 && day <= 21))
			return "gemini";
		else if ((month == 5 && day >= 22 && day <= 30) || (month == 6 && day >= 1 && day <= 22))
			return "cancer";
		else if ((month == 6 && day >= 23 && day <= 31) || (month == 7 && day >= 1 && day <= 21))
			return "leo";
		else if ((month == 7 && day >= 22 && day <= 31) || (month == 8 && day >= 1 && day <= 23))
			return "virgo";
		else if ((month == 8 && day >= 24 && day <= 30) || (month == 9 &&  day >= 1 && day <= 23))
			return "libra";
		else if ((month == 9 && day >= 24 && day <= 31) || (month == 10 &&  day >= 1 && day <= 22))
			return "scorpio";
		else if ((month == 10 && day >= 23 && day <= 30) || (month == 11 && day >= 1 && day <= 22))
			return "sagittarius";
		return "capricorn";

	}
	public static void main(String args[]) throws Exception {
		// System.setIn(new FileInputStream("1.txt"));
		// System.setOut(new PrintStream("2.txt"));
		MyScanner st = new MyScanner();
		int n = st.nextInt();
		String str;
		Calendar cal;
		SimpleDateFormat sdf = new SimpleDateFormat("MMddyyyy");
		SimpleDateFormat outputFormat = new SimpleDateFormat("MM/dd/yyyy");
		int days = 40 * 7;
		for (int i = 1; i <= n; i++) {
			str = st.next();
			cal = new GregorianCalendar();
			Date date = sdf.parse(str);
			cal.setTime(date);
			// System.out.println(sdf.format(cal.getTime()));

			cal.add(Calendar.DATE, days);

			System.out.println(i + " " + outputFormat.format(cal.getTime()) + " " + getSign((int)cal.get(Calendar.MONTH), (int)cal.get(Calendar.DAY_OF_MONTH), cal.get(Calendar.YEAR)));


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

