using System;
class _309_Div2_ProbA {
	static void Main(string[] args) {
		string str = Console.ReadLine();
		int [] arr = new int[26];
		foreach (var c in str) {
			arr[c - 'a']++;
		}

		int count = 26;
		foreach (var c in arr) {
			if (c > 0)
				count += 25;
		}
		Console.WriteLine(count);
	}
}