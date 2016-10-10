import java.io.*;
import java.util.*;
class MattsGraphBook {
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
	int n, k, a, b, r;
	ArrayList<Integer> v[], arr, brr;
	int [] vis;

	void init() throws Exception {
		n = Integer.parseInt(br.readLine()); k = Integer.parseInt(br.readLine());
		arr = new ArrayList<Integer>();
		brr = new ArrayList<Integer>();
		vis = new int[n];
		v = new ArrayList[n];
		for (int i = 0; i < n; i++) v[i] = new ArrayList<Integer>();

		for (int i = 1; i <= k; i++) {
			String [] temp = br.readLine().split(" ");
			a = Integer.parseInt(temp[0]); b = Integer.parseInt(temp[1]);
			arr.add(a); brr.add(b);
		}
		r = Integer.parseInt(br.readLine());
		int len = arr.size();
		for (int i = 0; i < len; i++) {
			if (arr.get(i) == r || brr.get(i) == r) continue;
			v[arr.get(i)].add(brr.get(i));
			v[brr.get(i)].add(arr.get(i));
		}
	}
	void dfs(int i) {
		vis[i] = 1;
		for (int j = 0; j < v[i].size(); j++) {
			if (vis[v[i].get(j)] != 1) {
				dfs(v[i].get(j));
			}
		}
	}
	void check() {
		for (int i = 0; i < n; i++) {
			if (i == r) continue;
			if (vis[i] == 0) {
				pr.println("Not Connected"); return;
			}
		}
		pr.println("Connected");
	}

	public static void main(String[] args) throws Exception {
		init();
		MattsGraphBook mb = new MattsGraphBook();
		mb.init();
		mb.dfs(0);
		mb.check();
	}
}
