/*
Author : Shivakkumar K R
File name : 314_Div2_ProbB.cs
*/
using System;
using System.Collections;
using System.Linq;
using System.Text;
using System.IO;
using System.Collections.Generic;
public class _314_Div2_ProbB {
	static void Main(string [] args) {
		//Console.SetIn(new StreamReader(File.OpenRead("C://Users//Shiva//Desktop//314_Div2_ProbB.txt")));
		int n = int.Parse(Console.ReadLine());
		long sum = 0;
		int min = 0;
		var regSet = new HashSet<int>();
		for (int i = 0; i < n; i++) {
			var input = Console.ReadLine().Split(new char[] {' '});
			if (input[0] == "+") {
				regSet.Add(int.Parse(input[1]));
				min = Math.Max(min, regSet.Count);
			}else{
				if(regSet.Contains(int.Parse(input[1])))
					regSet.Remove(int.Parse(input[1]));
				else {
					min++;
				}
			}
		}
		Console.WriteLine(min);
	}
}