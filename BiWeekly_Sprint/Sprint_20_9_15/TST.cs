/*
Author : Shivakkumar K R
File name : TST.cs
*/
using System;
using System.Collections;
using System.Linq;
using System.Text;
public class TST {
	class Node {
		public char c;
		public Node Left, Right, Center;
		public bool IsEnd;
	}
	Node root;
	private Node NewNode(char c) {
		return new Node {
			c = c
		};
	}
	private void InsertHelper(ref Node temp, string data, int i) {
		if (temp == null)
			temp = NewNode(data[i]);

		if (data[i] < temp.c)
			InsertHelper(ref temp.Left, data, i);
		else if (data[i] > temp.c)
			InsertHelper(ref temp.Right, data, i);
		else {
			if (i + 1 == data.Length) {
				temp.IsEnd = true; return;
			}
			InsertHelper(ref temp.Center, data, i + 1);
		}
	}
	public void Insert(string data) {
		InsertHelper(ref root, data, 0);
	}

	private void DisplayHelper(Node temp, string data) {
		if (temp == null)
			return;

		DisplayHelper(temp.Left, data);
		if (temp.IsEnd) {
			Console.WriteLine(data + temp.c);
		}
		DisplayHelper(temp.Center, data + temp.c);
		DisplayHelper(temp.Right, data);
	}
	public void Display() {
		DisplayHelper(root, "");
	}

	private void DeleteHelper(ref Node temp, string data, int i) {
		if (temp == null)
			return;
		if (data[i] < temp.c)
			DeleteHelper(ref temp.Left, data, i);
		else if (data[i] > temp.c)
			DeleteHelper(ref temp.Right, data, i);
		else {
			if (i + 1 == data.Length) {
				temp.IsEnd = true;
				if (temp.Left == null && temp.Right == null && temp.Center == null)
					temp = null;
				return;
			}
			DeleteHelper(ref temp.Center, data, i + 1);
		}
	}
	public void Delete(string data) {
		DeleteHelper(ref root, data, 0);
	}
	static void Main(string [] args) {
		string [] strarr = {"shiva", "sairaj", "ranju", "gokul", "ganesh", "ram", "rajkumar", "tamil", "anisha", "anjana"
		                    , "nantha", "nitheesh", "ravi", "saraswathy", "balaji", "vinoth", "prem", "sudarson", "sathya", "prakash", "mano",
		                    "jagadeesh", "santhosh", "jude", "sruthi"
		                   };
		var tst = new TST();
		foreach (var str in strarr)
			tst.Insert(str);
		tst.Display();
		int i = 0;
		foreach (var str in strarr) {
			if (i == strarr.Length * 3/4)
				break;
			i++;
			tst.Delete(str);
		}
		tst.Display();

	}
}