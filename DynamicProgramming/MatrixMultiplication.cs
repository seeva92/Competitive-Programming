/*
Author : Shivakkumar K R
File name : MatrixMultiplication.cs
*/
using System;
using System.Collections;
using System.Linq;
using System.Text;
public class MatrixMultiplication {
	static int CountOperationsRec(int [] matrixSizes, int start, int end) {
		if (start == end)
			return 0;
		int min = int.MaxValue;
		for (int i = start; i < end; i++) {
			int count = CountOperationsRec(matrixSizes, start, i) +
			            CountOperationsRec(matrixSizes, i + 1, end) +
			            matrixSizes[start - 1] * matrixSizes[i] * matrixSizes[end];
			min = Math.Min(min, count);
		}
		return min;
	}

	static int[,] Mem;
	static void Init(int Size) {
		//iter = 0;
		Mem = new int[Size + 1, Size + 1];
		for (int i = 0; i < Mem.GetLength(0); i++)
			for (int j = 0; j < Mem.GetLength(1); j++)
				Mem[i, j] = -1;
	}
	// static int iter = 0,func =0;
	static int CountOperationsMem(int [] matrixSizes, int start, int end) {
		//func++;
		if (start == end)
			return 0;
		if (Mem[start, end] != -1) {
			// iter++;
			//Console.WriteLine(iter);
			return Mem[start, end];
		}
		int min = int.MaxValue;
		for (int i = start; i < end; i++) {
			int count = CountOperationsMem(matrixSizes, start, i) +
			            CountOperationsMem(matrixSizes, i + 1, end) +
			            matrixSizes[start - 1] * matrixSizes[i] * matrixSizes[end];
			min = Math.Min(min, count);
		}
		Mem[start, end] = min;
		return min;
	}

	static int CountOperationsDp(int [] matrixSizes) {
		if (matrixSizes.Length == 0)
			return 0;

		int n = matrixSizes.Length;
		int [,] Dp = new int[matrixSizes.Length + 1, matrixSizes.Length + 1];
		int L,i,j,k;

		for (i = 1; i < n; i++)
			Dp[i, i] = 0;

		Dp[0, 0] = 0;
		// for (int L = 2; L < n; L++) {
		// 	for (int i = 1; i <= n - L + 1; i++) {
		// 		int j = i + L - 1;

		// 		Dp[i, j] = int.MaxValue;
		// 		for (int k = i; k <= j - 1; k++) {
		// 			int count = Dp[i, k] + Dp[k + 1, j] + matrixSizes[i - 1] * matrixSizes[k] * matrixSizes[j];
		// 			Dp[i, j] = Math.Min(Dp[i, j], count);
		// 		}
		// 	}
		// }
		for (L = 2; L < n; L++)
		{
			for (i = 1; i < n - L + 1; i++)
			{
				j = i + L - 1;
				Dp[i, j] = int.MaxValue;
				for (k = i; k <= j - 1; k++)
				{
					// q = cost/scalar multiplications
					int count = Dp[i, k] + Dp[k + 1, j] + matrixSizes[i - 1] * matrixSizes[k] * matrixSizes[j];
					Dp[i, j] = Math.Min(Dp[i, j], count);
				}
			}
		}

		return Dp[1,n-1];
	}
	static void Main(string [] args) {
		int [] matrixSizes = {1, 2, 3, 4, 3, 5, 7, 6, 2, 8, 9, 11, 15, 16};
		Console.WriteLine(CountOperationsRec(matrixSizes, 1, matrixSizes.Length - 1));
		Init(matrixSizes.Length);
		Console.WriteLine(CountOperationsMem(matrixSizes, 1, matrixSizes.Length - 1));
		Console.WriteLine(CountOperationsDp(matrixSizes));

		// Console.WriteLine(func);

	}

}