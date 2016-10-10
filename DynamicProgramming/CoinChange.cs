/*
Author : Shivakkumar K R
File name : CoinChange.cs
*/
using System;
using System.Collections;
using System.Linq;
using System.Text;
public class CoinChange {
	static long CountWaysRec(int [] coins, int S, int n) {
		if (S == 0)
			return 1;
		if (S < 0)
			return 0;
		if (n == 0)
			return 0;

		return CountWaysRec(coins, S - coins[n - 1], n) + CountWaysRec(coins, S, n - 1);
	}

	static long [,] Mem;
	static void Init(int Size, int n) {
		Mem = new long[Size, n];
		for (int i = 0; i < Size; i++)
			for (int j = 0; j < n; j++)
				Mem[i, j] = -1;
	}
	static long CountWaysMem(int [] coins, int S, int n) {
		if (S == 0)
			return 1;
		if (S < 0)
			return 0;
		if (n == 0)
			return 0;
		if (Mem[S, n] != -1) {
			return Mem[S, n];
		}

		Mem[S, n] = CountWaysMem(coins, S - coins[n - 1], n) + CountWaysMem(coins, S, n - 1);
		return Mem[S, n];
	}
	static long CountWayDp(int [] coins , int S, int n) {
		long [,] Dp = new long[S + 1, n + 1];
		for (int i = 0; i <= n; i++)
			Dp[0, i] = 1;
		for (int i = 0; i <= S; i++)
			Dp[i, 0] = 0;

		for (int i = 1; i <= S; i++) {
			for (int j = 1; j <= n; j++) {
				if (i - coins[j - 1] >= 0)
					Dp[i, j] += Dp[i - coins[j - 1], j];
				Dp[i, j] += Dp[i, j - 1];
			}
		}
		return Dp[S, n];
	}

	static long CountWaysDpOptimized(int [] coins, int S, int n) {
		long [] Dp = new long[S + 1];
		Dp[0] = 1;
		for (int i = 0; i < n; i++) {
			for (int j = coins[i]; j <= S; j++) {
				Dp[j] += Dp[j - coins[i]];
			}
		}
		return Dp[S];
	}
	static void Main(string [] args) {
		int S = 100000;
		int [] coins = {1, 2, 3, 4, 5, 6};
		//Console.WriteLine(CountWaysRec(coins, S, coins.Length));
		Init(S + 1, coins.Length + 1); //int count = 0;
		//Console.WriteLine(CountWaysMem(coins, S, coins.Length));
		Console.WriteLine(CountWayDp(coins, S, coins.Length));
		Console.WriteLine(CountWaysDpOptimized(coins, S, coins.Length));

		//1 1 1 1
		// 2 2
		//3 1
		//1 1 2
		//

	}
}