using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DataStructures.Stack {
    public class Stack<T> : IEnumerable<T> where T : struct {

        /// <summary>
        /// Stack Item structure
        /// </summary>
        private class Node {

            /// <summary>
            /// Generic data type to hold any type of data which is of value type
            /// </summary>
            public T data { get; set; }

            /// <summary>
            /// References the next item in the Stack
            /// </summary>
            public Node next { get; set; }
        }

        Node top;


        /// <summary>
        /// Checks if the Stack is empty
        /// </summary>
        public bool IsEmpty {
            get {
                if (top == null)
                    return true;
                return false;
            }
        }

        public int Count { get; set; }

        /// <summary>
        /// Push the data to the top of the stack
        /// </summary>
        /// <param name="data"></param>
        public void Push (T data) {
            if (IsEmpty) {
                top = new Node();
                top.data = data;
            } else {
                var newNode = new Node();
                newNode.data = data;
                newNode.next = top;
                top = newNode;
            }

        }

        /// <summary>
        /// Pop out the top item in the Stack
        /// </summary>
        public void Pop () {
            if (IsEmpty)
                return;

            var temp = top;
            top = top.next;
            temp = null;
        }


        /// <summary>
        /// Prints the elements in the Stack
        /// </summary>
        public void Display () {
            var temp = top;
            while (temp != null) {
                Console.WriteLine(temp.data);
                temp = temp.next;
            }
        }

        /// <summary>
        /// This method implements the GetEnumerator method. It allows 
        ///  an instance of the class to be used in a foreach statement.
        /// </summary>
        /// <returns></returns>
        public IEnumerator<T> GetEnumerator () {
            for (var temp = top; temp != null; temp = temp.next) {
                yield return temp.data;
            }
        }

        IEnumerator IEnumerable.GetEnumerator () {
            return GetEnumerator();
        }

    }
}
