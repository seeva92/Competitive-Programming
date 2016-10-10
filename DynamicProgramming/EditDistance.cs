/*
Author : Shivakkumar K R
File name : EditDistance.cs
*/
using System;
using System.Collections;
using System.Linq;
using System.Text;
public class EditDistance {

	static int CalculateEditRec (string str1, string str2, int n, int m) {

		if (m == 0 && n == 0)
			return 0;
		if (n == 0)
			return m;
		if (m == 0)
			return n;

		return Math.Min(CalculateEditRec(str1, str2, n - 1, m) + 1,
		                Math.Min(CalculateEditRec(str1, str2, n, m - 1) + 1, CalculateEditRec(str1, str2, n - 1, m - 1) + (str1[n - 1] == str2[m - 1] ? 0 : 1)));
	}

	static int [,] mem = new int[100, 100];
	static void Init() {
		for (int i = 0; i < mem.GetLength(0); i++)
		{
			for (int j = 0; j < mem.GetLength(1); j++) {
				mem[i, j] = -1;
			}
		}
	}
	static int CalculateEditMem(string str1, string str2, int n, int m) {
		if (m == 0 && n == 0)
			return 0;
		if (n == 0)
			return m;
		if (m == 0)
			return n;
		if (mem[n, m] != -1)
			return mem[n, m];

		mem[n, m] = Math.Min(Math.Min(CalculateEditMem(str1, str2, n - 1, m) + 1,
		                              CalculateEditMem(str1, str2, n, m - 1) + 1),
		                     CalculateEditMem(str1, str2, n - 1, m - 1) + (str1[n - 1] == str2[m - 1] ? 0 : 1));

		return mem[n, m];
	}

	static int CalculateEditDp(string str1, string str2, int n, int m ) {
		int [,] dp = new int[n + 2, m + 2];

		for (int j = 0; j < dp.GetLength(1); j++)
			dp[0,j] = j;

		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++) {
				dp[i, j] = Math.Min(Math.Min(dp[i - 1, j] + 1, dp[i,j - 1] + 1), dp[i - 1, j - 1] + (str1[i - 1] == str2[j - 1] ? 0 : 1));
			}
		}
		return dp[n,m];
	}
	static void Main(string [] args) { 
		string str1 = "XYZAASJHUAKSD";
		string str2 = "SIVARANJANIXCMMAKLASDIIVMASDL";
		Init();
		// Console.WriteLine(CalculateEditRec(str1, str2, str1.Length - 1, str2.Length - 1));
		Console.WriteLine(CalculateEditMem(str1, str2, str1.Length , str2.Length ));
		str1 = "akldjsfkjhasdkjfh";
		str2 = "mnzxcvuuoaszcxvnaasdjfkjwkejrbnxdiu";
		Init();
		Console.WriteLine(CalculateEditMem(str1, str2, str1.Length , str2.Length));
		Console.WriteLine(CalculateEditDp(str1,str2,str1.Length,str2.Length));

	}
}