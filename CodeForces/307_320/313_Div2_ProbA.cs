/*
Author : Shivakkumar K R
File name : 313_Div2_ProbA.cs
*/
using System;
using System.Collections;
using System.Linq;
using System.Text;
using System.IO;
public class _313_Div2_ProbA {
	static void Main(string [] args) {
		//Console.SetIn(new StreamReader(File.OpenRead("C://Users//Shiva//Desktop//313_Div2_ProbA.txt")));
		var n = int.Parse(Console.ReadLine());
		var arr = new int[n];
		var input = Console.ReadLine().Split(new char[] {' '});
		for (int i = 0; i < n; i++)
			arr[i] = int.Parse(input[i]);
		Array.Sort(arr);

		if (arr[0] > 1)
			Console.WriteLine(1);
		else {
			Console.WriteLine(-1);
		}
	}
}