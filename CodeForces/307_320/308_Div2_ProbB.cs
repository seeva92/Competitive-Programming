using System;
using System.IO;
class _308_Div2_ProbB {
	static void Main() {
//		Console.SetIn(new StreamReader(File.OpenRead("308_Div2_ProbB.txt")));
		int n = int.Parse(Console.ReadLine());
		long [] arr = new long[12];
		long [] digits = new long[12];
		int i;
		long power = 1;
		for (i = 1; i < 11; i++) {
			arr[i] = (power * 10) - 1;
			digits[i] += digits[i - 1] + ((arr[i] - arr[i - 1]) * i);
			power *= 10;
		}

		// for (i = 1; i < 11; i++)
		// {
		// 	Console.WriteLine(arr[i] + " " + digits[i]);
		// }
		if (n < 10) {
			Console.WriteLine(n); return;
		}

		for (i = 1; i < 11 && arr[i] < n; i++);
		i--;
		long diff = n - arr[i];
		long digitsCount = diff == 0 ? i : i + 1;
		long total = digitsCount * diff + (digits[i]);
		Console.WriteLine(total);




	}
}