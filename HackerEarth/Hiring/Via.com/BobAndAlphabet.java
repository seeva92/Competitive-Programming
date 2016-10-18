import java.io.*;
import java.util.*;
class BobAndAlphabet {
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
	int T; String S;

	int []count;
	long [][] arr, dp;
	public void compute() {
		count = new int[26];
		int len = S.length();
		arr = new long[26][len];
		dp = new long[26][len];
		char sarr[] = S.toCharArray();
		for (int i = 0; i < len; i++  ) {
			arr[sarr[i] - 'a'][count[sarr[i] - 'a']] = i;
			count[sarr[i] - 'a']++;
		}
		// for (int i = 0; i < 26; i++)
		// for (int j = 0; j < count[i]; j++) dp[i][j] = (long)1e9;

		// for (int i = 0; i < 26; i++) dp[0][i] = arr[0][i];
		// for (int i = 0; i < 26; i++, pr.println())
		// for (int j = 0; j < len; j++)
		// pr.print(arr[i][j] + " ");
		long res = (long)1e9;
		for (int i = 1; i < 26; i++) {
			for (int j = 0; j < count[i]; j++) {
				long less = (long)1e9, temp = (long)1e9;
				for (int k = 0; k < count[i - 1]; k++) {
					temp = dp[i - 1][k] + Math.min(temp, Math.abs(arr[i][j] - arr[i - 1][k]));
					if (less < temp) break;
					less = temp;
				}
				dp[i][j] = less;
				if (i == 25) {
					res = Math.min(res, dp[i][j]);
				}
			}
		}

		pr.println(res);

		// for (int i = 0; i < 26; i++, pr.println())
		// 	for (int j = 0; j < len; j++)
		// 		pr.print(dp[i][j] + " ");
	}
	public void init() throws Exception {
		T = Integer.parseInt(br.readLine());
		for (int i = 0; i < T; i++) {
			S = br.readLine();
			compute();
		}
	}
	public static void main(String[] args) throws Exception {
		initI();
		BobAndAlphabet b = new BobAndAlphabet();
		b.init();
	}
}