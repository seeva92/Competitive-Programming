/*
Author : Shivakkumar K R
File name : BIT.cs
*/
using System;
using System.Collections;
using System.Linq;
using System.Text;
public class BIT {
	int [] bit;
	public BIT(int size) {
		bit = new int[size + 2];
	}
	public BIT() {
		bit = new int[(int)1e5];
	}
	public void Build(int [] arr) {
		for (int i = 0; i < arr.Length; i++)
			Update(i, arr[i]);
	}
	public void Update(int index, int data) {
		index++;
		int len = bit.Length;
		while (index < len) {
			bit[index] += data;
			index += -index & index;
		}
	}
	public long Sum(int index) {
		index++;
		long total = 0;
		while (index > 0) {
			total += bit[index];
			index -= -index & index;
		}
		return total;
	}
	public long Sum(int start, int end) {
		return Sum(end) - Sum(start - 1);
	}
	public void Print() {
		foreach (var item in bit)
			Console.Write(item + " ");
	}
	static void Main(string [] args) {
		int [] a = {3, 6, 1, 7, 2, 8, 4, 9, 10};
		var bit = new BIT(a.Length);
		bit.Build(a);
		bit.Print();
		Console.WriteLine(bit.Sum(a.Length - 1));
		bit.Update(3, 2);
		Console.WriteLine(bit.Sum(1, 3));
	}
}