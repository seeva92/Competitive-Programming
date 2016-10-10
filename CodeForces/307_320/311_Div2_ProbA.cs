/*
Author : Shivakkumar K R
File name : 311_Div2_ProbA.cs
*/
using System;
using System.Collections;
using System.Linq;
using System.Text;
using System.IO;
public class _312_Div2_ProbA {
	static void Main(string [] args) {
		//Console.SetIn(new StreamReader(File.OpenRead("C://Users//Shiva//Desktop//311_Div2_ProbA.txt")));
		var n = int.Parse(Console.ReadLine());
		var input = Console.ReadLine().Split(new char[] {' '});
		var min1 = int.Parse(input[0]);
		var max1 = int.Parse(input[1]);
		input = Console.ReadLine().Split(new char[] {' '});
		var min2 = int.Parse(input[0]);
		var max2 = int.Parse(input[1]);
		input = Console.ReadLine().Split(new char[] {' '});
		var min3 = int.Parse(input[0]);
		var max3 = int.Parse(input[1]);

		int totalMinSum = min1 + min2 + min3;
		if (totalMinSum == n)
			Console.WriteLine(min1 + " " + min2 + " " + min3);
		else if (totalMinSum < n) {
			int diff = n - totalMinSum;
			if (diff > (max1 - min1)) {
				diff -= (max1 - min1);
				min1 += (max1 - min1);

			} else {
				min1 += diff;
				diff -= diff;

				if (diff == 0) {
					Console.WriteLine(min1 + " " + min2 + " " + min3); return;
				}
			}

			if (diff > (max2 - min2)) {
				diff -= (max2 - min2);
				min2 += (max2 - min2);

			} else {
				min2 += diff;
				diff -= diff;

				if (diff == 0) {
					Console.WriteLine(min1 + " " + min2 + " " + min3); return;
				}
			}

			if (diff > (max3 - min3)) {
				diff -= (max3 - min3);
				min3 += (max3 - min3);

			} else {
				min3 += diff;
				diff -= diff;
				if (diff == 0) {
					Console.WriteLine(min1 + " " + min2 + " " + min3); return;
				}
			}

			if (diff == 0) {
				Console.WriteLine(min1 + " " + min2 + " " + min3); return;
			}
		}
	}
}