using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Fibo {

    class Program {
        static int FiboRec (int n) {
            if (n <= 1)
                return n;
            return FiboRec(n - 1) + FiboRec(n - 2);
        }


        static int[] mem = new int[100];

        static int FiboMem (int n) {
            if (mem[n] != -1)
                return mem[n];

            if (n <= 1)
                return n;
            mem[n] = FiboMem(n - 1) + FiboMem(n - 2);
            return mem[n];
        }

        static int[] dp = new int[100];

        static int FiboDP(int n) {
            if (n == 0)
                return 0;
            if (n == 1)
                return 1;
            int length = dp.Length;
            for (int i = 0; i < length; i++) {
                dp[i] = 0;
            }

            dp[0] = 0; dp[1] = 1;
            for (int i = 2; i <= n; i++) {
                dp[i] = dp[i - 1] + dp[i - 2];
            }

            return dp[n];
        }
        static void Main (string[] args) {
            for (int i = 0; i < 35; i++)
                Console.WriteLine(FiboRec(i));

            int length = Program.mem.Length;
            for (int i = 0; i < length; i++)
                mem[i] = -1;

            for (int i = 0; i < 35; i++) {
                for (int j = 0; j < length; j++)
                    mem[j] = -1;
                Console.WriteLine(FiboMem(i));

            }

            for (int i = 0; i < 35; i++)
                Console.WriteLine(FiboDP(i));

            Console.ReadKey();
        }
    }
}
