using System;
using System.IO;
class _320_Div2_ProbA {
	public static void Main() {
		//Console.SetIn(new StreamReader(File.OpenRead("C://Users//sivak//Desktop//_320_Div2_ProbA.txt")));
		var x = int.Parse(Console.ReadLine());
		int sum = 0;
		while (x != 0) {
			sum += (x % 2);
			x /= 2;
		}
		Console.WriteLine(sum);
	}
}