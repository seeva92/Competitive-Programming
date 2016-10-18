import java.io.*;
import java.util.*;
class VasyaRhezo {
	int N, Q, L, R, Val, K;
	int [] A, B;
	int [][] Spt;
	static FileOutputStream fout;
	static PrintWriter pr;
	static IO io;
	static void initIO(boolean flag) throws Exception {
		io = new IO(flag);
		if (flag) {
			fout = new FileOutputStream("/Users/seeva92/Workspace/Contests/2.txt");
			pr = new PrintWriter(fout, true);
		} else {
			pr = new PrintWriter(new OutputStreamWriter(System.out), true);
		}
	}
	public void init(boolean flag) throws Exception {
		initIO(flag);
		N = io.nextInt();
		// int M = (int)Math.floor(Math.log(N + 3) / Math.log(2));
		A = new int[N]; B = new int[N];
		Spt = new int[N + 1][31 - Integer.numberOfLeadingZeros(N + 3) + 1];

		for (int i = 0; i < N; i++) { A[i] = io.nextInt(); Spt[i][0] = i; }
		for (int i = 0; i < N; i++) B[i] = io.nextInt();
		for (int j = 1; (1 << j) <= N; j++) {
			for (int i = 0; (i + (1 << j) - 1) < N; i++) {
				if (A[Spt[i][j - 1]] == A[Spt[i + (1 << (j - 1))][j - 1]]) {
					if (B[Spt[i][j - 1]] == B[Spt[i + (1 << (j - 1))][j - 1]]) {
						if (Spt[i][j - 1] < Spt[i + (1 << (j - 1))][j - 1]) Spt[i][j] = Spt[i][j - 1];
						else Spt[i][j] = Spt[i + (1 << (j - 1))][j - 1];
					} else if (B[Spt[i][j - 1]] < B[Spt[i + (1 << (j - 1))][j - 1]]) Spt[i][j] = Spt[i][j - 1];
					else  Spt[i][j] = Spt[i + (1 << (j - 1))][j - 1];
				} else if (A[Spt[i][j - 1]] > A[Spt[i + (1 << (j - 1))][j - 1]]) Spt[i][j] = Spt[i][j - 1];
				else Spt[i][j] = Spt[i + (1 << (j - 1))][j - 1];
			}
		}

		Q = io.nextInt();
		for (int i = 0; i < Q; i++) {
			L = io.nextInt() - 1; R = io.nextInt() - 1;
			K = 31 - Integer.numberOfLeadingZeros(R - L + 1);
			if (A[Spt[L][K]] == A[Spt[R - (1 << K) + 1][K]]) {
				if (B[Spt[L][K]] == B[Spt[R - (1 << K) + 1][K]]) {
					if (Spt[L][K] < Spt[R - (1 << K) + 1][K]) io.println(Spt[L][K] + 1);
					else io.println(Spt[R - (1 << K) + 1][K] + 1);
				} else if (B[Spt[L][K]] < B[Spt[R - (1 << K) + 1][K]]) io.println(Spt[L][K] + 1);
				else  io.println(Spt[R - (1 << K) + 1][K] + 1);
			} else if (A[Spt[L][K]] > A[Spt[R - (1 << K) + 1][K]]) io.println(Spt[L][K] + 1);
			else io.println(Spt[R - (1 << K) + 1][K] + 1);
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