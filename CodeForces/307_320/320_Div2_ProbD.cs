using System;
using System.IO;
using System.Collections.Generic;
using System.Collections;
using System.Globalization;
class _320_Div2_ProbD {
	public static void Main() {
		//Console.SetIn(new StreamReader(File.OpenRead("C://Users//sivak//Desktop//_320_Div2_ProbD.txt")));
		var input = Console.ReadLine().Split(new char[] {' '});
		int n = int.Parse(input[0]); int k = int.Parse(input[1]); int x = int.Parse(input[2]);
		long [] pre_arr = new long[n + 10];
		long [] suff_arr = new long[n + 10];
		long [] arr = new long[n + 10];
		input = Console.ReadLine().Split(new char[] {' '});

		long mul = 1;
		for (int i = k; i > 0; i--)
			mul *= x;
		for (int i = 1; i <= n; i++)
			arr[i] = long.Parse(input[i - 1]);

		for (int i = 1; i <= n; i++)
			pre_arr[i] = pre_arr[i - 1] | arr[i];

		for (int i = n; i >= 1; i--)
			suff_arr[i] = suff_arr[i + 1] | arr[i];

		long ans = 0;
		for (int i = 1; i <= n; i++)
			ans = Math.Max(ans, pre_arr[i - 1] | (arr[i] * mul) | suff_arr[i + 1]);

		Console.WriteLine(ans);
	}

}