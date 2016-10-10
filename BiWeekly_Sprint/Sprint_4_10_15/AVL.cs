using System;
using System.Collections;
using System.Collections.Generic;
using System.Text;
class AVL {
	class Node {
		public int data;
		public Node left, right;
		public int height;
	}

	private Node head;

	private Node NewNode(int data) {
		return new Node {data = data, height = 1};
	}
	private void InsertHelper(ref Node root, int data) {
		if (root ==  null)
			root = NewNode(data);
		else if (data < root.data)
			InsertHelper(ref root.left, data);
		else
			InsertHelper(ref root.right, data);

		root.height = Math.Max(Height(root.left), Height(root.right)) + 1;

		if (BalanceFactor(root) < -1)
		{
			if (BalanceFactor(root.right) < 0) {
				root = LeftRotate(root, root.right);
			}
			if (BalanceFactor(root.right) > 0) {
				root.right = RightRotate(root.right, root.right.left);
				root = LeftRotate(root, root.right);
			}
		}
		if (BalanceFactor(root) > 1) {
			if (BalanceFactor(root.left) > 0) {
				root = RightRotate(root, root.left);
			}
			if (BalanceFactor(root.left) < 0) {
				root.left = LeftRotate(root.left, root.left.right);
				root = RightRotate(root, root.left);
			}
		}
	}

	public void Insert(int data) {
		InsertHelper(ref head, data);
	}

	private void DisplayHelper(Node root) {
		if (root != null) {
			DisplayHelper(root.left);
			Console.Write(root.data + " ");
			DisplayHelper(root.right);
		}
	}
	public void Display() {
		DisplayHelper(head);
	}

	private void Swap<T>(ref T a, ref T b) {
		T c = a;
		a = b;
		b = c;
	}
	private void DeleteHelper(ref Node root, int data) {
		if (root == null)
			return;

		if (data < root.data)
			DeleteHelper(ref root.left, data);
		else if (data > root.data)
			DeleteHelper(ref root.right, data);
		else {
			if (root.left == null && root.right == null) {
				root = null;
			} else if (root.left != null && root.right == null) {
				var temp = root;
				root = root.left;
				temp = null;
			} else if (root.left == null && root.right != null) {
				var temp = root;
				root = root.right;
				temp = null;
			} else {
				var temp = root.right;
				while (temp.left != null)
					temp = temp.left;

				Swap(ref temp.data, ref root.data);
				DeleteHelper(ref root.right, data);
			}

		}

		if (root == null)
			return;
		root.height = Math.Max(Height(root.left), Height(root.right)) + 1;

		if (BalanceFactor(root) < -1)
		{
			if (BalanceFactor(root.right) < 0) {
				root = LeftRotate(root, root.right);
			}
			if (BalanceFactor(root.right) > 0) {
				root.right = RightRotate(root.right, root.right.left);
				root = LeftRotate(root, root.right);
			}
		}
		if (BalanceFactor(root) > 1) {
			if (BalanceFactor(root.left) > 0) {
				root = RightRotate(root, root.left);
			}
			if (BalanceFactor(root.left) < 0) {
				root.left = LeftRotate(root.left, root.left.right);
				root = RightRotate(root, root.left);
			}
		}

	}

	public void Delete(int data) {
		DeleteHelper(ref head, data);
	}

	private int Height(Node root) {
		if (root == null)
			return 0;

		return (root.left == null ? 0 : root.left.height) + (root.right == null ? 0 : root.right.height);
	}

	private int BalanceFactor(Node root) {
		if (root == null)
			return 0;

		return Height(root.left) - Height(root.right);
	}

	private Node LeftRotate(Node curr, Node right) {
		Node rightLeft = right.left;
		right.left = curr;
		curr.right = rightLeft;
		return rightLeft;
	}

	private Node RightRotate(Node curr, Node left) {
		Node leftRight = left.right;
		left.right = curr;
		curr.left = leftRight;
		return left;
	}
	static void Main() {
		Console.WriteLine("I love you");
		int [] arr = {4, 6, 1, 8, 3, 2, 9, 0, 5, 7};
		var avl = new AVL();
		foreach (var v in arr)
			avl.Insert(v);

		avl.Display();
		Console.Write("\n");

		foreach (var v in arr) {
			//Console.Write(v);
			avl.Delete(v);
			avl.Display();
			Console.Write("\n");
		}

	}
}