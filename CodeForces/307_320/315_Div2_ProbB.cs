/*
Author : Shivakkumar K R
File name : 315_Div2_ProbB.cs
*/
using System;
using System.Collections;
using System.Linq;
using System.Text;
using System.IO;
public class _315_Div2_ProbB {
	static int FindNextZeroIndex(int []countArr, int start, int end) {
		int idx;
		for (idx = start; idx <= end; idx++)
			if (countArr[idx] == 0)
				break;
		if (start <= idx && idx <= end)
			return idx;
		return -1;
	}
	static void Main(string [] args) {
		Console.SetIn(new StreamReader(File.OpenRead("C://Users//Shiva//Desktop//315_Div2_ProbB.txt")));
		var n = int.Parse(Console.ReadLine());

		var input = Console.ReadLine().Split(new char[] {' '});
		var arr = new int[n];
		var countArr = new int[(int)1e5+1];
		var visitedArr = new bool[(int)1e5+1];
		for (int i = 0; i < n; i++) {
			arr[i] = int.Parse(input[i]);
			countArr[arr[i]]++;
		}

		//Find first element with count 0
		int idx = FindNextZeroIndex(countArr, 1, n);
		if (idx == -1) {
			for (int i = 0; i < n; i++)
				Console.Write(arr[i] + " "); return;
		}

		for (int i = 0; i < n; i++) {
			if (arr[i] <= n && !visitedArr[arr[i]]) {
				visitedArr[arr[i]] = true;
				if (countArr[arr[i]] > 1)
					countArr[arr[i]]--;
			} else {
				arr[i] = idx; visitedArr[idx] = true; countArr[arr[i]]++;
				idx = FindNextZeroIndex(countArr, idx + 1, n);
			}
		}

		for (int i = 0; i < n; i++)
			Console.Write(arr[i] + " "); return;
	}
}