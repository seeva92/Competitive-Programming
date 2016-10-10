using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BinaryIndexedTree {
    class Program {
        static void Main (string[] args) {

            var list = new List<int>();
            var random = new Random();
            for(int i = 0; i < 10; i++) {
                list.Add(random.Next(1, 10));
            }

            foreach (var item in list) {
                Console.Write(item+"  ");
            }
            Console.WriteLine();
            var bit = new BIT(list.ToArray());
            bit.Display();
            Console.WriteLine();
            Console.WriteLine(bit.GetSum(5));
            Console.WriteLine(bit.GetSum(7));
            Console.WriteLine(bit.GetSum(list.Count));
            bit.Update(0, 10);
            bit.Update(1, 10);
            Console.WriteLine(bit.GetSum(5));
            Console.WriteLine(bit.GetSum(7));

            Console.ReadKey();

        }
    }
}
