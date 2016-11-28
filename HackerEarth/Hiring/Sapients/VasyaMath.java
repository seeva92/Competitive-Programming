import java.io.*;
import java.util.*;
class VasyaMath {
	static IO io;
	int T, N, L, R;
	long arr[];
	final long mod = (long)1e9 + 7;
	int sieve[] = new int[10000021];
	long primes[] = new long[10050];
	int pIdx = 0;
	long vals[];
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
	public long modexp(long a, long b) {
		long res = 1;
		while (b > 0) {
			if ((b & 1) > 0) res = (res * a) % mod;
			a = (a * a) % mod;
		}
		return res;
	}
	public void init(boolean flag) throws Exception {
		io = new IO(flag);
		processprimes();
		N = io.nextInt();
		vals = new long[N];
		arr = new long[N];
		for (int i = 0; i < N; i++)  {
			arr[i] = io.nextInt();
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
			vals[i] = arr[i];
			if (i > 0) vals[i] = (vals[i] * vals[i - 1]) % mod;
		}
		// for (int i = 0; i < N; i++) pr.println(vals[i]);
		T = io.nextInt();
		for (int i = 0; i < T; i++) {
			L = io.nextInt() - 1; R = io.nextInt() - 1;
			if (L - 1 >= 0) {
				io.println((vals[R] * modexp(vals[L - 1], mod - 2)) % mod);
			} else {
				io.println(vals[R]);
			}
		}
	}
	public static void main(String[] args) throws Exception {
		new VasyaMath().init(true);
		if (io != null)
			io.close();
	}
	static class IO {
		final private int BUFFER_SIZE = 1 << 16;
		private BufferedInputStream din;
		private BufferedWriter bw;
		private byte[] buffer;
		private int bufferPointer, bytesRead;
		public IO(boolean flag) throws Exception {
			if (flag) {
				din = new BufferedInputStream(new FileInputStream("/Users/seeva92/Workspace/Contests/1.txt"));
				bw = new BufferedWriter(new OutputStreamWriter(new FileOutputStream("/Users/seeva92/Workspace/Contests/2.txt")));
			} else {
				din = new BufferedInputStream(System.in);
				bw = new BufferedWriter(new OutputStreamWriter(System.out));
			}
			buffer = new byte[BUFFER_SIZE];
			bufferPointer = bytesRead = 0;
		}
		public void print(Object object)throws IOException {
			bw.append("" + object);
		}
		public void println(Object object)throws IOException {
			bw.append(object + "\n");
		}
		public String readLine() throws IOException {
			byte[] buf = new byte[64]; // line length
			int cnt = 0, c;
			while ((c = read()) != -1) {
				if (c == '\n')
					break;
				buf[cnt++] = (byte) c;
			}
			return new String(buf, 0, cnt);
		}
		public int nextInt() throws IOException {
			int ret = 0;
			byte c = read();
			while (c <= ' ')
				c = read();
			boolean neg = (c == '-');
			if (neg)
				c = read();
			do {
				ret = ret * 10 + c - '0';
			}  while ((c = read()) >= '0' && c <= '9');

			if (neg)
				return -ret;
			return ret;
		}
		public long nextLong() throws IOException {
			long ret = 0;
			byte c = read();
			while (c <= ' ')
				c = read();
			boolean neg = (c == '-');
			if (neg)
				c = read();
			do {
				ret = ret * 10 + c - '0';
			} while ((c = read()) >= '0' && c <= '9');
			if (neg)
				return -ret;
			return ret;
		}
		public double nextDouble() throws IOException {
			double ret = 0, div = 1;
			byte c = read();
			while (c <= ' ')
				c = read();
			boolean neg = (c == '-');
			if (neg)
				c = read();

			do {
				ret = ret * 10 + c - '0';
			} while ((c = read()) >= '0' && c <= '9');

			if (c == '.') {
				while ((c = read()) >= '0' && c <= '9') {
					ret += (c - '0') / (div *= 10);
				}
			}
			if (neg)
				return -ret;
			return ret;
		}
		private void fillBuffer() throws IOException {
			bytesRead = din.read(buffer, bufferPointer = 0, BUFFER_SIZE);
			if (bytesRead == -1)
				buffer[0] = -1;
		}
		private byte read() throws IOException {
			if (bufferPointer == bytesRead)
				fillBuffer();
			return buffer[bufferPointer++];
		}
		public void close() throws IOException {
			if (din == null)
				return;
			din.close();
			bw.close();
		}
	}
}

