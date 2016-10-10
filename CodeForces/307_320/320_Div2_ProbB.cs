using System;
using System.IO;
using System.Collections.Generic;
using System.Collections;
class _320_Div2_ProbB {
	public static void Main() {
		//Console.SetIn(new StreamReader(File.OpenRead("C://Users//sivak//Desktop//_320_Div2_ProbB.txt")));
		var n = int.Parse(Console.ReadLine());
		int [,] arr = new int[2 * n + 1, 2 * n + 1];
		int temp = 2 * n;
		int i, j;
		for (i = 2; i <= temp; i++) {
			var input = Console.ReadLine().Split(new char[] {' '});
			for (j = 1; j <= (i - 1); j++) {
				arr[i, j] = int.Parse(input[j - 1]);
			}
		}
		// 	for( i=2;i<=temp;i++,Console.WriteLine())
		// 		for(j=1;j<=(i-1);j++)
		// 			Console.Write(arr[i,j]);
		//

		int [] flag = new int[2 * n + 1];
		for (i = 0; i < flag.Length; i++)
			flag[i] = 0;
		int k;
		var list = new List<int>();
		for (k = 1; k <= n; k++)
		{
			int max = int.MinValue;
			int one = 0, two = 0;
			for (i = 2; i <= temp; i++) {
				for (j = 1; j <= (i - 1); j++) {
					if (flag[i] == 0 && flag[j] == 0 && max < arr[i, j])
					{
						max = arr[i, j];
						one = i; two = j;
					}
				}
			}
			if (one != two) {
				flag[one] = two; flag[two] =  one;

			}

		}

		for (i = 1; i <= temp; i++)
			Console.Write(flag[i] + " ");
	}
}