import java.util.*;
import java.io.*;
import java.text.*;
import java.math.*;
class Main {
	public static void main(String args[]) throws Exception {
		// System.setIn(new FileInputStream("E:/Shiva backup/Shiva/Learning/Learning/UVA/1.txt"));
		// System.setOut(new PrintStream("E:/Shiva backup/Shiva/Learning/Learning/UVA/2.txt"));
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		while (br.ready()) {
			ArrayList<BigInteger> arr = new ArrayList<BigInteger>();
			boolean flag = true;
			int len;
			while (flag) {
				String [] str = br.readLine().split(" ");
				len = str.length;
				for (int i = 0; i < len; i++)
					if (!str[i].equals("-999999"))
						arr.add(new BigInteger(str[i]));
					else {
						flag = false; break;
					}
			}
			len  = arr.size();
			BigInteger res = new BigInteger("-999999"), pos = null, neg = null;
			int s;
			BigInteger temp;
			for (int i = 0; i < len; i++) {
				s = arr.get(i).compareTo(BigInteger.ZERO);
				if (s == 0) {
					res = res.max(BigInteger.ZERO);
					pos = neg = null;
					continue;
				} else if (s > 0) {
					neg = neg == null ? null : neg.multiply(arr.get(i));

					if (pos == null) { pos = arr.get(i);}
					else {pos = pos.multiply(arr.get(i));}

				} else {
					temp = neg;
					if (pos == null) { neg = arr.get(i); }
					else {neg = pos.multiply(arr.get(i)); }

					pos = temp == null ? temp : temp.multiply(arr.get(i));
				}
				if (pos != null)
					res = res.max(pos);
				if (neg != null)
					res = res.max(neg);
			}
			System.out.println(res.toString());
		}
	}
}