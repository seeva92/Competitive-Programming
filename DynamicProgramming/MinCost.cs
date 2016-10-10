/*
Author : Shivakkumar K R
File name : MinCost.cs
*/
using System;
using System.Collections;
using System.Linq;
using System.Text;
public static class MinCost {

	static long GetMinDistance(long [,] path, int n, int m) {
		if (n < 0 || m < 0)
			return int.MaxValue;
		if (n == 0 && m == 0)
			return path[n, m];
		else {
			long diagonal = GetMinDistance(path, n - 1, m - 1);
			long left = GetMinDistance(path, n, m - 1);
			long up = GetMinDistance(path, n - 1, m);
			//Console.WriteLine(diagonal + " " + left + " " + up);
			long x = path[n, m] + Math.Min(Math.Min(diagonal, left) , up );
			//Console.WriteLine(x);
			return x;
		}

	}
	static long[,] pathMem;

	static void Init(int n, int m) {
		pathMem = new long[n + 2, m + 2];
		for (int i = 0; i < pathMem.GetLength(0); i++)
			for (int j = 0; j < pathMem.GetLength(1); j++)
				pathMem[i, j] = -1;
	}

	static long GetMinDistanceMem(long [,] path, int n, int m) {
		if (n < 0 || m < 0)
			return int.MaxValue;
		if (n == 0 && m == 0)
			return path[n, m];
		else {

			if (pathMem[n, m] != -1)
				return pathMem[n, m];
			long diagonal = GetMinDistance(path, n - 1, m - 1);
			long left = GetMinDistance(path, n, m - 1);
			long up = GetMinDistance(path, n - 1, m);
			//Console.WriteLine(diagonal + " " + left + " " + up);
			pathMem[n, m] = path[n, m] + Math.Min(Math.Min(diagonal, left) , up );
			//Console.WriteLine(x);
			return pathMem[n, m];
		}

	}

	static long GetMinDistanceDp (long [,] path, int n, int m) {

		long [,] dp = (long [,])path.Clone();
		for (int i = 1; i < dp.GetLength(1); i++)
			dp[0, i] += dp[0, i - 1];
		for (int i = 1; i < dp.GetLength(0); i++)
			dp[i, 0] += dp[i - 1, 0];

		for (int i = 1; i < dp.GetLength(0); i++)
			for (int j = 1; j < dp.GetLength(1); j++)
				dp[i, j] = dp[i, j] + Math.Min(Math.Min(dp[i - 1, j - 1], dp[i - 1, j]), dp[i, j - 1]);

		return dp[dp.GetLength(0) - 1, dp.GetLength(1) - 1];
	}
	static void Main(string [] args) {
		Int64 [,] pathDistance = {
			{1, 2, 3}, {4, 8, 2}, {1, 5, 3}
		};
		for (int i = 0; i < pathDistance.GetLength(0); i++)
		{
			for (int j = 0; j < pathDistance.GetLength(1); j++)
				Console.Write(pathDistance[i, j] + " ");
			Console.WriteLine();
		}
		Console.WriteLine(GetMinDistance(pathDistance, pathDistance.GetLength(0) - 1, pathDistance.GetLength(1) - 1));
		Init(pathDistance.GetLength(0), pathDistance.GetLength(1));
		Console.WriteLine(GetMinDistanceMem(pathDistance, pathDistance.GetLength(0) - 1, pathDistance.GetLength(1) - 1));
		Console.WriteLine(GetMinDistanceDp(pathDistance, pathDistance.GetLength(0) - 1, pathDistance.GetLength(1) - 1));

	}
}