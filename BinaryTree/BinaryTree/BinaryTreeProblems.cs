using System;
using System.Collections;
using System.Collections.Generic;
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
    //http://www.geeksforgeeks.org/given-a-binary-tree-print-out-all-of-its-root-to-leaf-paths-one-per-line/
    internal static void PrintRootToLeafPath(Node root, int [] arr, int idx) {
        if (root == null)
            return;

        arr[idx] = root.Data;
        if (root.Left == null && root.Right == null) {
            for (int i = 0; i <= idx; i++)
                Console.Write(arr[i]); Console.WriteLine();

        }
        PrintRootToLeafPath(root.Left, arr, idx + 1);
        PrintRootToLeafPath(root.Right, arr, idx + 1);
    }

    internal static void TreeToList (Node root, ref Node list) {
        if (root == null)
            return;

        TreeToList(root.Left, ref list);
        if (list == null) {
            list = root;
        } else {
            list.Right = root;
            root.Left = list;
            list = list.Right;
        }
        TreeToList(root.Right, ref list);

    }

    internal static void LevelOrderTraversal(Node root) {
        var queue = new Queue<Node>();
        queue.Enqueue(root);
        while (queue.Count > 0) {
            Console.WriteLine(queue.Peek().Data);
            if (queue.Peek().Left != null)
                queue.Enqueue(queue.Peek().Left);
            if (queue.Peek().Right != null)
                queue.Enqueue(queue.Peek().Right);
            queue.Dequeue();
        }
    }

    internal static void CountLeafNodes(Node root, ref int count) {
        if (root == null)
            return;

        if (root.Left == null && root.Right == null) {
            count++; return;
        }

        CountLeafNodes(root.Left, ref count);
        CountLeafNodes(root.Right, ref count);
    }
    internal static void LevelOrderTraversalSpiral(Node root) {
        if (root == null)
            return;
        LevelOrderTraversal(root);
        var stack = new Stack<Node>();
        stack.Push(root);
        bool flag = false;
        while (stack.Count > 0) {
            var temp = new Stack<Node>();
            flag = !flag;
            while (stack.Count > 0) {
                Console.Write(stack.Peek().Data + " ");
                if (flag) {
                    if (stack.Peek().Right != null)
                        temp.Push(stack.Peek().Right);
                    if (stack.Peek().Left != null)
                        temp.Push(stack.Peek().Left);
                } else {
                    if (stack.Peek().Left != null)
                        temp.Push(stack.Peek().Left);
                    if (stack.Peek().Right != null)
                        temp.Push(stack.Peek().Right);
                }
                stack.Pop();

            }
            Console.WriteLine();
            stack = temp;
        }
    }

    internal static bool ChildrenSumProperty(Node root) {
        if (root == null)
            return true;

        if (root.Left == null && root.Right == null)
            return true;
        int left = 0, right = 0;
        if (root.Left != null)
            left = root.Left.Data;
        if (root.Right != null)
            right = root.Right.Data;
        return (root.Data == left + right) && ChildrenSumProperty(root.Left) && ChildrenSumProperty(root.Right);
    }

    internal static void ConvertChildrenSum(Node root) {
        if (root == null || (root.Left == null && root.Right == null))
            return;

        ConvertChildrenSum(root.Left);
        ConvertChildrenSum(root.Right);
        int left = 0, right = 0;
        if (root.Left != null)
            left = root.Left.Data;
        if (root.Right != null)
            right = root.Right.Data;
        int diff = left + right - root.Data;
        if (diff > 0)
            root.Data = root.Data + diff;

        if (diff < 0)
            AddDiff(root, -diff);
    }
    internal static void AddDiff(Node root, int diff) {
        if (root.Left != null) {
            root.Left.Data += diff;
            AddDiff(root.Left, diff);
        }
        if (root.Right != null) {
            root.Right.Data += diff;
            AddDiff(root.Right, diff);
        }
    }



    internal static int Diameter(Node root, ref int dia) {
        if (root == null)
            return 0;

        int lh = Diameter(root.Left, ref dia);
        int rh = Diameter(root.Right, ref dia);
        //Console.WriteLine(root.Data + " " + lh + " " + rh);
        // Console.WriteLine(dia + " " + (lh + rh + 1));
        dia = Math.Max(dia, lh + rh + 1);

        return Math.Max(lh, rh) + 1;
    }
}

internal class Program {
    private static Node NewNode (int value) {
        return new Node { Data = value, Left = null, Right = null };
    }
    private static Node GetTree() {
        var node1 = NewNode(5);
        node1.Left = NewNode(4);
        node1.Right = NewNode(3);
        node1.Right.Left = NewNode(100);
        node1.Right.Left.Left = NewNode(100);
        node1.Right.Left.Left.Left = NewNode(100);
        node1.Right.Left.Left.Left.Left = NewNode(100);
        node1.Right.Left.Left.Left.Left.Left = NewNode(100);

        node1.Left.Left = NewNode(6);
        node1.Left.Right = NewNode(7);
        node1.Right.Right = NewNode(10);
        node1.Right.Right.Right = NewNode(12);
        node1.Right.Right.Right.Right = NewNode(12);
        node1.Right.Right.Left = NewNode(12);
        return node1;
    }

    private static Node GetSumTree() {
        var node = NewNode(10);
        node.Left = NewNode(6);
        node.Right = NewNode(4);
        node.Left.Left = NewNode(2);
        node.Left.Right = NewNode(4);
        node.Right.Left = NewNode(1);
        node.Right.Right = NewNode(3);
        return node;
    }
    private static void SizeofTreeCaller () {
        var node = NewNode(5);
        node.Left = NewNode(4);
        node.Right = NewNode(3);
        node.Left.Left = NewNode(6);
        //node.Left.Right = NewNode(7);
        node.Right.Right = NewNode(10);

        Console.WriteLine(Problems.SizeofTree(node));

    }

    private static void CheckIfTreesAreIdenticalCaller () {
        var node1 = NewNode(5);
        node1.Left = NewNode(4);
        node1.Right = NewNode(3);
        node1.Left.Left = NewNode(6);
        //node.Left.Right = NewNode(7);
        node1.Right.Right = NewNode(10);

        var node2 = NewNode(5);
        node2.Left = NewNode(4);
        node2.Right = NewNode(3);
        node2.Left.Left = NewNode(6);
        //node.Left.Right = NewNode(7);
        node2.Right.Right = NewNode(10);

        Console.WriteLine(Problems.CheckIfTreesAreIdentical(node1, node2));

        node2.Left.Right = NewNode(7);
        Console.WriteLine(Problems.CheckIfTreesAreIdentical(node1, node2));

    }

    private static void HeightOfTreeCaller() {
        var node1 = NewNode(5);
        node1.Left = NewNode(4);
        node1.Right = NewNode(3);
        node1.Left.Left = NewNode(6);
        //node.Left.Right = NewNode(7);
        node1.Right.Right = NewNode(10);

        Console.WriteLine(Problems.HeightOfTree(node1));

        node1.Left.Right = NewNode(7);
        node1.Left.Right.Right = NewNode(7);

        Console.WriteLine(Problems.HeightOfTree(node1));


    }

    private static void DeleteTreeCaller() {
        var node1 = NewNode(5);
        node1.Left = NewNode(4);
        node1.Right = NewNode(3);
        node1.Left.Left = NewNode(6);
        //node.Left.Right = NewNode(7);
        node1.Right.Right = NewNode(10);

        Problems.DeleteTree(node1);
    }

    private static void PrintRootToLeafPathCaller() {
        var node1 = NewNode(5);
        node1.Left = NewNode(4);
        node1.Right = NewNode(3);
        node1.Left.Left = NewNode(6);
        node1.Left.Right = NewNode(7);
        node1.Right.Right = NewNode(10);
        int [] arr = new int[Problems.HeightOfTree(node1) + 1];
        Problems.PrintRootToLeafPath(node1, arr, 0);

    }
    private static void TreeToListCaller() {

        Node node2 = null;
        Problems.TreeToList(GetTree(), ref node2);
        while (node2 != null) {
            Console.WriteLine(node2.Data);
            node2 = node2.Left;
        }
    }
    private static void LevelOrderTraversalCaller() {

        Problems.LevelOrderTraversal(GetTree());
    }

    private static void CountLeafNodesCaller() {

        int count = 0;
        Problems.CountLeafNodes(GetTree(), ref count);
        Console.WriteLine(count);
    }

    private static void TreeMirroringCaller() {
        Problems.TreeMirroring(GetTree());
    }

    private static void LevelOrderTraversalSpiralCaller() {
        Problems.LevelOrderTraversalSpiral(GetTree());
    }
    private static void ChildrenSumPropertyCaller() {
        Console.WriteLine(Problems.ChildrenSumProperty(GetTree()));
        Console.WriteLine(Problems.ChildrenSumProperty(GetSumTree()));
    }

    private static void ConvertChildrenSumCaller() {
        var node = GetTree();
        var node1 = GetSumTree();
        Console.WriteLine(Problems.ChildrenSumProperty(node));
        Console.WriteLine(Problems.ChildrenSumProperty(node1));

        Problems.ConvertChildrenSum(node);
        Problems.ConvertChildrenSum(node1);
        Console.WriteLine(Problems.ChildrenSumProperty(node));
        Console.WriteLine(Problems.ChildrenSumProperty(node1));
    }

    static void DiameterCaller() {
        int dia = 0;
        Problems.Diameter(GetTree(), ref dia);
        Console.WriteLine(dia); dia = 0;
        Problems.Diameter(GetSumTree(), ref dia);
        Console.WriteLine(dia);
    }
    private static void Main (string[] args) {
        // SizeofTreeCaller();
        // CheckIfTreesAreIdenticalCaller();
        // HeightOfTreeCaller();
        // DeleteTreeCaller();
        // TreeMirroringCaller();
        // PrintRootToLeafPathCaller();
        // TreeToListCaller();
        // LevelOrderTraversalCaller();
        // CountLeafNodesCaller();
        //LevelOrderTraversalSpiralCaller();
        // ChildrenSumPropertyCaller();
        //ConvertChildrenSumCaller();
        DiameterCaller();
        // //Console.ReadKey();
    }
}