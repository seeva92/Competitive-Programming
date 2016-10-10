using System;
using System.Collections;
using System.Collections.Generic;
using System.Text;
class BIT {
	int [] bit;
	BIT(int [] arr) {
		bit = new int[arr.Length + 1];
		BuildBIT(arr);
	}
	private void BuildBIT(int [] arr) {
		for (int i = 0; i < arr.Length; i++) {
			int temp = i + 1;
			while (temp < bit.Length) {
				bit[temp] += arr[i];
				temp += temp & -temp;
			}
		}
	}

	public void Update(int data, int i) {
		if (i < 0 || (i + 1) >= bit.Length)
			return;
		i = i + 1;
		while (i < bit.Length) {
			bit[i] += data;
			i += i & -i;
		}
	}

	public long Sum(int i) {
		if (i < 0 || (i + 1) >= bit.Length)
			return 0;
		i++;
		long total = 0;
		while (i > 0) {
			total += bit[i];
			i -= i & -i;
		}
		return total;
	}
	public void Display() {
		foreach (var v in bit)
			Console.Write(v + " ");
	}
	static void Main() {
		Console.WriteLine("I love you");
		int [] arr = {4, 6, 1, 8, 3, 2, 9, 0, 5, 7};
		var bit = new BIT(arr);
		bit.Display();
		Console.WriteLine();
		for (int i = 0; i < arr.Length; i++)
			Console.Write(bit.Sum(i) + " ");
		bit.Update(10, 7);
		Console.WriteLine();
		for (int i = 0; i < arr.Length; i++)
			Console.Write(bit.Sum(i) + " ");
		Console.Write(bit.Sum(1) - bit.Sum(0));
	}
}