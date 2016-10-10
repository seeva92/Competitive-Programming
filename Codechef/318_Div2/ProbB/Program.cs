using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ProbB {
    
    public class Program {

        static void Main (string[] args) {
            bool [,] knownPair = new bool[4003, 4003];
            int[] first = new int[4003];
            int[] second = new int[4003];
            int[] known = new int[4003];
#if DEBUG
            var input = new StreamReader(File.OpenRead("C:\\Users\\Shiva\\Desktop\\318Div2B.txt"));
            Console.SetIn(input);

#endif
            var firstLine = Console.ReadLine().Split(new char[] { ' ' });
            var NoWarriors = int.Parse(firstLine[0]); var KnownPairCount = int.Parse(firstLine[1]);

            for (int i = 0; i < KnownPairCount; i++) {
                var line = Console.ReadLine().Split(new char[] { ' ' });
                var key = int.Parse(line[0]); var value = int.Parse(line[1]);

                knownPair[key,value] = true;
                knownPair[value, key] = true;
                first[i] = key;
                second[i] = value;
                known[key]++;
                known[value]++;
            }

            long currMin = int.MaxValue;
            for (int i = 0; i < NoWarriors; i++) {
                for (int j = 0; j < KnownPairCount; j++) {
                    if(first[j]!=i && second[j]!=i &&  knownPair[i,first[j]] && knownPair[i, second[j]]) {
                        currMin = Math.Min(currMin, known[i] + known[first[j]] + known[second[j]] - 6);
                    }
                }
            }

            if (currMin == int.MaxValue) {
                Console.WriteLine(-1); return;
            }
            Console.WriteLine(currMin);
#if DEBUG
            Console.ReadKey();
#endif
        }
    }
}
