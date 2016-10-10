/*
Author : Shivakkumar K R
File name : TRY.cs
*/
using System;
using System.Collections;
using System.Linq;
using System.Text;
public class TRY {
	const int Size = 256;
	class Node {
		public Node[] children;
		public bool isEnd;
		public Node() {
			children = new Node[Size];
		}
	}
	private Node root;
	public TRY() {
		root = new Node();
	}
	public void Insert(string data) {
		Node temp = root;
		for (int i = 0; i < data.Length; i++) {
			if (temp.children[(int)data[i]] == null)
				temp.children[(int)data[i]] = new Node();
			temp = temp.children[(int)data[i]];
		}
		temp.isEnd = true;
	}
	public bool Search(string data) {
		Node temp = root;
		for (int i = 0; i < data.Length; i++) {
			if (temp.children[(int)data[i]] == null)
				return false;
			temp = temp.children[(int)data[i]];
		}
		return temp.isEnd;
	}
	private bool ContainsChildren(Node temp) {
		if (temp == null)
			return false;
		for (int i = 0; i < Size; i++)
			if (temp.children[i] != null )
				return true;
		return false;
	}
	private void PrintHelper(Node temp, string str, ref int count) {
		if (temp == null)
			return;
		if (temp.isEnd) {
			count++;
			Console.WriteLine(str);
		}
		for (int i = 0; i < Size; i++) {
			if (temp.children[i] != null)
				PrintHelper(temp.children[i], str + (char)i, ref count);
		}
	}
	public void Print() {
		int count = 0;
		PrintHelper(root, "", ref count);
		Console.WriteLine(count);
	}
	private bool DeleteHelper(ref Node temp, string data, int i) {
		if (temp != null) {

			if (i > data.Length)
				return false;
			if (i == data.Length && temp.isEnd) {
				temp.isEnd = false;
				if (!ContainsChildren(temp)) {
					temp = null;
					return true;
				}
				return false;
			} else if (DeleteHelper(ref temp.children[(int)data[i]], data, i + 1)) {
				if (!ContainsChildren(temp)) {
					temp = null;
					return true;
				}
				return false;
			}
		}
		return false;
	}
	public void Delete(string data) {
		DeleteHelper(ref root, data, 0);
	}
	static void Main(string [] args) {
		string [] strarr = {"shiva", "sairaj", "ranju", "gokul", "ganesh", "ram", "rajkumar", "tamil", "anisha", "anjana"
		                    , "nantha", "nitheesh", "ravi", "saraswathy", "balaji", "vinoth", "prem", "sudarson", "sathya", "prakash", "mano",
		                    "jagadeesh", "santhosh", "jude", "sruthi"
		                   };
		var trie = new TRY();
		foreach (var str in strarr)
			trie.Insert(str);
		trie.Print();
		foreach (var str in strarr)
			Console.WriteLine(trie.Search(str));
		foreach (var str in strarr)
			trie.Delete(str);
		trie.Print();


	}
}