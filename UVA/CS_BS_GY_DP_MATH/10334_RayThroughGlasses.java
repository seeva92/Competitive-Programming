import java.util.*;
import java.io.*;
import java.text.*;
import java.math.*;
class Main {
	public static void main(String args[]) throws Exception {
		// System.setIn(new FileInputStream("E:/Shiva backup/Shiva/Learning/Learning/UVA/1.txt"));
		// System.setOut(new PrintStream("E:/Shiva backup/Shiva/Learning/Learning/UVA/2.txt"));
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BigInteger [] arr = new BigInteger[1010];
		arr[0] = BigInteger.ONE; arr[1] = arr[0].add(BigInteger.ONE);
		for (int i = 2; i < 1010; i++) arr[i] = arr[i - 1].add(arr[i - 2]);
		while (br.ready()) {
			System.out.println(arr[Integer.parseInt(br.readLine())]);
		}
	}
}