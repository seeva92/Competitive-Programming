import java.io.*;
import java.util.*;
import java.math.*;
class VasyaMath {
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
	int T, N, L, R;
	long arr[];
	final BigInteger mod = new BigInteger(Long.toString((long)1e9 + 7));
	int sieve[] = new int[10000021];
	long primes[] = new long[10050];
	int pIdx = 0;
	BigInteger vals[];
	public void processprimes() {
		int len = (int)Math.sqrt(10000007);
		sieve[1] = 1;
		for (int i = 2; i <= len; i++)
			if (sieve[i] == 0) {
				for (int j = i * 2; j * j <= 10000021; j += i) {
					sieve[j] = 1;
				}
				primes[pIdx++] = (long)i;
			}
	}

	public void init() throws Exception {
		processprimes();
		N = Integer.parseInt(br.readLine());
		vals = new BigInteger[N];
		arr = new long[N];
		String [] temp = br.readLine().split(" ");
		for (int i = 0; i < N; i++)  {
			arr[i] = Integer.parseInt(temp[i]);
			if (arr[i] % 2 == 0) arr[i] = arr[i] / 2;
			else if (sieve[(int)arr[i]] == 0) {
				arr[i] = 1;
			} else {
				for (int j = 0; j < pIdx; j++) {
					if (arr[i] % primes[j] == 0) {
						arr[i] = arr[i] / primes[j]; break;
					}
				}
			}
			vals[i] = new BigInteger(Long.toString(arr[i]));
			if (i > 0)vals[i] = vals[i].multiply(vals[i - 1]);
		}
		// for (int i = 0; i < N; i++) pr.println(vals[i]);
		T = Integer.parseInt(br.readLine());
		for (int i = 0; i < T; i++) {
			temp = br.readLine().split(" ");
			L = Integer.parseInt(temp[0]) - 1; R = Integer.parseInt(temp[1]) - 1;
			BigInteger bib[];
			if (L - 1 >= 0) {
				bib = vals[R].divideAndRemainder(vals[L - 1]);
				pr.println(bib[0].mod(mod));
			} else {
				pr.println(vals[R].mod(mod));
			}
		}
	}
	public static void main(String[] args) throws Exception {
		initL();
		new VasyaMath().init();
	}
}