/*
Author : Shivakkumar K R
File name : KnapSack.cs
*/
using System;
using System.Collections;
using System.Linq;
using System.Text;
public class KnapSack {
	static int KnapSackRec(int [] wt, int [] val, int W, int n) {
		if (n == 0 || W == 0)
			return 0;
		if (wt[n - 1] > W)
			return KnapSackRec(wt, val, W, n - 1);
		else
			return Math.Max(KnapSackRec(wt, val, W, n - 1), val[n - 1] + KnapSackRec(wt, val, W - wt[n - 1], n - 1) );
	}

	static int [,] mem;
	static void Init(int W, int n) {
		mem = new int[W + 1, n + 1];
		for (int i = 0; i <= W; i++)
			for (int j = 0; j <= n; j++)
				mem[i, j] = -1;
	}
	static int KnapSackMem(int [] wt, int [] val, int W, int n) {
		if (n == 0 || W == 0)
			return 0;
		if (mem[W, n] != -1)
			return mem[W, n];
		if (wt[n - 1] > W)
			return KnapSackRec(wt, val, W, n - 1);


		mem[W, n] = Math.Max(KnapSackRec(wt, val, W, n - 1), val[n - 1] + KnapSackRec(wt, val, W - wt[n - 1], n - 1) );
		return mem[W, n];
	}

	static void KnapSackDp(int []wt, int []val, int W) {
		int [,] dp = new int[W + 1, wt.Length + 1];
		for (int i = 0; i < dp.GetLength(1); i++)
			dp[0, i] = 0;
		for (int i = 0; i < dp.GetLength(0); i++)
			dp[i, 0] = 0;

		for (int i = 1; i < dp.GetLength(0); i++) {
			for (int j = 1; j < dp.GetLength(1); j++) {
				if (wt[j - 1] > i)
					dp[i, j] = dp[i, j - 1];
				else {

					dp[i, j] = Math.Max(dp[i, j - 1], val[j - 1] + dp[i - wt[j - 1], j - 1]);
				}
			}
		}
		Console.WriteLine(dp[W, wt.Length]);
	}
	static void Main(string [] args) {
		int[] values = {60, 100, 120};
		int []weights = {10, 20, 30};
		Console.WriteLine(KnapSackRec(weights, values, 50, 3));
		Init(50, 3);
		Console.WriteLine(KnapSackMem(weights, values, 50, 3));
		KnapSackDp(weights, values, 50);


	}
}