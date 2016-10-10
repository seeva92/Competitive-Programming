using System;
using System.Collections;
using System.Collections.Generic;
using System.Text;
class TST {
	const int size = 256;
	class Node {
		public char c;
		public Node left, right, center;
		public bool IsEnd;
	}
	public TST() {
		head = new Node();
	}
	private Node head;
	private Node NewNode(char data) {
		return new Node{c = data};
	}
	private void InsertHelper(ref Node root, int i, string str) {
		if (root == null)
			root = NewNode(str[i]);

		if (str[i] < root.c)
			InsertHelper(ref root.left, i, str);
		else if (str[i] > root.c)
			InsertHelper(ref root.right, i, str);
		else {
			if (i + 1 == str.Length)
			{
				root.IsEnd = true;
				return;
			}
			InsertHelper(ref root.center, i + 1, str);
		}
	}
	public void Insert(string str) {
		if (str == null || str.Length <= 0)
			return;
		InsertHelper(ref head,0, str);
	}
	private void DisplayHelper(Node root, string str) {
		if (root == null)
			return;

		DisplayHelper(root.left, str);
		if (root.IsEnd) {
			Console.Write(str + root.c + " ");
		}
		DisplayHelper(root.center, str + root.c);
		DisplayHelper(root.right, str);

	}
	public void Display() {
		DisplayHelper(head, "");
	}

	private bool ContainsChildren(Node root) {
		if (root == null)
			return true;
		return root.left == null && root.right == null && root.center == null;
	}
	// private bool DeleteHelper(ref Node root, int i, string str) {
	// 	if (root == null)
	// 		return false;
	// 	if (i > str.Length)
	// 		return false;
	// 	if (i == str.Length && root.IsEnd) {
	// 		root.IsEnd = false;
	// 		if (!ContainsChildren(root))
	// 			root = null; return true;
	// 	}
	// 	else if (DeleteHelper(ref root.child[(int)str[i]], i + 1, str)) {
	// 		if (!ContainsChildren(root))
	// 			root = null;
	// 		return true;
	// 	}
	// 	return true;
	// }
	// public void Delete(string str) {
	// 	DeleteHelper(ref head, 0, str);
	// }
	static void Main() {
		string [] strarr = {"shiva", "sairaj", "ranju", "gokul", "ganesh", "ram", "rajkumar", "tamil", "anisha", "anjana"
		                    , "nantha", "nitheesh", "ravi", "saraswathy", "balaji", "vinoth", "prem", "sudarson", "sathya", "prakash", "mano",
		                    "jagadeesh", "santhosh", "jude", "sruthi"
		                   };
		var trie = new TST();
		foreach (var str in strarr)
			trie.Insert(str);
		trie.Display();
		Console.WriteLine();
		// foreach (var v in strarr)
		// 	Console.Write(trie.Search(v) + " ");
		// foreach (var str in strarr)
		// {
		// 	trie.Delete(str);
		// 	Console.WriteLine();
		// 	trie.Display();
		// }

		// trie.Print();

	}
}