using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LongestIncSubsequence {
    class Program {//3, 4
        static int LISRec (int[] a, int n, ref int result) {
            if (n == 1)
                return 1;
            int sum = 0, max_end = 1;
            for (int i = 1; i < n; i++) {
                sum = LISRec(a, i, ref result);
                if (a[i - 1] < a[n - 1] && sum + 1 > max_end)
                    max_end = sum + 1;
            }

            if (max_end > result)
                result = max_end;
            return max_end;
        }

        static int[] mem = new int[100];
        static int LISMem (int[] a, int n, ref int result) {
            if (n == 1)
                return 1;

            if (mem[n] != -1) {
                if (result < mem[n])
                    result = mem[n];
                return mem[n - 1];
            }

            int sum = 0, max_end = 1;
            for (int i = 1; i < n; i++) {
                sum = LISRec(a, i, ref result);
                if (a[i - 1] < a[n - 1] && sum + 1 > max_end)
                    max_end = sum + 1;
            }

            if (max_end > result) {
                mem[n] = max_end;
                result = max_end;
            }

            return max_end;
        }

        static int LISDp (int[] a) {
            int[] dp = new int[a.Length + 1];
            for (int i = 0; i < dp.Length; i++) {
                dp[i] = 1;
            }

            for (int i = 1; i < a.Length; i++) {
                for (int j = 0; j < i; j++) {
                    if (a[j] < a[i] && dp[j] + 1 > dp[i])
                        dp[i] = dp[j] + 1;
                }
            }

            return dp[a.Length - 1];
        }
        static void Main (string[] args) {
            int[] a = { 10, 10, 11, 5, 12, 0,8,9,10, 13 };
            int res = 0;
            Console.WriteLine(LISRec(a, a.Length, ref res));

            res = 0;
            for (int i = 0; i < Program.mem.Length; i++) {
                mem[i] = -1;
            }
            Console.WriteLine(LISMem(a, a.Length, ref res));

            Console.Write(LISDp(a));
        }
    }
}
