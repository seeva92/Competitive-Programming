using System;
using System.IO;
class _308_Div2_ProbA {
	static void Main() {
		//Console.SetIn(new StreamReader(File.OpenRead("308_Div2_ProbA.txt")));
		int n = int.Parse(Console.ReadLine());
		int [,] arr = new int[101, 101];
		int x1, y1, x2, y2;
		for (int i = 0 ; i < n; i++) {
			var input = Console.ReadLine().Split(new char[] {' '});
			x1 = int.Parse(input[0]);
			y1 = int.Parse(input[1]);
			x2 = int.Parse(input[2]);
			y2 = int.Parse(input[3]);


			for (int j = x1; j <= x2; j++)
				for (int k = y1; k <= y2; k++)
					arr[j, k] += 1;
		}

		long total = 0;
		for (int i = 0; i < 101; i++)
			for (int j = 0; j < 101; j++)
				total += arr[i, j];
		Console.WriteLine(total);
	}
}