/*
Author : Shivakkumar K R
File name : 312_Div2_ProbA.cs
*/
using System;
using System.Collections;
using System.Linq;
using System.Text;
using System.IO;
public class _312_Div2_ProbA {

	static void Main(string [] args) {
		//Console.SetIn(new StreamReader(File.OpenRead("C://Users//Shiva//Desktop//312_Div2_ProbA.txt")));
		var n = int.Parse(Console.ReadLine());
		var pos = new int[n];
		var count = new int[n];
		long max = 0;
		int negative = 0, positive = 0;
		for (int i = 0; i < n; i++) {
			var input = Console.ReadLine().Split(new char[] {' '});
			pos[i] = int.Parse(input[0]);
			count[i] = int.Parse(input[1]);
			if (pos[i] < 0)
				negative++;
			else
				positive++;
			max += count[i];
		}
		Array.Sort(pos, count);
		if (positive == negative)
			Console.WriteLine(max);
		else if (negative > positive) {
			if (positive == 0)
			{
				Console.WriteLine(count[n-1]); return;
			}
			for (int i = 0; i < (negative - positive - 1) && i < n; i++)
				max -= count[i];
			Console.WriteLine(max);
		}
		else {
			if (negative == 0)
			{
				Console.WriteLine(count[0]); return;
			}

			for (int i = n - 1; i >= (n - (positive - negative - 1)) && i >= 0; i--)
				max -= count[i];
			Console.WriteLine(max);
		}
	}
}