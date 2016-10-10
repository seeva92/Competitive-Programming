/*
Author : Shivakkumar K R
File name : 316_Div2_ProbB.cs
*/
using System;
using System.Collections;
using System.Linq;
using System.Text;
using System.IO;
public class _316_Div2_ProbB {
	static void Main(string [] args) {
		//Console.SetIn(new StreamReader(File.OpenRead("C://Users//Shiva//Desktop//316_Div2_ProbB.txt")));
		var input = Console.ReadLine().Split(new char[] {' '});
		var n = int.Parse(input[0]);
		var m = int.Parse(input[1]);
		if (n == 1)
			Console.WriteLine(1);
		else if (m - 1 < n - m)
			Console.WriteLine(m + 1);
		else {
			Console.WriteLine(m - 1);
		}
	}
}