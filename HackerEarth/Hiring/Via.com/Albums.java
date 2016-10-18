import java.io.*;
import java.util.*;
class Albums {
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
	int N, Q, L, R, K;
	int arr[];
	static void initI() throws Exception {
		br = new BufferedReader(new InputStreamReader(System.in));
		pr = new PrintWriter(System.out, true);
	}
	public void init() throws Exception {
		N = Integer.parseInt(br.readLine());
		arr = new int[N + 7];
		String [] sarr = br.readLine().split(" ");
		for (int i = 0; i < N; i++) arr[i] = Integer.parseInt(sarr[i]);
		Q = Integer.parseInt(br.readLine());
		for (int i = 0; i < Q; i++) {
			sarr = br.readLine().split(" ");
			L = Integer.parseInt(sarr[0]); R = Integer.parseInt(sarr[1]);
			K = Integer.parseInt(sarr[2]);
			int c = 0;
			for (int j = L - 1; j <= R - 1; j++)
				if (arr[j] >= K && arr[j] % K == 0) c++;
			pr.println(c);
		}
	}
	public static void main(String[] args) throws Exception {
		initI();
		new Albums().init();
	}
}