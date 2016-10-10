using System;
using System.Collections.Generic;
class _309_Div2_ProbA {
	static void Main(string[] args) {
		string str = Console.ReadLine();

		var hashset = new HashSet<string>();
		for (int i = 0; i <= str.Length; i++)
			for (char c = 'a'; c <= 'z'; c++) {
				hashset.Add(str.Substring(0, i) + c + str.Substring(i));
			}
		Console.WriteLine(hashset.Count);
	}
}