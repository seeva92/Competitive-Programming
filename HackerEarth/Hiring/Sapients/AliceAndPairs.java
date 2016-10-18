import java.io.*;
import java.util.*;
import java.math.*;
class AliceAndPairs {
	static FileInputStream fin;
	static FileOutputStream fout;
	static BufferedReader br;
	static PrintWriter pr;
	static void initL() throws Exception {
		fin = new FileInputStream("/Users/seeva92/Workspace/Contests/1.txt");
		fout = new FileOutputStream("/Users/seeva92/Workspace/Contests/2.txt");
		br = new BufferedReader(new InputStreamReader(fin));
		pr = new PrintWriter(fout, true);
	}
	static void initI() throws Exception {
		br = new BufferedReader(new InputStreamReader(System.in));
		pr = new PrintWriter(System.out, true);
	}
	int T, N;
	public void init() throws Exception {
		T = Integer.parseInt(br.readLine());
		for (int j = 0; j < T; j++) {
			N = Integer.parseInt(br.readLine());
			int len = (int)Math.sqrt(N);
			int c = 0;
			if (N % 2 != 0) {
				BigInteger b = new BigInteger(Integer.toString(N));
				if (b.isProbablePrime(1)) {
					pr.println("2");
					continue;
				}
			}
			for (int i = 1; i <= len; i++) {
				if (N % i == 0) {
					c++;
					if (N / i != i) c++;
				}
			}
			pr.println(c);
		}
	}
	public static void main(String[] args) throws Exception {
		initL();
		new AliceAndPairs().init();
	}
}