using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SegmentTree {
    class SegTree {
        int[] data;
        int[] input;
        public SegTree (int[] a) {
            input = a;
            int size = a.Length;
            double height = Math.Ceiling(Math.Log(size, 2));
            double no_elements = Math.Ceiling(Math.Pow(2, height));
            double memory = 2 * ((int)no_elements) - 1;
            size = ((int)memory);
            data = new int[size];
            BuildTree(0, a.Length - 1, 0);
        }
        public void Display () {
            foreach (var item in data) {
                Console.Write(item + " ");
            }
            Console.WriteLine();
            foreach (var item in input) {
                Console.Write(item + " ");
            }
        }
        private int BuildTree (int start, int end, int index) {
            if (start > end)
                return 0;

            if (start == end) {
                data[index] = input[start];
                return input[start];
            }
            int lsum = BuildTree(start, start + ((end - start) / 2), 2 * index + 1);
            int rsum = BuildTree(start + ((end - start) / 2) + 1, end, 2 * index + 2);
            data[index] = lsum + rsum;
            return data[index];
        }

        private int SumRangeHelper (int start, int end, int l, int r, int index) {
            if (start > end)
                return 0;
            if (l > end || r < start)
                return 0;
            if (start == end) {
                return input[start];
            }

            int lsum = SumRangeHelper(start, start + ((end - start) / 2), l, r, 2 * index);
            int rsum = SumRangeHelper(start + ((end - start) / 2) + 1, end, l, r, 2 * index + 1);
            return lsum + rsum;
        }

        public int SumRange (int l, int r) {
            return SumRangeHelper(0, input.Length, l, r, 0);
        }

        private void UpdateHelper (int start, int end, int pos, int val, int index) {
            if (start > end)
                return;
            if (start == end) {
                data[index] += val;
                input[pos] += val;
                return;
            }

            int mid = start + (end - start) / 2;
            int lsum, rsum;
            if (pos <= mid)
                UpdateHelper(start, mid, pos, val, 2 * index + 1);
            else
                UpdateHelper(mid + 1, end, pos, val, 2 * index + 2);
            data[index] = data[2 * index + 1] + data[2 * index + 2];
        }
        public void Update (int pos, int val) {
            if (pos < 0 || pos > input.Length)
                return;
            int oldValue = input[pos];
            int diff = val - oldValue;
            UpdateHelper(0, input.Length - 1, pos, diff, 0);
        }
    }
}
