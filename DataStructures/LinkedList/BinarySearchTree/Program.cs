using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BinarySearchTree {
    class Program {
        static void Main (string[] args) {

            var random = new Random();
            var bst = new BST();
            var list = new List<int>();
            for(int i = 0; i < 100; i++) {
                list.Add(random.Next(1, 200));
            }
            foreach (var item in list) {
                bst.Insert(item);
            }
            bst.Inorder();
            Console.ReadKey();

            foreach(var item in list) {
                bst.Delete(item);
            }
            bst.Inorder();
            Console.ReadKey();

        }
    }
}
