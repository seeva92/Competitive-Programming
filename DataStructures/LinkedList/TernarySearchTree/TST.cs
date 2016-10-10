using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TernarySearchTree {
    public class TST {
        internal class Node {
            public char data { get; set; }
            public Node left, right, center;
            public bool IsEnd { get; set; }
        };

        private Node root;
        private Node NewNode(char c) {
            var node = new Node();
            node.data = c; return node;
        }
        private void InsertHelper(ref Node temp,string str,int i) {
            if (temp == null) {
                temp = NewNode(str[i]);
            }
            if (str[i] < temp.data)
                InsertHelper(ref temp.left, str, i);
            else if (str[i] > temp.data)
                InsertHelper(ref temp.right, str, i);
            else {
                if(i+1 == str.Length) {
                    temp.IsEnd = true;
                    return;
                }

                InsertHelper(ref temp.center, str, i + 1);
            }
        }

       public void Insert(string str) {
            if (string.IsNullOrWhiteSpace(str))
                return;

            InsertHelper(ref root, str, 0);
        }

        private void DisplayHelper(Node node,string str, int i) {
            if (node == null)
                return;

            DisplayHelper(node.left, str, i);
            if (node.IsEnd) {
                Console.WriteLine(str+node.data);
            }
            DisplayHelper(node.center, str+node.data, i + 1);
            DisplayHelper(node.right, str, i);
        }
        public void Display () {
            DisplayHelper(root, "", 0);
        }

        private void DeleteHelper(ref Node node,string str, int i) {
            if (node == null)
                return;

            if (node.data > str[i])
                DeleteHelper(ref node.left, str, i);
            else if (node.data < str[i])
                DeleteHelper(ref node.right, str, i);
            else {
                if(i+1 == str.Length && node.IsEnd) {
                    node.IsEnd = false;
                    return;
                }

                DeleteHelper(ref node.center, str, i + 1);
            }
        }

        public void Delete(string str) {
            DeleteHelper(ref root, str, 0);
        }
    }
}
