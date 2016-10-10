using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Security.Cryptography;
using System.IO;

namespace TrieDa {
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
            var trie = new Trie();
            var wordsList = new List<string>();
            using(var stream = new StreamWriter(File.OpenWrite("C:\\Users\\Shiva\\Desktop\\Oruvan.txt"))) {
                Console.SetOut(stream);

                for (int i = 0; i < 10000; i++) {
                    var str = RandomString();
                    trie.Insert(str);
                    wordsList.Add(str);
                    Console.WriteLine(str);
                }
                Console.WriteLine(trie.Count);
                Console.ReadKey();

                trie.Display();
                Console.ReadKey();
                Console.WriteLine();

                for (int i = 0; i < 10; i++) {
                    trie.Delete(wordsList[i]);
                    Console.WriteLine();

                }

                trie.Display();
                Console.ReadKey();
            }
            
        }
    }
}
