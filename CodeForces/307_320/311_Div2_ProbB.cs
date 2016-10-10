/*
Author : Shivakkumar K R
File name : 311_Div2_ProbB.cs
*/
using System;
using System.Collections;
using System.IO;
using System.Linq;
using System.Text;
using System.Globalization;
public class _311_Div2_ProbB {
	static void Main(string [] args) {
		//Console.SetIn(new StreamReader(File.OpenRead("C://Users//Shiva//Desktop//311_Div2_ProbB.txt")));
		var input = Console.ReadLine().Split(new char[] {' '});
		var n =  int.Parse(input[0]);
		var w = double.Parse(input[1]);
		double [] arr = new double[2 * n];
		input = Console.ReadLine().Split(new char[] {' '});

		double min = double.MaxValue;
		double max = double.MinValue;
		for (int i = 0; i < (2 * n); i++)
			arr[i] = double.Parse(input[i]);

		Array.Sort(arr);
		min = arr[0];
		max = arr[n];
		double total = 0.0;
		if ((max / 2) <= min)
			total = Math.Max(total, (max / 2) * n + (max * n));
		else {
			total = min*n+(2*min)*n;
		}
		total = Math.Min(w, total);
		Console.WriteLine(total.ToString(CultureInfo.InvariantCulture));
	}
}

