using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SegmentTree {
    class Program {
        static void Main (string[] args) {
            var random = new Random();

            int[] a = new int[10];
            for (int i = 0; i < a.Length; i++) {
                a[i] = random.Next(0, 10);
            }

            var segTree = new SegTree(a);
            segTree.Display();
            Console.WriteLine();
            Console.WriteLine(segTree.SumRange(1, 4));
            Console.WriteLine(segTree.SumRange(0, 5));
            segTree.Update(0, 10);
            Console.WriteLine(segTree.SumRange(0, 5));
            segTree.Update(4, 10);
            Console.WriteLine(segTree.SumRange(1, 4));

            Console.ReadKey();
            
        }
    }
}
