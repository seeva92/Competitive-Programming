using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DataStructures.Queue {
    class Program {
        static void Main (string[] args) {
            var random = new Random();
            var queue = new Queue<int>();
            for (int i = 0; i < 10; i++) {
                queue.Enqueue(random.Next(0,100));
            }

            foreach (var item in queue) {
                Console.WriteLine(item);
            }

            for (int i = 0; i < 11; i++) {
                queue.Dequeue();
            }

            Console.ReadKey();
        }
    }
}
