import java.util.*;
import java.io.*;
class Tree3 {
	static long compute(int i, int j, int lvl, ArrayList<ArrayList<Long>> val, long arr[], long M) {
		if (i == j) {val.get(lvl).add(arr[i]); return arr[i];}
		long l = compute(i, (i + j) / 2, lvl + 1, val, arr, M);
		long r = compute((i + j) / 2 + 1, j, lvl + 1, val, arr, M);
		val.get(lvl).add((l * r) % M);

		return (l * r) % M;
	}
	public static void main(String args[]) throws Exception {
		System.setIn(new FileInputStream("/home/shiva/Learning/1.txt"));
		System.setOut(new PrintStream("/home/shiva/Learning/2.txt"));
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String inp[] = br.readLine().split(" ");
		long L = Long.parseLong(inp[0]), M = Long.parseLong(inp[1]);

		long arr[] = new long[1 << 22];
		ArrayList<ArrayList<Long>> val = new ArrayList<ArrayList<Long>>();
		int len = arr.length;
		for (int i = 0; i < len; i++) {
			arr[i] = i + 1;
		}
		for (int i = 0; i < 22; i++) val.add(new ArrayList<Long>());
		compute(0, arr.length - 1, 0, val, arr, M);
		// int N, X, Y;
		// for (int i = 0; i < M; i++) {
		// 	inp = br.readLine().split(" ");
		// 	N = Integer.parseInt(inp[0]); X = Integer.parseInt(inp[1]); Y = Integer.parseInt(inp[2]);
		// 	long total = 0;
		// 	// for(int j = X;j<=Y;j++){
		// 	// 	total = (total+val.get(N-1).get(j-1))%M;
		// 	// }
		// 	System.out.println(total);
		// }

	}
}