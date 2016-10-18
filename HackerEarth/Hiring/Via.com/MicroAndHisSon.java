import java.io.*;
import java.util.*;
class MicroAndHisSon {
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
	int T;
	int [] prep = new int[1445];

	public void preprocess() {
		String temp;
		for (int i = 0; i < 24; i++)
			for (int j = 0; j < 60; j++) {
				temp = String.format("%02d%02d", i, j);
				if ((temp.charAt(0) == temp.charAt(3)) && (temp.charAt(1) == temp.charAt(2))) {
					prep[i * 60 + j] = 1;
				}
			}
		for (int i = 1; i < prep.length; i++) prep[i] += prep[i - 1];
	}
	public int compute(String from, String to) {
		int c = 0;
		String temp;
		int is = Integer.parseInt(from.substring(0, 2)), ie = Integer.parseInt(from.substring(2, 4));
		int js = Integer.parseInt(to.substring(0, 2)), je = Integer.parseInt(to.substring(2, 4));
		c = prep[js * 60 + je];
		if (((is * 60) + ie) - 1 >= 0 ) c -= prep[((is * 60) + ie) - 1];
		return c;
	}
	public void init() throws Exception {
		MicroAndHisSon m = new MicroAndHisSon();
		m.preprocess();
		T = Integer.parseInt(br.readLine());

		for (int i = 0; i < T; i++) {
			String [] temp = br.readLine().split(" ");
			pr.println(m.compute(temp[0], temp[1]));
		}
	}
	public static void main(String[] args) throws Exception {
		initI();
		new MicroAndHisSon().init();


	}
}