using System;
using System.Runtime.InteropServices.WindowsRuntime;

namespace BinaryTreeProblems {
    internal class Node {
        public Node Left;
        public Node Right;
        public int Data { get; set; }
    }

    internal class Problems {
        internal static void Swap<T>(ref T data1, ref T data2) {
            var temp = data1;
            data1 = data2;
            data2 = temp;
        }

        internal static void PreOrderRec(Node temp) {
            if (temp == null)
                return;

            Console.WriteLine(temp.Data);
            PreOrderRec(temp.Left);
            PreOrderRec(temp.Right);
        }

        //Calculates the size of the tree http://www.geeksforgeeks.org/write-a-c-program-to-calculate-size-of-a-tree/
        internal static int SizeofTree (Node temp) {
            if (temp == null)
                return 0;
            var lh = SizeofTree(temp.Right);
            var rh = SizeofTree(temp.Left);
            return lh + rh + 1;
        }

        //Check if two tree are identical http://www.geeksforgeeks.org/write-a-c-program-to-find-the-maximum-depth-or-height-of-a-tree/
        internal static bool CheckIfTreesAreIdentical (Node tree1, Node tree2) {
            if (tree1 == null && tree2 == null)
                return true;

            if (tree1 == null || tree2 == null)
                return false;

            if (tree1.Data != tree2.Data)
                return false;

            return CheckIfTreesAreIdentical(tree1.Left, tree2.Left) &&
                   CheckIfTreesAreIdentical(tree1.Right, tree2.Right);
        }

        //Calculates the height of the tree http://www.geeksforgeeks.org/write-a-c-program-to-find-the-maximum-depth-or-height-of-a-tree/
        internal static int HeightOfTree (Node root) {
            if (root == null)
                return 0;

            var lh = HeightOfTree(root.Left);
            var rh = HeightOfTree(root.Right);

            return Math.Max(lh, rh) + 1;
        }

        //Deletes the Tree http://www.geeksforgeeks.org/write-a-c-program-to-delete-a-tree/
        internal static void DeleteTree (Node root) {
            if (root == null)
                return;

            DeleteTree(root.Left);
            DeleteTree(root.Right);

            root = null;
        }

        //Mirrors the Tree http://www.geeksforgeeks.org/write-an-efficient-c-function-to-convert-a-tree-into-its-mirror-tree/
        internal static Node TreeMirroring (Node root) {
            if (root == null)
                return null;

            TreeMirroring(root.Left);
            TreeMirroring(root.Right);
            Swap(ref root.Left, ref root.Right);
            return root;
        }
    }
}