using System;
using System.Collections.Generic;
using System.Linq;
using System.Security.Cryptography;
using System.Text;
using System.Threading.Tasks;

namespace TernarySearchTree {
    class Program {
        public const string RANDOM_CHARS = "shiva";// fghijklmnopqrstuvwxyz";
        static RNGCryptoServiceProvider rng = new RNGCryptoServiceProvider();


        static string RandomString () {
            var chars = RANDOM_CHARS.ToCharArray();
            var byteArray = new byte[5];
            rng.GetBytes(byteArray);
            StringBuilder result = new StringBuilder(RANDOM_CHARS.Length);
            foreach (byte b in byteArray) {
                result.Append(RANDOM_CHARS[b % RANDOM_CHARS.Length]);
            }
            return result.ToString();
        }

        static void Main (string[] args) {
            var tst = new TST();

            var list = new List<string>();
            for(int i = 0; i < 10; i++) {
                list.Add(RandomString());
                tst.Insert(list[i]);
            }
            Console.WriteLine();
            foreach (var item in list) {
                Console.WriteLine(item);
            }
            Console.WriteLine();

            tst.Display();

            for (int i = 0; i < list.Count-5; i++) {
                tst.Delete(list[i]);
            }

            Console.WriteLine();
            tst.Display();

            foreach (var item in list) {
                tst.Insert(item);
            }
            Console.WriteLine();
            tst.Display();
            Console.ReadKey();
        }
    }
}
