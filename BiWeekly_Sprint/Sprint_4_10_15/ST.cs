using System;
using System.Collections;
using System.Collections.Generic;
using System.Text;
class ST {
	int [] st;
	int startIndex, endIndex;
	ST(int [] arr) {
		int size = 2 * (int)Math.Ceiling(Math.Pow(2, Math.Ceiling(Math.Log(arr.Length, 2)))) + 1;
		Console.WriteLine(size);
		st = new int[size];
		startIndex = 0;
		endIndex = arr.Length - 1;
		BuildST(arr, startIndex, endIndex, 0);
	}

	private void BuildST(int [] arr, int start, int end, int index) {
		if (start > end)
			return;

		if (start == end) {
			st[index] = arr[start];
			return;
		}

		int mid = start + (end - start) / 2;

		BuildST(arr, start, mid, 2 * index + 1);
		BuildST(arr, mid + 1, end, 2 * index + 2);
		st[index] = st[2 * index + 1] + st[2 * index + 2];
	}

	private void UpdateHelper(int data, int pos, int start, int end, int index) {
		if (pos < start || pos > end)
			return;
		if (start > end)
			return;

		if (start == end) {
			st[index] = data;
			return;
		}
		int mid =  start + (end - start) / 2;
		if (pos <= mid)
			UpdateHelper(data, pos, start, mid, 2 * index + 1);
		else
			UpdateHelper(data, pos, mid + 1, end, 2 * index + 2);
		st[index] = st[2 * index + 1] + st[2 * index + 2];
	}
	public void Update(int pos, int data) {
		UpdateHelper(data, pos, startIndex, endIndex, 0);
	}

	private long SumHelper(int l, int r, int start, int end, int index) {
		if (start > end)
			return 0;
		if (r < start || l > end)
			return 0;
		if (l <= start && end <= r) {
			return st[index];
		}

		int mid = start + (end - start) / 2;
		long lh = SumHelper(l, r, start, mid, 2 * index + 1);
		long rh = SumHelper(l, r, mid + 1, end, 2 * index + 1);
		return lh + rh;
	}
	public long Sum(int l, int r) {
		return SumHelper(l, r, startIndex, endIndex, 0);
	}
	public void Display() {
		foreach (var v in st)
			Console.Write(v + " ");
	}
	static void Main() {
		Console.WriteLine("I love you");
		int [] arr = {4, 6, 1, 8, 3, 2, 9, 0, 5, 7};
		var st = new ST(arr);
		st.Display();
		st.Update(7, 10);
		Console.WriteLine();
		st.Display();
		st.Update(0, 10);
		st.Update(9, 10);
		Console.WriteLine();
		st.Display();
		Console.Write(st.Sum(100,100));
	}
}