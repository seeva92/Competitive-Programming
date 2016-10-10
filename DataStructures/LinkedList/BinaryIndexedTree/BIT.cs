using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BinaryIndexedTree {
    class BIT {
        int[] data;
        int[] input;
        public BIT(int[] a) {
            input = a;
            data = new int[input.Length + 2];
            BuildBIT(input);
        }

        private void BuildBIT(int [] input) {
            int len = input.Length;
            for (int i = 0; i < len; i++) {
                int index = i + 1;
                while(index<= len) {
                    data[index] += input[i];
                    index+= (index) & (-index);
                }
            }
        }

        public int GetSum(int index) {
            int sum = 0;
            index += 1;
            while (index > 0) {
                sum += data[index];

                index -= (index) & (-index);
            }

            return sum;
        }

        public void Update(int index, int val) {
            int diff = val - input[index];
            input[index] += diff;

            int len = input.Length;
            index += 1;
            while (index <= len) {
                data[index] += diff;
                index += (index) & (-index);
            }
        }
        public void Display () {
            for (int i = 0; i < data.Length; i++) {
                Console.Write(data[i]+" ");
            }
        }
    }
}
