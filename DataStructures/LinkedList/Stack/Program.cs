using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DataStructures.Stack {
    class Program {
        static void Main (string[] args) {

            var stack = new Stack<int>();
            stack.Push(5);
            stack.Push(4);
            stack.Push(3);
            stack.Push(2);
            stack.Display();
            foreach (var item in stack) {
                Console.WriteLine(item);
            }
            var temp = stack.Reverse();
            foreach (var item in temp) {
                Console.WriteLine(item);
            }
            stack.Pop();
            stack.Pop();
            stack.Pop();
            stack.Pop();
            stack.Pop();
            stack.Display();
            Console.ReadKey();
        }
    }
}
