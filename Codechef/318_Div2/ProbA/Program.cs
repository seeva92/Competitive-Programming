using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;


namespace ProbA {

    class Program {
        static void Main (string[] args) {
            int[] voteArray = new int[102];
            int[] copiedArray = new int[102];

            int n = int.Parse(Console.ReadLine());
            string[] voteStringArray = Console.ReadLine().Split(new char[] { ' ' });

            for (int i = 1; i <= n; i++) {
                voteArray[i] = int.Parse(voteStringArray[i - 1]);
            }
            Array.Copy(voteArray, 2, copiedArray, 2, n - 1);
            Array.Sort(copiedArray, new Comparison<int>((first, second) => second.CompareTo(first)));

            int LimaVotes = voteArray[1];
            int CurrMax = copiedArray[0];   
            int BribedVotes = 0;

            while (LimaVotes + BribedVotes <= copiedArray[0]) {
                BribedVotes += 1;
                copiedArray[0] -= 1;
                Array.Sort(copiedArray, new Comparison<int>((first, second) => second.CompareTo(first)));
            }
            Console.WriteLine(BribedVotes);
        }
    }
}
