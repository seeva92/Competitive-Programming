import java.util.*;
import java.io.*;
import java.text.*;
class Main {
	public static void main(String args[]) throws Exception {
		// System.setIn(new FileInputStream("1.txt"));
		// System.setOut(new PrintStream("2.txt"));
		Scanner st = new Scanner(System.in);
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
}