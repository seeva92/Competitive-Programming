using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TrieDa {
    public class Trie {
        const int size = 256;

        private class Node {
            public Node[] children = new Node[size];
            public bool IsEnd { get; set; }
        }

        private Node root;
        public int Count { get; set; }
        public Trie () {
            root = new Node();
        }

        public void Insert (string str) {
            var temp = root;
            foreach (var letter in str) {
                if (temp.children[((int)letter)] == null) {
                    temp.children[((int)letter)] = new Node();
                }
                temp = temp.children[((int)letter)];
            }
            temp.IsEnd = true;
            Count++;
        }

        private void DisplayHelper (Node temp, string str) {
            if (temp == null)
                return;
            if (temp.IsEnd)
                Console.WriteLine(str);


            for (int i = 0; i < size; i++) {
                if (temp.children[i] != null)
                    DisplayHelper(temp.children[i], str + (char)i);
            }
        }

        private bool IsChildrenEmpty(Node temp) {
            if (temp == null)
                return true;

            for (int i = 0; i < size; i++) {
                if (temp.children[i] != null)
                    return false;
            }

            return true;
        }
        private bool DeleteHelper (ref Node temp, string str, int i) {
            if (temp == null)
                return false;
            if (i > str.Length)
                return false;
            if(i == str.Length && temp.IsEnd) {
                if(IsChildrenEmpty(temp)) {
                    temp = null; return true;
                }
                return false;
            }

            if(DeleteHelper(ref temp.children[((int)str[i])], str, i + 1)) {
                if (IsChildrenEmpty(temp)) {
                    temp = null;
                    return true;
                }
                return false;
            }

            return false;
        }

        public void Delete(string str) {
            DeleteHelper(ref root, str, 0);
        }

        public void Display () {
            DisplayHelper(root, "");
        }
    }
}
