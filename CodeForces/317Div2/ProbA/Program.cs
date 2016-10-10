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
            Console.SetIn(new StreamReader(File.OpenRead("C:\\Users\\Shiva\\Desktop\\317Div2A.txt")));
#endif
            int nA, nB, k, m;
            var first = Console.ReadLine().Split(new char[] { ' ' });
            nA = int.Parse(first[0]); nB = int.Parse(first[1]);

            var second = Console.ReadLine().Split(new char[] { ' ' });
            k = int.Parse(second[0]); m = int.Parse(second[1]);

            var aArray = Console.ReadLine().Split(new char[] { ' ' }).Select(s => {
                return int.Parse(s);
            }).ToArray();

            var bArray = Console.ReadLine().Split(new char[] { ' ' }).Select(s => {
                return int.Parse(s);
            }).ToArray();

            if (aArray[k - 1] < bArray[nB - m])
                Console.WriteLine("YES");
            else
                Console.WriteLine("NO");
#if DEBUG
            Console.ReadKey();
#endif
        }
    }
}
