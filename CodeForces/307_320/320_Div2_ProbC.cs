using System;
using System.IO;
using System.Collections.Generic;
using System.Collections;
using System.Globalization;
class _320_Div2_ProbC {
	public static void Main() {
		//Console.SetIn(new StreamReader(File.OpenRead("C://Users//sivak//Desktop//_320_Div2_ProbC.txt")));
		var input = Console.ReadLine().Split(new char[] {' '});
		double a = double.Parse(input[0]); double b = double.Parse(input[1]);
		if (a < b)
			Console.WriteLine(-1);
		else {
			double d2 = (double)(a + b) / (2 * (int)((double)(a + b) / (2 * b)));
			Console.WriteLine(d2.ToString(CultureInfo.InvariantCulture));
		}
	}

}