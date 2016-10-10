using System;
using System.Collections;
using System.Collections.Generic;
using System.Text;
class TRY {
	const int size = 256;
	class Node {
		public Node [] child = new Node[size];
		public bool IsEnd;
	}
	public TRY() {
		head = new Node();
	}
	private Node head;
	private Node NewNode() {
		return new Node();
	}
	private void InsertHelper(Node root, string str) {
		if (root == null)
			return;

		foreach (var v in str) {
			if (root.child[(int)v] == null)
				root.child[(int)v] = NewNode();
			root = root.child[(int)v];
		}

		root.IsEnd = true;
	}
	public void Insert(string str) {
		if (str == null || str.Length <= 0)
			return;
		InsertHelper( head, str);
	}
	private void DisplayHelper(Node root, string str) {
		if (root == null)
			return;

		if (root.IsEnd) {
			Console.Write(str + " ");
		}
		for (int i = 0; i < size; i++) {
			if (root.child[i] != null)
				DisplayHelper(root.child[i], str + (char)i);
		}
	}
	public void Display() {
		DisplayHelper(head, "");
	}

	private bool SearchHelper(Node root, string str) {
		if (root == null)
			return false;
		foreach (var v in str) {
			if (root.child[(int)v] == null)
				return false;
			root = root.child[(int)v];
		}
		return root.IsEnd;

	}
	public bool Search(string str) {
		return SearchHelper(head, str);
	}
	private bool ContainsChildren(Node root) {
		for (int i = 0; i < size; i++)
			if (root.child[i] != null)
				return true;
		return false;
	}
	private bool DeleteHelper(ref Node root, int i, string str) {
		if (root == null)
			return false;
		if (i > str.Length)
			return false;
		if (i == str.Length && root.IsEnd) {
			root.IsEnd = false;
			if (!ContainsChildren(root))
				root = null; return true;
		}
		else if (DeleteHelper(ref root.child[(int)str[i]], i + 1, str)) {
			if (!ContainsChildren(root))
				root = null;
			return true;
		}
		return true;
	}
	public void Delete(string str) {
		DeleteHelper(ref head, 0, str);
	}
	static void Main() {
		string [] strarr = {"shiva", "sairaj", "ranju", "gokul", "ganesh", "ram", "rajkumar", "tamil", "anisha", "anjana"
		                    , "nantha", "nitheesh", "ravi", "saraswathy", "balaji", "vinoth", "prem", "sudarson", "sathya", "prakash", "mano",
		                    "jagadeesh", "santhosh", "jude", "sruthi"
		                   };
		var trie = new TRY();
		foreach (var str in strarr)
			trie.Insert(str);
		trie.Display();
		Console.WriteLine();
		foreach (var v in strarr)
			Console.Write(trie.Search(v) + " ");
		foreach (var str in strarr)
		{
			trie.Delete(str);
			Console.WriteLine();
			trie.Display();
		}

		// trie.Print();

	}
}