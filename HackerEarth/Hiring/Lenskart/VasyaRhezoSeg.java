import java.io.*;
import java.util.*;
class VasyaRhezoSeg {
	int N, Q, X, Y, Val;
	int [] A, B, Seg;
	static IO io;
	public int comp(int lf, int rf) {
		if (A[lf] < A[rf]) return rf;
		else if (A[lf] > A[rf]) return lf;
		else {
			if (B[lf] < B[rf]) return lf;
			else if (B[lf] > B[rf]) return rf;
		}
		return  Math.min(lf, rf);
	}
	public void build(int i, int j, int idx) {
		if (i == j) {
			Seg[idx] = i; return;
		}
		build(i, (i + j) / 2, (idx << 1));
		build((i + j) / 2 + 1, j, (idx << 1) + 1);
		int lf = Seg[(idx << 1)], rf = Seg[(idx << 1) + 1];
		Seg[idx] = comp(lf, rf);
	}
	public int query(int i, int j, int idx, int l, int r) {
		if (i > j || r < i || l > j) return 0;
		if (l <= i && j <= r) return Seg[idx];

		return comp(query(i, (i + j) / 2, (idx << 1), l, r), query((i + j) / 2 + 1, j, (idx << 1) + 1, l, r));
	}
	public void init(boolean flag) throws Exception {
		io = new IO(flag);
		N = io.nextInt();
		A = new int[N + 1]; B = new int[N + 1]; Seg = new int[4 * N];

		for (int i = 1; i <= N; i++) A[i] = io.nextInt();
		for (int i = 1; i <= N; i++) B[i] = io.nextInt();
		build(1, N, 1);

		Q = io.nextInt();
		for (int i = 1; i <= Q; i++) {
			X = io.nextInt(); Y = io.nextInt();
			io.println(query(1, N, 1, X, Y));
		}
		io.close();
	}

	public static void main(String[] args) throws Exception {
		VasyaRhezo c = new VasyaRhezo();
		c.init(true);
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
			// print();
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
