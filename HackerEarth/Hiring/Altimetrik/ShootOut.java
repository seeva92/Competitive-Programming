import java.util.*;
import java.io.*;
class ShootOut {
	long x, y;
	static boolean onSegment(ShootOut p, ShootOut q, ShootOut r) {
		if (q.x <= Math.max(p.x, r.x) && q.x >= Math.min(p.x, r.x) &&
		        q.y <= Math.max(p.y, r.y) && q.y >= Math.min(p.y, r.y))
			return true;
		return false;
	}
	static long orientation(ShootOut p, ShootOut q, ShootOut r) {
		long val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
		if (val == 0) return 0;
		return (val > 0) ? 1 : 2;
	}
	static boolean doIntersect(ShootOut p1, ShootOut q1, ShootOut p2, ShootOut q2) {
		long o1 = orientation(p1, q1, p2);
		long o2 = orientation(p1, q1, q2);
		long o3 = orientation(p2, q2, p1);
		long o4 = orientation(p2, q2, q1);
		if (o1 != o2 && o3 != o4)
			return true;
		return false;
	}
	public static void main(String[] args) throws Exception {
		// System.setIn(new FileInputStream("/home/shiva/Learning/1.txt"));
		// System.setOut(new PrintStream("/home/shiva/Learning/2.txt"));
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int t = Integer.parseInt(br.readLine());
		while (t > 0) {
			ShootOut p1 = new ShootOut(), p2 = new ShootOut(), p3 = new ShootOut(), p4 = new ShootOut();
			long x, y;
			String line[] = br.readLine().split(" ");
			p1.x = Long.parseLong(line[0]); p1.y = Long.parseLong(line[1]);
			line = br.readLine().split(" ");
			p2.x = Long.parseLong(line[0]); p2.y = Long.parseLong(line[1]);
			line = br.readLine().split(" ");
			p3.x = Long.parseLong(line[0]); p3.y = Long.parseLong(line[1]);
			line = br.readLine().split(" ");
			p4.x = Long.parseLong(line[0]); p4.y = Long.parseLong(line[1]);
			if(doIntersect(p1,p2,p3,p4))
				System.out.println("No");
			else
				System.out.println("Yes");

			t--;

		}
	}
}
