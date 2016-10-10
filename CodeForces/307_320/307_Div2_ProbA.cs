using System;
using System.IO;
using System.Collections.Generic;
using System.Collections;
class _307_Div2_ProbA {

	private class IntComparer: IComparer
	{
		int IComparer.Compare(object a, object b)
		{
			int c1 = (int)a;
			int c2 = (int)b;
			if (c1 < c2)
				return 1;
			if (c1 > c2)
				return -1;
			else
				return 0;
		}
	}
	static void Main() {
		//Console.SetIn(new StreamReader(File.OpenRead("307_Div2_ProbA.txt")));
		int n = int.Parse(Console.ReadLine());
		int [] arr = new int[n + 1];
		int [] pos = new int[n + 1];
		int [] rank = new int[n + 1];
		var input = Console.ReadLine().Split(new char[] {' '});
		int i;
		for (i = 1; i <= n; i++) {
			arr[i] = int.Parse(input[i - 1]);
			pos[i] = i;
		}
		var comparer = new IntComparer();
		Array.Sort(arr, pos, 1, n, comparer);
		// for (i = 1; i <= n; i++) {
		// 	Console.WriteLine(arr[i] + " " + pos[i]);
		// }

		for (i = 1; i <= n; i++) {
			if (arr[i] != arr[i - 1])
				rank[pos[i]] = i;
			else
				rank[pos[i]] = rank[pos[i - 1]];
		}

		for (i = 1; i <= n; i++)
			Console.Write(rank[i] + " ");
	}
}