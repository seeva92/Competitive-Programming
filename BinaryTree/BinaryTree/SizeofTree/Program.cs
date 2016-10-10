using System;
using Problems;

namespace BinaryTreeProblems {


    internal class Program {
        private static Node NewNode (int value) {
            return new Node { Data = value };
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

        private static void TreeMirroringCaller () {
            var node1 = NewNode(5);
            node1.Left = NewNode(4);
            node1.Right = NewNode(3);
            node1.Left.Left = NewNode(6);
            //node.Left.Right = NewNode(7);
            node1.Right.Right = NewNode(10);
            Problems.PreOrderRec(node1);
            node1 = Problems.TreeMirroring(node1);
            Problems.PreOrderRec(node1);

        }
        private static void Main (string[] args) {
            //SizeofTreeCaller();
            //CheckIfTreesAreIdenticalCaller();
            //HeightOfTreeCaller();
            //DeleteTreeCaller();
            TreeMirroringCaller();
            Console.ReadKey();
        }
    }
}