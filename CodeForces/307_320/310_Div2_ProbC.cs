/*
Author : Shivakkumar K R
File name : 310_Div2_ProbC.cs
*/
using System;
using System.Collections;
using System.Linq;
using System.Text;
using System.IO;
public class Program {
	static void Main(string [] args) {
		//Console.SetIn(new StreamReader(File.OpenRead("C://Users//Shiva//Desktop//310_Div2_ProbC.txt")));
		var input = Console.ReadLine().Split(new char[] {' '});
		var n = int.Parse(input[0]);
		var k = int.Parse(input[1]);
		int count = 0;
		for (int i = 0; i < k; i++) {
			input = Console.ReadLine().Split(new char[] {' '});
			int m = int.Parse(input[0]);
			for (int j = 1; j <= m; j++)
				if (j == int.Parse(input[j]))
					count++;

		}
		Console.WriteLine(2 * n - 2 * count - k + 1);
	}
}