import java.util.*;
import java.io.*;
import java.text.*;
import java.math.*;
class Main {
	static BigInteger[] fibo = new BigInteger[110];


	public static void main(String args[]) throws Exception {
		// System.setIn(new FileInputStream("E:/Shiva backup/Shiva/Learning/Learning/UVA/1.txt"));
		// System.setOut(new PrintStream("E:/Shiva backup/Shiva/Learning/Learning/UVA/2.txt"));
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter pw = new PrintWriter(System.out);
		fibo[1] = BigInteger.ONE;
		fibo[2] = new BigInteger("2");
		for (int i = 3; i < 110; i++)
			fibo[i] = fibo[i - 1].add(fibo[i - 2]);
		while (br.ready()) {
			String str1 = br.readLine();
			String str2 = br.readLine();
			if (br.ready())
				br.readLine();
			int l1 = str1.length(), l2 = str2.length();
			BigInteger sum = new BigInteger("0");
			for (int i = l1 - 1, j = 1; i >= 0; i--, j++)
				if (str1.charAt(i) == '1')
					sum = sum.add(fibo[j]);
			for (int i = l2 - 1, j = 1; i >= 0; i--, j++)
				if (str2.charAt(i) == '1')
					sum = sum.add(fibo[j]);

			int i;
			for (i = 1; i < 110; i++)
				if (fibo[i].compareTo(sum) >= 0)
					break;
			if (fibo[i].compareTo(sum) > 0) i--;
			if (i != 0) {
				for (int j = i; j > 0; j--) {
					if (sum.compareTo(fibo[j]) >= 0) {
						sum = sum.subtract(fibo[j]);
						System.out.print("1");
					} else System.out.print("0");
				}
			}else System.out.print("0");

			System.out.print('\n');
			if (br.ready())
				System.out.print('\n');
		}
	}
}