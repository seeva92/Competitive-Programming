using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ProbB {
    class Program {

        static void Main (string[] args) {
#if DEBUG
            Console.SetIn(new StreamReader(File.OpenRead("C:\\Users\\Shiva\\Desktop\\319_Div2ProbB.txt")));
#endif
            int[] nArray;
            var input = Console.ReadLine().Split(new char[] { ' ' });
            nArray = new int[int.Parse(input[0])];
            int m = int.Parse(input[1]);
            int n = nArray.Length;

            bool[] dp = new bool[m + 2];
            input = Console.ReadLine().Split(new char[] { ' ' });

            for (int i = 0; i < n; i++) {
                nArray[i] = int.Parse(input[i]);
            }
            
            for (int i = 0; i < n; i++) {
                int temp = nArray[i] % m;
                var currentDp = (bool [])dp.Clone();
                for (int j = 0; j < m; j++) {
                    if (currentDp[j]) dp[(j + temp) % m] = true;
                }
                if (dp[0]) break;
                dp[temp] = true;
            }

            if(dp[0])
                Console.WriteLine("YES");
            else
                Console.WriteLine("NO");

#if DEBUG
            Console.ReadKey();
#endif
        }
    }
}
