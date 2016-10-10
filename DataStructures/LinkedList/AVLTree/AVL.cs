using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AVLTree {
    public class AVL {
        private class Node {
            public int data {
                get; set;
            }
            public Node left;
            public Node right;
            public int height { get; set; }
        }

        private Node root;
        public int Count { get; set; }
        private int GetHeight (Node node) {
            if (node == null)
                return 0;

            int lt_height = 0;
            int rt_height = 0;
            if (node.left != null)
                lt_height += node.left.height;
            if (node.right != null)
                rt_height += node.right.height;

            return Math.Max(lt_height, rt_height);
        }


        /// <summary>
        /// Left rotate the subRoot
        /// </summary>
        /// <param name="subRoot"></param>
        /// <param name="right"></param>
        /// <returns></returns>
        private Node LeftRotate (Node subRoot, Node right) {
            var rightLeft = right.left;
            right.left = subRoot;
            subRoot.right = rightLeft;
            return right;
        }


        /// <summary>
        /// Right rotate the subRoot
        /// </summary>
        /// <param name="subRoot"></param>
        /// <param name="left"></param>
        /// <returns></returns>
        private Node RightRotate (Node subRoot, Node left) {
            var leftRight = left.right;
            left.right = subRoot;
            subRoot.left = leftRight;
            return left;
        }


        /// <summary>
        /// Gets the balance factor of the current node
        /// </summary>
        /// <param name="node"></param>
        /// <returns></returns>
        private int balFactor (Node node) {
            if (node == null)
                return 0;
            int lt_height = GetHeight(node.left);
            int rt_height = GetHeight(node.right);

            return lt_height - rt_height;
        }


        /// <summary>
        /// Checks if the tree is empty
        /// </summary>
        public bool IsEmpty {
            get {
                if (root == null)
                    return true;
                return false;
            }
        }

        private Node NewNode (int data) {
            return new Node() {
                data = data,
                height = 0
            };

        }

        private void InsertHelper (int data, ref Node temp) {
            if (temp == null) {
                temp = NewNode(data);
                Count++;
            } else if (data < temp.data)
                InsertHelper(data, ref temp.left);
            else
                InsertHelper(data, ref temp.right);

            //Update Node Height
            temp.height = GetHeight(temp) + 1;

            int bal = balFactor(temp);
            if (bal < -1 && balFactor(temp.right) > 0) {
                temp.right = RightRotate(temp.right, temp.right.left);
                temp = LeftRotate(temp, temp.right);
            }
            if (bal < -1 && balFactor(temp.right) < 0) {
                temp = LeftRotate(temp, temp.right);
            }
            if (bal > 1 && balFactor(temp.left) > 0) {
                temp = RightRotate(temp, temp.left);
            }
            if (bal > 1 && balFactor(temp.left) < 0) {
                temp.left = LeftRotate(temp.left, temp.left.right);
                temp = RightRotate(temp, temp.left);
            }
        }


        /// <summary>
        /// Inserts a new node and balance the tree height
        /// </summary>
        /// <param name="data"></param>
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
                    temp = null; Count--;
                } else if (temp.left != null && temp.right == null) {
                    var deleteNode = temp;
                    temp = temp.left;
                    deleteNode = null; Count--;
                } else if (temp.left == null && temp.right != null) {
                    var deleteNode = temp;
                    temp = temp.right;
                    deleteNode = null; Count--;
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
            if (temp == null)
                return;

            //Update the height
            temp.height = GetHeight(temp) + 1;

            int bal = balFactor(temp);

            if (bal < -1 && balFactor(temp.right) <= 0) {
                temp = LeftRotate(temp, temp.right);
            }
            if (bal < -1 && balFactor(temp.right) > 0) {
                temp.right = RightRotate(temp.right, temp.right.left);
                temp = LeftRotate(temp, temp.right);
            }
            if (bal > 1 && balFactor(temp.left) >= 0) {
                temp = RightRotate(temp, temp.left);
            }

            if (bal > 1 && balFactor(temp.left) < 0) {
                temp.left = LeftRotate(temp.left, temp.left.right);
                temp = RightRotate(temp, temp.left);
            }

        }

        /// <summary>
        /// Deletes the first occurence of the given data
        /// </summary>
        /// <param name="data"></param>
        public void Delete (int data) {
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
