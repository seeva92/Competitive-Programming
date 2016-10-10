/*
Author : Shivakkumar K R
File name : 314_Div2_ProbA.cs
*/
using System;
using System.Collections;
using System.Linq;
using System.Text;
using System.IO;
public class _314_Div2_ProbA {
	static void Main(string [] args) {
		//Console.SetIn(new StreamReader(File.OpenRead("C://Users//Shiva//Desktop//314_Div2_ProbA.txt")));
		int n = int.Parse(Console.ReadLine());
		var arr = new int[n];
		var input = Console.ReadLine().Split(new char[] {' '});
		for (int i = 0; i < n; i++) {
			arr[i] = int.Parse(input[i]);
		}
		int left = arr[0], right = arr[n - 1];
		int currMin = int.MaxValue;
		int currMax = int.MinValue;
		for (int i = 0; i < n; i++) {
			currMin = int.MaxValue;
			currMax = int.MinValue;
			if (i - 1 >= 0)
				currMin = Math.Min(currMin, Math.Abs(arr[i - 1] - arr[i]));
			if (i + 1 < n)
				currMin = Math.Min(currMin, Math.Abs(arr[i + 1] - arr[i]));

			if (left != arr[i])
				currMax = Math.Max(currMax, Math.Abs(left - arr[i]));
			if (right != arr[i])
				currMax = Math.Max(currMax, Math.Abs(right - arr[i]));
			Console.Write(currMin + " " + currMax + "\n");
		}
	}
}