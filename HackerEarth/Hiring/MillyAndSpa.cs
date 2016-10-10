using System;
using System.Collections.Generic;
using System.Text;
using System.IO;
class Program {
	public static void Main(string [] args) {
		// Console.SetIn(new StreamReader(File.OpenRead("E:/Shiva backup/Shiva/Learning/Learning/UVA/1.txt")));
		double s = 4.20;
		Console.WriteLine(Math.Round(s,2));
		// int t = Int32.Parse(Console.ReadLine().Trim());
		// for (; t > 0; t--) {
		// 	string str = Console.ReadLine().Trim();
		// 	string [] weight = Console.ReadLine().Split(new char[] {' '});
		// 	int [] wt = new int[26];
		// 	for (int i = 0; i < 26; i++) wt[i] = int.Parse(weight[i]);
		// 	int [] count = new int[26];
		// 	for (int i = 0; i < str.Length; i++)
		// 		count[str[i] - 'a']++;
		// 	double uniq = 0;

		// 	for (int i = 0; i < 26; i++) if (count[i] > 0) uniq += wt[i];
		// 	Console.WriteLine(uniq);
		// 	double result = 0;
		// 	//Summing up
		// 	for (int i = 0; i < 26; i++) result += 10 * count[i] * wt[i];
		// 	Console.WriteLine(result);
		// 	Console.WriteLine(str.Length * uniq);
		// 	Console.WriteLine(Math.Round(result / (str.Length * uniq), 2));
		// }
	}
}