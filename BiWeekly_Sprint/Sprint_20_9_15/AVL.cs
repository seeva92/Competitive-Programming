/*
Author : Shivakkumar K R
File name : AVL.cs
*/
using System;
using System.Collections;
using System.Linq;
using System.Text;
public class AVL {
	class Node {
		public int Data, Height;
		public Node Left, Right;
	}
	Node root;
	private void Swap<T>(ref T val1, ref T val2) {
		T temp = val2;
		val2 = val1;
		val1 = temp;
	}
	private Node NewNode(int data) {
		return new Node {
			Data = data, Left = null, Right = null, Height = 1
		};
	}

	private int GetHeight(Node temp) {
		if (temp == null)
			return 0;
		int lh = temp.Left == null ? 0 : temp.Left.Height;
		int rh = temp.Right == null ? 0 : temp.Right.Height;
		return lh + rh;
	}

	private int GetBalanceFactor(Node temp) {
		if (temp == null)
			return 0;
		return GetHeight(temp.Left) - GetHeight(temp.Right);
	}

	private Node LeftRotate(Node temp, Node right) {
		var rightLeft = right.Left;
		right.Left = temp;
		temp.Right = rightLeft;
		return right;
	}

	private Node RightRotate(Node temp, Node left) {
		var leftRight = left.Right;
		left.Right = temp;
		temp.Left = leftRight;
		return left;
	}
	private void Insert(ref Node temp, int data) {
		if (temp == null)
			temp = NewNode(data);
		else if (data < temp.Data)
			Insert(ref temp.Left, data);
		else if (data >= temp.Data)
			Insert(ref temp.Right, data);

		temp.Height = GetHeight(temp) + 1;

		if (GetBalanceFactor(temp) < -1 && GetBalanceFactor(temp.Right) < 0)
			temp = LeftRotate(temp, temp.Right);
		if (GetBalanceFactor(temp) > 1 && GetBalanceFactor(temp.Left) > 0)
			temp = RightRotate(temp, temp.Left);
		if (GetBalanceFactor(temp) < -1 && GetBalanceFactor(temp.Right) > 0) {
			temp.Right = RightRotate(temp.Right, temp.Right.Left);
			temp = LeftRotate(temp, temp.Right);
		}
		if (GetBalanceFactor(temp) > 1 && GetBalanceFactor(temp.Left) < 0) {
			temp.Left = LeftRotate(temp.Left, temp.Left.Right);
			temp = RightRotate(temp, temp.Left);
		}
	}
	private void Delete(ref Node temp, int data) {
		if (temp == null)
			return;
		if (data < temp.Data)
			Delete(ref temp.Left, data);
		else if (data > temp.Data)
			Delete(ref temp.Right, data);
		else {
			if (temp.Left == null && temp.Right == null) {
				temp = null;
			} else if (temp.Left != null && temp.Right == null) {
				var deleting = temp;
				temp = temp.Left; deleting = null;
			} else if (temp.Left == null && temp.Right != null) {
				var deleting = temp;
				temp = temp.Right; deleting = null;
			} else {
				var right = temp.Right;
				while (right.Left != null)
					right = right.Left;
				Swap(ref right.Data, ref temp.Data);
				Delete(ref temp.Right, data);
			}
		}
		if (temp == null)
			return;

		temp.Height = Math.Max(GetHeight(temp.Left), GetHeight(temp.Right)) + 1;

		if (GetBalanceFactor(temp) < -1 && GetBalanceFactor(temp.Right) < 0)
			temp = LeftRotate(temp, temp.Right);
		if (GetBalanceFactor(temp) > 1 && GetBalanceFactor(temp.Left) > 0)
			temp = RightRotate(temp, temp.Left);
		if (GetBalanceFactor(temp) < -1 && GetBalanceFactor(temp.Right) > 0) {
			temp.Right = RightRotate(temp.Right, temp.Right.Left);
			temp = LeftRotate(temp, temp.Right);
		}
		if (GetBalanceFactor(temp) > 1 && GetBalanceFactor(temp.Left) < 0) {
			temp.Left = LeftRotate(temp.Left, temp.Left.Right);
			temp = RightRotate(temp, temp.Left);
		}
	}
	private void InOrder(Node temp) {
		if (temp == null)
			return;
		InOrder(temp.Left); Console.WriteLine(temp.Data); InOrder(temp.Right);
	}
	private int Height(Node temp) {
		if (temp == null)
			return 0;
		return Math.Max(Height(temp.Left), Height(temp.Right)) + 1;
	}
	public void InsertHelper(int data) {
		Insert(ref root, data);
	}

	public void InOrderHelper() {
		InOrder(root);
	}
	public void DeleteHelper(int data) {
		Delete(ref root, data);
	}
	public int HeightHelper() {
		return Height(root);
	}
	static void Main(string [] args) {
		int [] a = {3, 6, 1, 7, 2, 8, 4, 9, 10};
		var avlTree = new AVL();
		int n = 100;
		var random = new Random();

		for (int i = 0; i < n; i++)
			avlTree.InsertHelper(random.Next(0, n));
		 avlTree.InOrderHelper();
		Console.WriteLine("Height:{0}", avlTree.HeightHelper());
		for (int i = 0; i < n; i++) {
			avlTree.DeleteHelper(random.Next(0, n));
		}
		avlTree.InOrderHelper();
	}
}