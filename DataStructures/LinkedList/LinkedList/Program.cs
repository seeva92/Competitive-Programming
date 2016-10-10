using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DataStructures.LinkedList{
    class Program {
        
        static void Main (string[] args) {
            LL<int> list = new LL<int>();
            list.Add(5);
            list.Add(10);
            list.Add(15);
            list.Add(20);
            list.Insert(1, 0);
            list.Insert(1, 2);
            list.Insert(1, 4);
            list.Insert(1, 6);
            list.AddBegin(5);
            list.AddBegin(10);
            list.AddEnd(56);
            foreach (var item in list) {
                Console.WriteLine(item);
            }
            list.DeleteBegin();
            list.DeleteEnd();
            list.DeleteEnd();
            list.DeleteEnd();
            list.DeleteBegin();
            list.DeleteBegin();
            list.DeleteBegin();
            list.DeleteBegin();
            list.DeleteBegin();
            list.DeleteBegin();
            list.DeleteBegin();
            list.DeleteBegin();
            list.Delete(10);
            list.Delete(20);
            list.Display();
            
            Console.ReadKey();
        }
    }
}
