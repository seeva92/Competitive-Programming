using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DataStructures.LinkedList {
    class LL<T> : IEnumerable<T> where T : struct {
        private class Node {
            public T data {
                get; set;
            }
            public Node next {
                get; set;
            }
        }
        private Node head;

        /// <summary>
        /// Checks if the list is empty
        /// </summary>
        /// <returns></returns>
        public bool IsEmpty () {
            return head == null ? true : false;
        }

        /// <summary>
        /// Add an item to the list
        /// </summary>
        /// <param name="data">Data to be inserted</param>
        public void Add (T data) {
            if (IsEmpty()) {
                head = new Node();
                head.data = data;
            } else {
                var temp = head;
                while (temp.next != null) {
                    temp = temp.next;
                }
                temp.next = new Node();
                temp.next.data = data;
            }
            Count++;
        }

        /// <summary>
        /// Count of items in te list
        /// </summary>
        public int Count { get; set; }

        /// <summary>
        /// Add an item to the beginning of the list
        /// </summary>
        /// <param name="data">Data to be inserted</param>
        public void AddBegin (T data) {
            if (IsEmpty()) {
                Add(data);
                return;
            }

            var temp = new Node();
            temp.data = data;
            temp.next = head;
            head = temp;
            Count++;
        }


        /// <summary>
        /// Add an item to the end of the list
        /// </summary>
        /// <param name="data">Data to be inserted</param>
        public void AddEnd (T data) {
            if (IsEmpty()) {
                Add(data);
                return;
            }

            var temp = head;
            while (temp.next != null) {
                temp = temp.next;
            }

            temp.next = new Node();
            temp.next.data = data;
            Count++;
        }


        /// <summary>
        /// Insert an item in a particular position
        /// </summary>
        /// <param name="data">Data to be inserted</param>
        /// <param name="pos">Position should be less than list size and greater than or equal to 0</param>
        public void Insert (T data, int pos) {
            if (pos < 0 || pos >= Count)
                return;
            int index = 1;
            if (pos == 0) {
                AddBegin(data);
                return;
            } else {
                var temp = head;
                while (index < pos && temp.next != null) {
                    index++;
                    temp = temp.next;
                }
                var insertingNode = new Node();
                insertingNode.data = data;

                insertingNode.next = temp.next;
                temp.next = insertingNode;
                Count++;
            }

        }


        /// <summary>
        /// Delete the first item in the list
        /// </summary>
        public void DeleteBegin () {
            if (IsEmpty())
                return;

            var temp = head;
            head = head.next;
            temp = null;

            Count--;

        }

        /// <summary>
        /// Delete the last item in the list
        /// </summary>
        public void DeleteEnd () {
            if (IsEmpty()) {
                return;
            }

            var temp = head;
            while (temp.next.next != null)
                temp = temp.next;

            temp.next = null;
            Count--;
        }

        /// <summary>
        /// Deletes the item in the list for the position given
        /// </summary>
        /// <param name="pos">Position of the item</param>
        public void Delete (int pos) {

            if (pos < 0 || pos >= Count)
                return;
            if (pos == 0) {
                DeleteBegin();
                return;
            } else {
                int index = 1;
                var temp = head;
                while (index < pos && temp.next != null) {
                    index++;
                    temp = temp.next;
                }

                var deletingNode = temp.next;
                temp.next = deletingNode.next;
                deletingNode = null;

                Count--;
            }
        }

        /// <summary>
        /// Prints the list
        /// </summary>
        public void Display () {
            if (IsEmpty()) {
                return;
            }

            var temp = head;
            while (temp != null) {
                Console.WriteLine(temp.data);
                temp = temp.next;
            }
        }

        public IEnumerator<T> GetEnumerator () {
            for(var temp = head;temp!= null;temp = temp.next) {
                yield return temp.data;
            }
        }

        IEnumerator IEnumerable.GetEnumerator () {
            return GetEnumerator();
        }

    }
}
