/*
Author : Shivakkumar K R
File name : 313_Div2_ProbB.cs
*/
using System;
using System.Collections;
using System.Linq;
using System.Text;
using System.IO;
public class _313_Div2_ProbB {
	static int max(int a, int b)
	{
		return Math.Max(a, b);
	}
	static void swap<T>(ref T a, ref T b) {
		T c = a;
		a = b;
		b = c;
	}
	static void Main(string [] args) {
		//Console.SetIn(new StreamReader(File.OpenRead("C://Users//Shiva//Desktop//313_Div2_ProbB.txt")));
		var input = Console.ReadLine().Split(new char[] {});
		int a = int.Parse(input[0]), b = int.Parse(input[1]);
		input = Console.ReadLine().Split(new char[] {});
		int c = int.Parse(input[0]), d = int.Parse(input[1]);
		input = Console.ReadLine().Split(new char[] {});
		int e = int.Parse(input[0]), f = int.Parse(input[1]);

		for (int i = 0; i < 4; i++) {
			if ((a >= (c + e) && b >= d && b >= f) || (b >= (d + f) && a >= c && a >= e)) {
				Console.WriteLine("YES"); return;
			}
			if (i % 2 == 0) swap(ref c, ref d);
			swap(ref e, ref f);
		}

		Console.WriteLine("NO");
	}
}
