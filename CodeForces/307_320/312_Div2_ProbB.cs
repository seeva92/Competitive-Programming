/*
Author : Shivakkumar K R
File name : 312_Div2_ProbB.cs
*/
using System;
using System.Collections;
using System.Linq;
using System.Text;
using System.IO;
public class _312_Div2_ProbB {
	static void Main(string [] args) {
		//Console.SetIn(new StreamReader(File.OpenRead("C://Users//Shiva//Desktop//312_Div2_ProbB.txt")));
		var n = int.Parse(Console.ReadLine());
		n = n + 1;
		int [] arr = new int[n];
		int [] left = new int[((int)1e6) + 2];
		int [] right = new int[((int)1e6) + 2];
		int [] count = new int[((int)1e6) + 2];
		int maxLength = left.Length;
		for (int i = 0; i < maxLength; i++) {
			count[i] = 0;
			left[i] = right[i] = -1;
		}
		var input = Console.ReadLine().Split(new char[] {' '});
		for (int i = 1; i < n; i++) {
			arr[i] = int.Parse(input[i-1]);
			if (left[arr[i]] == -1) {
				left[arr[i]] = i; right[arr[i]] = i;
			}
			else if (right[arr[i]] != -1) {
				right[arr[i]] = i;
			}
			count[arr[i]]++;
		}
		int maxCount = int.MinValue;
		for (int i = 1; i < n; i++) {
			if (maxCount < count[arr[i]])
				maxCount = count[arr[i]];
		}
		int minDistance = int.MaxValue;
		int minDistanceIndex=0;
		for (int i = 1; i < n; i++) {
			if (count[arr[i]] == maxCount && minDistance > (right[arr[i]] - left[arr[i]])) {
				minDistance = right[arr[i]] - left[arr[i]];
				minDistanceIndex = arr[i];
			}
		}

		Console.WriteLine(left[minDistanceIndex]+" "+right[minDistanceIndex]);
	}
}