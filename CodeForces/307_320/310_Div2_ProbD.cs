/*
Author : Shivakkumar K R
File name : 310_Div2_ProbD.cs
*/
using System;
using System.Collections;
using System.Linq;
using System.Text;
using System.IO;
public class _310_Div2_ProbD {
	static void LowerBound(long [] a, bool [] bridgeFlag, int start, int end, long l, long r, ref int pos) {
		if (start > end)
			return;
		int mid;
		while (start <= end) {
			mid = start + (end - start) / 2;
			if (l <= a[mid] && a[mid] <= r) {
				if (!bridgeFlag[mid])
					pos = mid;
				end = mid - 1;
			} else if (r < a[mid]) {
				end = mid - 1;
			} else if (l > a[mid]) {
				start = mid + 1;
			}
		}
	}
	static void Main(string [] args) {
		Console.SetIn(new StreamReader(File.OpenRead("C://Users//Shiva//Desktop//310_Div2_ProbD.txt")));
		var input = Console.ReadLine().Split(new char[] {' '});
		int n = int.Parse(input[0]);
		int m = int.Parse(input[1]);
		long [] l, r, min, max, bridge;
		l = new long[n+1];  r = new long[n+1];
		min = new long[n + 1];
		max = new long[n + 1];
		bridge = new long[m];
		l[0] = 0;
		r[0] = 0;
		int [] bridgeIndex = new int[n + 1];
		bridgeIndex[0] = -1;
		for (int i = 1; i <= n; i++) {
			input = Console.ReadLine().Split(new char[] {' '});
			l[i] = long.Parse(input[0]);
			r[i] = long.Parse(input[1]);
			min[i] = Math.Min(r[i] - r[i - 1], Math.Min(r[i] - l[i - 1], Math.Min(l[i] - l[i - 1], l[i] - r[i - 1])));
			max[i] = Math.Max(r[i] - r[i - 1], Math.Max(r[i] - l[i - 1], Math.Max(l[i] - l[i - 1], l[i] - r[i - 1])));
			bridgeIndex[i] = -1;
			Console.WriteLine(min[i]+" "+max[i]);
		}
		input = Console.ReadLine().Split(new char[] {' '});
		bool [] bridgeFlag = new bool[m];
		for (int i = 0; i < m; i++) {
			bridge[i] = int.Parse(input[i]);
			bridgeFlag[i] = false;
		}

		Array.Sort(bridge);
		if (m < (n - 1))
		{
			Console.WriteLine("NO"); return;
		}

		int pos = -1;
		for (int i = 2; i <= n; i++) {
			pos = -1;
			LowerBound(bridge, bridgeFlag, 0, bridge.Length - 1, min[i], max[i], ref pos);
			bridgeIndex[i - 2] = pos;
			Console.WriteLine(pos);
			if (pos == -1)
			{
				Console.WriteLine("NO"); return;
			}
			bridgeFlag[pos] = true;
		}

		Console.WriteLine("YES");
		for (int i = 0; i <= n && bridgeIndex[i] != -1; i++) {
			Console.Write(bridgeIndex[i] + " ");
		}

	}
}