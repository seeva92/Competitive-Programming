import java.io.*;
import java.util.*;
class VasyaRhezo {
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
	int N, Q, X, Y, Val;
	int [] A, B, Seg;
	public void build() {  // build the tree
		for (int i = N; i > 0; --i) {
			int lf = Seg[(i << 1)], rf = Seg[(i << 1) + 1];
			if (A[lf] < A[rf]) Seg[i] = rf;
			else if (A[lf] > A[rf]) Seg[i] = lf;
			else {
				if (B[lf] < B[rf]) Seg[i] = lf;
				else if (B[lf] > B[rf]) Seg[i] = rf;
				else if (lf < rf) Seg[i] = lf;
				else Seg[i] = rf;
			}
		}
	}

	public int query(int l, int r) {

		int res = Seg.length - 1;
		for (l += N, r += N; l < r; l >>= 1, r >>= 1) {
			if (l % 2 != 0) {
				if (A[l] < A[res]) res = res;
				else if (A[l] > A[res]) res = l;
				else {
					if (B[l] < B[res]) res = l;
					else if (B[l] > B[res]) res = res;
					else if (l < res) res = l;
					else res = res;
				}
				l++;
			}
			if (r % 2 != 0) {
				r--;
				if (A[r] < A[res]) res = res;
				else if (A[r] > A[res]) res = r;
				else {
					if (B[r] < B[res]) res = r;
					else if (B[r] > B[res]) res = res;
					else if (l < res) res = r;
					else res = res;
				}
			}
		}
		return res;


	}
	public void init() throws Exception {
		N = Integer.parseInt(br.readLine());
		A = new int[2 * N + 5]; B = new int[2 * N + 5]; Seg = new int[2 * N + 5];
		String [] tempA = br.readLine().split(" ");
		String [] tempB = br.readLine().split(" ");
		for (int i = 1; i <= N; i++) {
			A[i] = Integer.parseInt(tempA[i - 1]);
			B[i] = Integer.parseInt(tempB[i - 1]);
			Seg[N + i] = i;
		}
		build();
		Q = Integer.parseInt(br.readLine());
		for (int i = 1; i <= Q; i++) {
			tempA = br.readLine().split(" ");
			X = Integer.parseInt(tempA[0]); Y = Integer.parseInt(tempA[1]);
			pr.println(query(X, Y));
		}
	}
	public static void main(String[] args) throws Exception {
		initL();
		VasyaRhezo c = new VasyaRhezo();
		c.init();
	}
}