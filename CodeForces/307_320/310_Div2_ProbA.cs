/*
Author : Shivakkumar K R
File name : 310_Div2_ProbA.cs
*/
using System;
using System.Collections;
using System.Linq;
using System.Text;
using System.IO;
using System.Collections.Generic;
public class _310_Div2_ProbA {
	static void Main(string [] args) {
		//Console.SetIn(new StreamReader(File.OpenRead("C://Users//Shiva//Desktop//310_Div2_ProbA.txt")));
		var n = int.Parse(Console.ReadLine());
		var number = Console.ReadLine();
		var stack = new Stack<char>();
		foreach (var v in number)
		{
			if (stack.Count == 0)
				stack.Push(v);
			else {
				if ((stack.Peek() == '1' && v == '0') || (stack.Peek() == '0' && v == '1'))
				{
					stack.Pop(); continue;
				}
				else
					stack.Push(v);
			}
		}

		Console.WriteLine(stack.Count);
	}
}