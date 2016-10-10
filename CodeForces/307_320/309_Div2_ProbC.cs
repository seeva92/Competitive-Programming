using System;
using System.IO;
class _309_Div2_ProbC {

	static void Main(string[] args) {
		//Console.SetIn(new StreamReader(File.OpenRead("309_Div2_ProbC.txt")));
		int n = int.Parse(Console.ReadLine());
		// string str = "haa";
		int [] arr = new int[n + 1];
		int i, j;
		for (i = 1; i <= n; i++)
			arr[i] = int.Parse(Console.ReadLine());

		long [,] binomial = new long[1010, 1010];
		binomial[0, 0] = 1;
		for (i = 0; i < binomial.GetLength(0); i++)
			binomial[i, 0] = 1;

		long mod = 1000000007;

		//Populate Binomial Values
		for (i = 1 ; i < binomial.GetLength(0); i++)
			for (j = 1; j < binomial.GetLength(1); j++)
				binomial[i, j] = (binomial[i - 1, j - 1] + binomial[i - 1, j]) % mod;


		long result = 1;
		long sum = 0;
		for (i = 1; i <= n; i++) {

			result = (result * binomial[sum + arr[i] - 1, arr[i] - 1]) % mod;
			sum += arr[i];
		}

		Console.WriteLine(result);	
	}
}