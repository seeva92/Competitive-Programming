/*
Author : Shivakkumar K R
File name : BinomialCoefficient.cs
*/
using System;
using System.Collections;
using System.Linq;
using System.Text;
public class BinomialCoefficient {
	static int BinomialCalc(int n, int k) {
		if (k == 0)
			return 1;
		if (n == k)
			return 1;

		return BinomialCalc(n - 1, k - 1) + BinomialCalc(n - 1, k);
	}

	static double [,] mem;
	static void Init(int n, int k) {
		mem = new double[n + 1, k + 1];
		for (int i = 0; i < mem.GetLength(0); i++)
			for (int j = 0; j < mem.GetLength(1); j++)
				mem[i, j] = -1;
	}

	static double BinomialCalcMem(int n, int k) {
		if (k == 0)
			return 1;
		if (n == k)
			return 1;

		if (mem[n, k] != -1)
			return mem[n, k];
		mem[n, k] = BinomialCalcMem(n - 1, k - 1) + BinomialCalcMem(n - 1, k);
		return mem[n, k];
	}

	static double BinomialCalcDp(int n, int k) {
		if (k == 0)
			return 1;
		if (n == k)
			return 1;

		double [,] dp = new double[n + 1, k + 1];

		dp[0, 0] = 1;

		for (int i = 1; i <= n; i++) {
			dp[i, 0] = 1;
			for (int j = 1; j <= k; j++)
				dp[i, j] = dp[i - 1,j - 1] + dp[i - 1, j];
		}
		return dp[n, k];
	}
	static void Main(string [] args) {
		int n = 500, k = 15;
		Init(n, k);
		Console.WriteLine(BinomialCalcMem(n, k).ToString());
		Console.WriteLine(BinomialCalcDp(n, k).ToString());

	}
}