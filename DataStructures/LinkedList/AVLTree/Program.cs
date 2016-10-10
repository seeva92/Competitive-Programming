using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AVLTree {
    class Program {
        static void Main (string[] args) {

            var avl = new AVL();
            var random = new Random();
            var list = new List<int>();
            for (int i = 0; i < 100; i++) {
                list.Add(random.Next(1, 200));

            }
            int count = 0;
            foreach (var item in list) {
                avl.Insert(item);
                count++;
            }  
            avl.Inorder();
            Console.WriteLine(avl.Count+" "+list.Count);
            Console.ReadKey();

            foreach (var item in list) {

                avl.Delete(item);
            }

            avl.Inorder();
            Console.WriteLine(avl.Count + " " + list.Count);
            Console.ReadKey();
        }
    }
}
