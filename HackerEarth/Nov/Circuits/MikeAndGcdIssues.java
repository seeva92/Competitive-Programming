import java.io.*;
import java.util.*;
class MikeAndGcdIssues {
	static IO io;
	boolean bs[];
	final int MAX = (int)2e5 + 7;
	int primes[], pIdx = 0, N;
	int arr[], ans[];

	ArrayList<ArrayList<Integer>> G = new ArrayList<ArrayList<Integer>>(MAX);
	public void sieve() throws Exception {
		bs[0] = bs[1] = false;
		for (int i = 2; i * i <= MAX; i++)
			if (bs[i]) {
				for (int j = i * i; j <= MAX; j += i) bs[j] = false;
			}
		for (int i = 0; i <= MAX; i++) {
			G.add(new ArrayList<Integer>());
			if (bs[i] == true) {
				primes[pIdx++] = i;
			}
		}
	}
	void compute() throws Exception {
		ArrayList<Integer> temp; int len, prev;
		for (int i = 0; i < pIdx; i++) {
			temp = G.get(primes[i]); len = temp.size();
			if (len == 0) continue;
			// io.print(temp.get(0) + " ");
			for (int j = 1; j < len - 1; j++) {
				// io.print(temp.get(j) + " ");
				int c = temp.get(j);
				if (Math.abs(c - ans[c]) > Math.abs(c - temp.get(j - 1)))
					ans[c] = temp.get(j - 1);
				if (Math.abs(c - ans[c]) > Math.abs(c - temp.get(j + 1)))
					ans[c] = temp.get(j + 1);
			}
			// io.print(temp.get(len - 1) + " ");
			if (1 < len && Math.abs(ans[temp.get(0)] - temp.get(0)) > Math.abs(temp.get(1) - temp.get(0))) ans[temp.get(0)] = temp.get(1);
			if (len - 2 >= 0 && Math.abs(ans[temp.get(len - 1)] - temp.get(len - 1)) > Math.abs(temp.get(len - 1) - temp.get(len - 2)))  ans[temp.get(len - 1)] = temp.get(len - 2);
			// io.println("");
		}


	}
	public void init(boolean flag) throws Exception {
		io = new IO(flag);
		N = io.nextInt();
		arr = new int[N + 7]; ans = new int[N + 7];
		bs = new boolean[MAX + 7];
		primes = new int[MAX + 7];
		Arrays.fill(bs, true);
		Arrays.fill(ans, MAX);
		sieve();
		int temp;
		for (int i = 1; i <= N; i++) {
			arr[i] = io.nextInt();
			if (bs[arr[i]]) {
				G.get(arr[i]).add(i); continue;
			}
			temp = arr[i]; int sqtmp = (int)Math.sqrt(temp);
			for (int j = 0; j < pIdx && primes[j] <= sqtmp; j++) {
				if (temp % primes[j] == 0) {
					G.get(primes[j]).add(i);
					while ((temp % primes[j]) == 0) {
						temp /= primes[j];
					}
				}
			}
			if (temp != 1) G.get(temp).add(i);
		}
		compute();
		for (int i = 1; i <= N; i++) {
			if (ans[i] != MAX) io.print(ans[i] + " ");
			else io.print("-1 ");
		}
	}
	public static void main(String[] args) throws Exception {
		new MikeAndGcdIssues().init(true);

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
		public long nextInteger() throws IOException {
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

