using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
namespace LongestCommSubsequence {
    class Program {
        static int LCSRec (string first, string second, int n, int m) {
            if (n < 0 || m < 0)
                return 0;

            if (first[n] == second[m]) {
                return 1 + LCSRec(first, second, n - 1, m - 1);

            }

            return Math.Max(LCSRec(first, second, n - 1, m), LCSRec(first, second, n, m - 1));
        }

        static int[,] mem = new int[100, 100];
        static int LCSMem (string first, string second, int n, int m) {
            if (n < 0 || m < 0)
                return 0;
            if (mem[n, m] != -1) {
                return mem[n, m];
            }

            if (first[n] == second[m]) {
                mem[n, m] = 1 + LCSMem(first, second, n - 1, m - 1);
                return mem[n, m];
            }

            mem[n, m] = Math.Max(LCSMem(first, second, n - 1, m), LCSMem(first, second, n, m - 1));
            return mem[n, m];
        }

        static int LCSDp (string first, string second) {
            int[,] dp = new int[first.Length + 2, second.Length + 2];
            for (int i = 0; i < dp.GetLength(0); i++)
                for (int j = 0; j < dp.GetLength(1); j++)
                    dp[i, j] = 0;

            for (int i = 0; i <= first.Length; i++) {
                for (int j = 0; j <= second.Length; j++) {
                    if (i == 0 || j == 0)
                        continue;
                    else if (first[i - 1] == second[j - 1])
                        dp[i, j] = dp[i - 1, j - 1] + 1;
                    else {
                        dp[i, j] = Math.Max(dp[i - 1, j], dp[i, j - 1]);
                    }
                }
            }


            return dp[first.Length,second.Length];
        }
        static void Main (string[] args) {
            string first = "Sivakumar";
            string second = "Sivaranjani";
            var list = new List<char>();
            Console.WriteLine(LCSRec(first, second, first.Length - 1, second.Length - 1));


            for (int i = 0; i < mem.GetLength(0); i++) {
                for (int j = 0; j < mem.GetLength(1); j++) {
                    mem[i, j] = -1;
                }
            }
            Console.WriteLine(LCSMem(first, second, first.Length - 1, second.Length - 1));
            Console.WriteLine(LCSDp(first, second));

        }
    }
}
