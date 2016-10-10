using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DataStructures.Queue {
    internal class Queue<T> : IEnumerable<T> where T : struct{
        private class Node {
            public T data { get; set; }
            public Node next { get; set; }
        }
        private Node front, rear;

        /// <summary>
        /// Check if the queue is empty
        /// </summary>
        public bool IsEmpty {
            get {
                if (front == null)
                    return true;
                return false;
            }
        }


        /// <summary>
        /// Adds the item to the queue
        /// </summary>
        /// <param name="data"></param>
        public void Enqueue(T data) {
            if (IsEmpty) {
                front = new Node();
                rear = front;
                front.data = data;
            } else {
                var temp = new Node();
                temp.data = data;
                rear.next = temp;
                rear = temp;
            }
        }

        /// <summary>
        /// Dequeues the item from the queue
        /// </summary>
        public void Dequeue() {
            if (IsEmpty)
                return;

            var temp = front;
            front = front.next;
            temp = null;
        }

        public IEnumerator<T> GetEnumerator () {
            for(var temp = front; temp!= null; temp = temp.next) {
                yield return temp.data;
            }
        }

        IEnumerator IEnumerable.GetEnumerator () {
            return GetEnumerator();
        }
    }
}
