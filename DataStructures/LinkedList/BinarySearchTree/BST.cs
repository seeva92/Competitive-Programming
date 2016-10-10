using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BinarySearchTree {
    class BST {
        private class Node {
            public int data {
                get; set;
            }
            public Node left;
            public Node right;
        }

        private Node root;

        public bool IsEmpty {
            get {
                if (root == null)
                    return true;
                return false;
            }
        }

        private Node NewNode (int data) {
            return new Node() {
                data = data
            };

        }

        private void InsertHelper (int data, ref Node temp) {
            if (temp == null)
                temp = NewNode(data);
            else if (data < temp.data)
                InsertHelper(data, ref temp.left);
            else
                InsertHelper(data, ref temp.right);
        }

        public void Insert (int data) {
            InsertHelper(data, ref root);
        }

        private void DeleteHelper (int data, ref Node temp) {
            if (temp == null)
                return;
            else if (data < temp.data)
                DeleteHelper(data, ref temp.left);
            else if (data > temp.data)
                DeleteHelper(data, ref temp.right);
            else {
                if (temp.left == null && temp.right == null) {
                    temp = null; return;
                } else if (temp.left != null && temp.right == null) {
                    var deleteNode = temp;
                    temp = temp.left;
                    deleteNode = null;
                    return;
                }else if(temp.left == null && temp.right != null) {
                    var deleteNode = temp;
                    temp = temp.right;
                    deleteNode = null;
                    return;
                } else {

                    var rightSubTree = temp.right;
                    while (rightSubTree.left != null)
                        rightSubTree = rightSubTree.left;

                    //Swapping Values
                    var value = rightSubTree.data;
                    rightSubTree.data = temp.data;
                    temp.data = value;

                    DeleteHelper(data, ref temp.right);
                }
            }
        }

        public void Delete (int data) {
            if (IsEmpty)
                return;
            DeleteHelper(data, ref root);
        }

        private void InorderHelper (Node temp) {
            if (temp != null) {
                InorderHelper(temp.left);
                Console.WriteLine(temp.data);
                InorderHelper(temp.right);
            }
        }

        public void Inorder () {
            InorderHelper(root);
        }
    }
}
