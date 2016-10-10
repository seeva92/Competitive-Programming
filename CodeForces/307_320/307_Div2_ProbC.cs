using System;
using System.IO;
using System.Collections.Generic;
using System.Collections;
using System.Text;
class _307_Div2_ProbB {

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
		Console.SetIn(new StreamReader(File.OpenRead("307_Div2_ProbC.txt")));
		var input = Console.ReadLine().Split(new char[] {' '});
		int n = int.Parse(input[0]);
		int m = int.Parse(input[1]);
		input = Console.ReadLine().Split(new char[] {' '});
		int [] arr = new int[n + 1];
		int i;
		for (i = 1; i <= n; i++)
			arr[i] = int.Parse(input[i - 1]);

		long seconds = 1;
		for (i = 1; i <= n; i++) {
			if (m > arr[i])
				seconds += 1;
			else if (m < arr[i])
				seconds += ((arr[i] / m) + 1);
			else
				seconds += (arr[i] / m);

			if (i != n)
				seconds += 1;

		}

		Console.WriteLine(seconds);
	}
}