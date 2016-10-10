/*
Author : Shivakkumar K R
File name : EggDropping.cs
*/
using System;
using System.Collections;
using System.Linq;
using System.Text;
public class EggDropping {
	static int EggDropRec(int n, int k) {
		if (k == 1 || k == 0)
			return k;
		if (n == 1)
			return k;


		int min = int.MaxValue,res;
		for (int i = 1; i <= k; i++) {
			res =  Math.Max(EggDropRec(n - 1, i - 1), EggDropRec(n, k - i));
			min = Math.Min(min,res);
		}
		return min+1;
	}
	static void Main(string [] args) {
		int n = 2, k = 10;
		Console.WriteLine(EggDropRec(n,k));
	}
}