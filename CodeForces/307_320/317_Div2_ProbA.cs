/*
Author : Shivakkumar K R
File name : 315_Div2_ProbA.cs
*/
using System;
using System.Collections;
using System.Linq;
using System.Text;
using System.IO;
public class _315_Div2_ProbA {
	static void Main(string [] args) {
		//Console.SetIn(new StreamReader(File.OpenRead("C://Users//Shiva//Desktop//317_Div2_ProbA.txt")));
		var input = Console.ReadLine().Split(new char [] {' '});
		var T = int.Parse(input[0]);
		var S = int.Parse(input[1]);
		var q = int.Parse(input[2]);
		if (q > S) {
			Console.WriteLine(1);
		} else {
			Console.WriteLine(2);
		}
	}
}