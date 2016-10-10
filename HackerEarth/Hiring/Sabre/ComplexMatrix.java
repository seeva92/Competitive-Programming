import java.io.*;
import java.util.*;
class ComplexMatrix {
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
	int n, m, K, x;
	int [][] matrix, total;


	void init() throws Exception {
		String temp [] = br.readLine().split(" ");
		n = Integer.parseInt(temp[0]); m = Integer.parseInt(temp[1]);
		K = Integer.parseInt(temp[2]); x = Integer.parseInt(temp[3]);
		matrix = new int[n][m];
		total = new int[n][m];
		for (int i = 0; i < n; i++) {
			temp = br.readLine().split(" ");
			for (int j = 0; j < m; j++) {
				matrix[i][j] = Integer.parseInt(temp[j]);
				if (matrix[i][j] == x)
					total[i][j] = 1;

				if (i - 1 >= 0) total[i][j] += total[i - 1][j];
				if (j - 1 >= 0) total[i][j] += total[i][j - 1];
				if (i - 1 >= 0 && j - 1 >= 0) total[i][j] -= total[i - 1][j - 1];
			}
		}
		compute();
	}
	void compute() {
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				for (int k = i + 1; k < n; k++) {
					for (int l = j + 1; l < m; l++) {
						int sum = 0;
						sum += total[k][l];
						if (i - 1 >= 0) sum -= total[i - 1][l];
						if (j - 1 >= 0) sum -= total[k][j - 1];
						if (i - 1 >= 0 && j - 1 >= 0) sum += total[i - 1][j - 1];

						if (sum < K) continue;

						if (matrix[i][j] == matrix[i][l]) cnt++;
						else if (matrix[i][j] == matrix[k][j]) cnt++;
						else if (matrix[i][j] == matrix[k][l]) cnt++;
						else if (matrix[i][l] == matrix[k][j]) cnt++;
						else if (matrix[i][l] == matrix[k][l]) cnt++;
						else if (matrix[k][l] == matrix[k][j]) cnt++;
						else continue;

					}
				}
			}
		}
		pr.println(cnt);
	}


	public static void main(String[] args) throws Exception {
		initL();
		ComplexMatrix c = new ComplexMatrix();
		c.init();
	}
}
