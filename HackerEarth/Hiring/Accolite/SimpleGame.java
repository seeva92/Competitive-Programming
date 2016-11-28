import java.io.*;
import java.util.*;
class SimpleGame {
	static IO io;
	long [] A, B;
	int N, M;
	long Atot = 0, Btot = 0;
	public long upper_bound(long temp[], long val) {
		int start = 0, end = temp.length - 1, mid;
		long res = 0;
		while (start <= end) {
			mid = (start + end)  / 2;
			if (temp[mid] >= val) {
				res = mid;
				end = mid - 1;
			} else start = mid + 1 ;
		}
		if (temp[(int)res] == val) return res + 1;
		return res;
	}
	public void init(boolean flag) throws Exception {
		io = new IO(flag);
		N = io.nextInt(); M = io.nextInt();
		A = new long[N]; B = new long[M];
		for (int i = 0; i < N; i++) A[i] = io.nextLong();
		for (int i = 0; i < M; i++) B[i] = io.nextLong();
		Arrays.sort(A); Arrays.sort(B);
		long a, b;
		for (int i = 0; i < N; i++) {

			a = upper_bound(B, A[i] - 1); if (a == M) a -= M;
			b = M - upper_bound(B, A[i]);
			// io.println(A[i] + " " + a + " " + b );
			Atot += (a * b);
		}
		for (int i = 0; i < M; i++) {
			a = upper_bound(A, B[i] - 1); if (a == N) a -= N;
			b = N - upper_bound(A, B[i]);
			// io.println(B[i] + " " + a + " " + b );
			Btot += (a * b);

		}
		// io.println( Atot << " " << Btot << "\n";
		if (Atot == Btot) io.println("Tie");
		else if (Atot > Btot) io.println( "Monk" + " " + (Atot - Btot));
		else io.println( "!Monk" + " " + (Btot - Atot));
	}
	public static void main(String[] args) throws Exception {
		SimpleGame s = new SimpleGame();
		s.init(true);
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

