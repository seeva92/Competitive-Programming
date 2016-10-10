using System;
using System.Collections.Generic;
using System.IO;
class _309_Div2_ProbB {

	
	static void Main(string[] args) {
		//Console.SetIn(new StreamReader(File.OpenRead("309_Div2_ProbB.txt")));
		int n = int.Parse(Console.ReadLine());
		// Console.WriteLine(n);
		int max = 0;
		var arr = new string[n];
		for (int i = 0; i < n; i++)
			arr[i] = Console.ReadLine();

		var map = new Dictionary<string, int>();
		for (int i = 0; i < n; i++)
		{
			if (map.ContainsKey(arr[i]))
				map[arr[i]]=map[arr[i]]+1;
			else
				map[arr[i]] = 1;

			max = Math.Max(max, map[arr[i]]);
		}
		Console.WriteLine(max);
	}
}
