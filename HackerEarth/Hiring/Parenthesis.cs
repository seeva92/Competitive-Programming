using System;
using System.Collections.Generic;
using System.Text;
class Program {
	public static void Main(string [] args) {
		int t = Int32.Parse(Console.ReadLine().Trim());
		// int t = 1;
		for (; t > 0; t--) {
			string str = Console.ReadLine().Trim();
			// string str = ")))())(()";
			var builder = new StringBuilder();
			builder.Append(str);
			int left = 0, right = 0;
			var stk = new Stack<char>();
			for (int i = 0; i < str.Length; i++) {
				if (str[i] == '(') stk.Push('(');
				else {
					if (stk.Count > 0 && stk.Peek() == '(')
						stk.Pop();
					else
						left++;
				}
			}
			right = stk.Count;
			for (int i = 0; i < left; i++) builder.Insert(0, '(');
			for (int i = 0; i < right; i++)builder.Append(')');

			Console.WriteLine(builder.ToString());
		}
	}
}