using System;
using System.Collections;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ProbB {
    class Order {
        public char direction;
        public int count;
        public int price;
        public long total;


    }

    class OrderComparer : IComparer<Order> {
        public int Compare (Order x, Order y) {
            if (x.direction < y.direction)
                return 1;
            else if (x.direction == y.direction) {
                if (x.price < y.price)
                    return 1;
                else if (x.price > y.price)
                    return -1;
                else
                    return 0;
            }
            return -1;
        }
    }
    class Program {

        static void Main (string[] args) {
#if DEBUG
            Console.SetIn(new StreamReader(File.OpenRead("C:\\Users\\Shiva\\Desktop\\317Div2B.txt")));
#endif
            int n, s;
            var first = Console.ReadLine().Split(new char[] { ' ' });
            n = int.Parse(first[0]); s = int.Parse(first[1]);

            Order[] orders = new Order[n];
            for (int i = 0; i < n; i++) {
                var line = Console.ReadLine().Split(new char[] { ' ' });
                orders[i] = new Order();
                orders[i].direction = char.Parse(line[0]);
                orders[i].count = int.Parse(line[2]);
                orders[i].price = int.Parse(line[1]);
                orders[i].total = orders[i].price * ((long)orders[i].count);
            }

            var items = orders.OrderBy(o => o, new OrderComparer()).ToArray();

            int len = items.Length;
            List<Order> aggregatedOrders = new List<Order>();
            aggregatedOrders.Add(items[0]);

            for (int i = 1, k = 0; i < len; i++) {
                if (aggregatedOrders[k].direction == items[i].direction && aggregatedOrders[k].price == items[i].price) {
                    aggregatedOrders[k].count += items[i].count;
                    aggregatedOrders[k].total = aggregatedOrders[k].count * aggregatedOrders[k].price;
                } else {
                    aggregatedOrders.Add(items[i]);
                    k++;
                    aggregatedOrders[k].total = aggregatedOrders[k].count * aggregatedOrders[k].price;

                }
            }
            aggregatedOrders.Sort(new OrderComparer());
            //foreach (var item in aggregatedOrders) {
            //    Console.WriteLine(item.direction + " " + item.price + " " + item.count + " " + item.total);
            //}

            var Sorders = aggregatedOrders.Where(si => si.direction == 'S').ToArray();
            var Borders = aggregatedOrders.Where(b => b.direction == 'B').ToArray();


            int temp = 2 * s;
            int j = 0;
            int length = Sorders.Length;
            int idx = Sorders.Length - s;
            if (idx < 0)
                idx = 0;
                
            for (; idx < length && j < temp; idx++, j++) {
                Console.WriteLine(Sorders[idx].direction + " " + Sorders[idx].price + " " + Sorders[idx].count);
            }
            length = Borders.Length;
            for (int i = 0; i<length && i < s && j < temp; i++, j++) {
                Console.WriteLine(Borders[i].direction + " " + Borders[i].price + " " + Borders[i].count);
            }

#if DEBUG
            Console.ReadKey();
#endif
        }
    }
}
