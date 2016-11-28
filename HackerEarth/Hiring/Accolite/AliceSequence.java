import java.io.*;
import java.util.*;
class AliceSequence {
	static IO io;
	long dp [][][][];
	int T, N;
	final long mod = (long)1e9 + 7;
	public long compute(int N, int a, int b, int c) throws Exception {

		if (N == 0) {
			if (a == b && c == b) {
				// io.println(str);
				return 1;
			} else return 0;
		}
		if (dp[N][a][b][c] != -1) return dp[N][a][b][c];
		long temp = 0;

		temp = compute(N - 1,  1, b, c);
		temp = (temp + compute(N - 1, a, 1, c)) % mod;
		temp = (temp + compute(N - 1, a, b, 1)) % mod;

		return dp[N][a][b][c] = temp;
	}
	public void init(boolean flag) throws Exception {
		io = new IO(flag);
		dp = new long[1000007][2][2][2];
		for (int i = 0; i < dp.length; i++)
			for (int j = 0; j < dp[i].length; j++)
				for (int k = 0; k < dp[i][j].length; k++)
					for (int l = 0; l < dp[i][j][k].length; l++) dp[i][j][k][l] = -1;

		io.println(compute(10000,  0, 0, 0));
		// T = io.nextInt();
	}
	public static void main(String[] args) throws Exception {
		AliceSequence obj = new AliceSequence();
		obj.init(true);

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

