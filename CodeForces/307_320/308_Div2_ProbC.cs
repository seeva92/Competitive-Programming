using System;
using System.IO;
class _308_Div2_ProbD {
	static bool solve(int w, int m) {
		return w <= 3 || m == 1 || trysolve(w, m - 1) || trysolve(w, m) || trysolve(w, m + 1);
	}

	static bool trysolve(int w, int m) {
		return m % w == 0 && solve(w, m / w);
	}
	static void Main() {
		//Console.SetIn(new StreamReader(File.OpenRead("308_Div2_ProbC.txt")));
		var input = Console.ReadLine().Split(new char[] {' '});
		int w = int.Parse(input[0]);
		int m = int.Parse(input[1]);

		bool flag = solve(w, m);
		if (flag)
			Console.WriteLine("YES");
		else
			Console.WriteLine("NO");


	}
}