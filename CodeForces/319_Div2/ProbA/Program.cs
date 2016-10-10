using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ProbA {
    class Program {

        static void Main (string[] args) {
#if DEBUG
            Console.SetIn(new StreamReader(File.OpenRead("C:\\Users\\Shiva\\Desktop\\319_Div2ProbA.txt")));
#endif
            var first = Console.ReadLine().Split(new char[] { ' ' });
            int n = int.Parse(first[0]); int x = int.Parse(first[1]);
            int counter = 0;
            int temp = n;
            int div = 0;
            while (n > 0) {
                div = x / n;
                if (x % n == 0 && (div) <= temp && (div >= 1))
                    counter++;
                n--;
            }
            Console.WriteLine(counter);
#if DEBUG
            Console.ReadKey();
#endif
        }
    }
}
