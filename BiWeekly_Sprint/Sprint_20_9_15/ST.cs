/*
Author : Shivakkumar K R
File name : ST.cs
*/
using System;
using System.Collections;
using System.Linq;
using System.Text;
public class ST {
	int [] st;
	public ST(int size) {
		int height = (int)Math.Ceiling(Math.Log(size, 2));
		size = 2 * (int)Math.Pow(2, height) + 1;
		st = new int[size];
		Console.WriteLine(size);
	}
	private void Init() {
		for (int i = 0; i < st.Length; i++)
			st[i] = 0;
	}

	private int BuildHelper(int [] arr, int start, int end, int index) {
		if (start > end)
			return 0;

		if (start == end) {
			st[index] = arr[end];
			return st[index];
		}

		int mid = start + (end - start) / 2;
		st[index] = BuildHelper(arr, start, mid, 2 * index + 1) + BuildHelper(arr, mid + 1, end, 2 * index + 2);
		return st[index];
	}

	private int SumHelper(int [] arr, int l, int r, int start, int end, int index) {
		if (r < start || l > end)
			return 0;

		if (l <= start && end <= r) {
			return st[index];
		}

		int mid = start + (end - start) / 2;
		return SumHelper(arr, l, r, start, mid, 2 * index + 1) + SumHelper(arr, l, r, mid + 1, end, 2 * index + 2);

	}
	public int Sum(int [] arr, int l, int r) {
		return SumHelper(arr, l, r, 0, arr.Length - 1, 0);
	}
	public void Build(int [] arr) {
		Init();
		BuildHelper(arr, 0, arr.Length - 1, 0);
	}
	public void Print() {
		foreach (var val in st)
			Console.Write(val + " ");
		Console.WriteLine();
	}
	private void UpdateHelper(int [] arr, int i, int data, int start, int end, int index) {
		if (start > end)
			return;
		if (start == end) {
			st[index] += data;
			return;
		}
		int mid = start + (end - start) / 2;
		if (i <= mid)
			UpdateHelper(arr, i, data, start, mid, 2 * index + 1);
		else
			UpdateHelper(arr, i, data, mid + 1, end, 2 * index + 2);

		st[index] = st[2 * index + 1] + st[2 * index + 2];

	}
	public void Update(int [] arr, int i, int data) {
		UpdateHelper(arr, i, data, 0, arr.Length - 1, 0);
	}
	static void Main(string [] args) {
		var st = new ST(10);
		int [] a = {3, 6, 1, 7, 2, 8, 4, 9, 10};
		st.Build(a);
		st.Print();
		st.Update(a, 3, 2);
		st.Print();
		Console.Write(st.Sum(a, 0, 10));
	}
}