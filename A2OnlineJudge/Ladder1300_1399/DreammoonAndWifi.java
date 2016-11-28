import java.io.*;
import java.util.*;
public final class DreammoonAndWifi {
	static IO io;
	String a, b;
	int blen, place = 0, tote = 0, curre = 0;
	void compute(int p, int c) {
		if (p == blen) {
			if (c == place) {
				tote++; curre++;
			} else tote++;
			return;
		}
		if (b.charAt(p) == '+') compute(p + 1, c + 1);
		else if (b.charAt(p) == '-') compute(p + 1, c - 1);
		else {
			compute(p + 1, c + 1);
			compute(p + 1, c - 1);
		}
	}
	public void init(boolean flag) throws Exception {
		io = new IO(flag);
		a = io.readLine();
		b = io.readLine();
		blen = b.length();
		for (char c : a.toCharArray()) {
			if (c == '+') place++;
			else place--;
		}
		compute(0, 0);
		if (tote > 0) {
			io.println(String.format("%.15f\n", (double)curre / (double)tote));
		} else io.println(String.format("%.15f\n", (double)0));

	}
	public static void main(String[] args) throws Exception {
		new DreammoonAndWifi().init(false);

		if (io != null)
			io.close();
	}
	static class IO {
		final private int BUFFER_SIZE = 1 << 32;
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
			byte[] buf = new byte[1024]; // line length
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

