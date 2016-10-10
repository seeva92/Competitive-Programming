/*
Author : Shivakkumar K R
File name : 310_Div2_ProbB.cs
*/
using System;
using System.Collections;
using System.Linq;
using System.Text;
using System.IO;
public class _310_Div2_ProbB {
	static void Main(string [] args) {
		//Console.SetIn(new StreamReader(File.OpenRead("C://Users//Shiva//Desktop//310_Div2_ProbB.txt")));
		  var n = int.Parse(Console.ReadLine());
		var input = Console.ReadLine().Split(new char[] {' '});
		int [] arr = new int[n];
		arr[0] = int.Parse(input[0]);
		int diff = n - arr[0];
		for (int i = 1; i < n; i++) {
			arr[i] = int.Parse(input[i]);
			int temp;
			if ((i & 1) == 1)
				temp = n - diff;
			else
				temp = diff;
			temp %= n;
			arr[i] = arr[i] + temp;
			arr[i] = arr[i] % n;
			if (arr[i] != i) {
				Console.WriteLine("NO");
				return;
			}
		}

		Console.WriteLine("YES");
		// var n = int.Parse(Console.ReadLine());
		// var input = Console.ReadLine().Split(new char[] {' '});
		// int [,] arr = new int[n, n];
		// for (int i = 0; i < n; i++)
		// 	arr[0, i] = int.Parse(input[i]);

		// if (n == 1) {
		// 	Console.WriteLine("YES");
		// 	return;
		// }

		// for (int i = 1; i < n; i++) {
		// 	int prev = int.MinValue; bool flag = true;
		// 	for (int j = 0; j < n; j++) {
		// 		if (j % 2 == 0)
		// 			arr[i, j] = (arr[i - 1, j] + 1) % n;
		// 		else {
		// 			arr[i, j] = (arr[i - 1, j]) == 0 ? n - 1 : arr[i - 1, j] - 1;
		// 		}

		// 		if (flag && prev < arr[i - 1, j])
		// 			flag = true;
		// 		else {
		// 			flag = false;
		// 		}
		// 		prev = arr[i - 1, j];
		// 	}
		// 	if (flag) {
		// 		Console.WriteLine("YES"); return;
		// 	}
		// }

		// int previous = int.MinValue; bool flagship = true;
		// for (int j = 0; j < n; j++) {
		// 	if (flagship && previous < arr[n - 1, j])
		// 		flagship = true;
		// 	else {
		// 		flagship = false;
		// 	}
		// 	previous = arr[n - 1, j];
		// }

		// // for(int i=0;i<n;i++,Console.WriteLine())
		// // 	for(int j=0;j<n;j++)
		// // 		Console.Write(arr[i,j]);
		// if (flagship) {
		// 	Console.WriteLine("YES"); return;
		// }
		// Console.WriteLine("NO");
	}
}