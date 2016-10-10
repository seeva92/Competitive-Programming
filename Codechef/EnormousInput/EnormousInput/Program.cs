using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Runtime.CompilerServices;
using System.Text;
using System.Threading.Tasks;

namespace EnormousInput {
    class Program {
        const int size = 1 << 20;
        static void Main (string[] args) {
            int n, k;
            int counter = 0;
            using (var stream = Console.OpenStandardInput()) {
                byte[] buffer = new byte[size];
                int bytesRead = stream.Read(buffer, 0, size);
                string convertedBytes = Encoding.ASCII.GetString(buffer);
                string[] splitStringArray = convertedBytes.Split(new char[] { '\n' });
                string[] firstLine = splitStringArray[0].Split(new char[] { ' ' });
                n = Convert.ToInt32(firstLine[0]);
                k = Convert.ToInt32(firstLine[1]);
                int length = splitStringArray.Length;
                for (int i = 1; i < length; i++) {
                    if (Convert.ToInt32((splitStringArray[i])) % k == 0)
                        counter++;
                }
                Console.WriteLine(counter);
            }
            //    string input = Console.ReadLine();
            //string[] inputArray = input.Split(new char[] { ' ' });
            //n = Convert.ToInt32(inputArray[0]);
            //k = Convert.ToInt32(inputArray[1]);
            //int temp;
            //int counter = 0;
            //for (int i = 0; i < n; i++) {
            //    temp = Convert.ToInt32(Console.ReadLine());
            //    if (temp % k == 0)
            //        counter++;
            //}
            //Console.WriteLine(counter);

        }

        //static Stream ReadStream;
        //static int Idx, Size, BytesRead;
        //static byte[] Buffer = new byte[Size];

        //[MethodImpl(MethodImplOptions.AggressiveInlining)]
        //public static void Initialze () {
        //    ReadStream = Console.OpenStandardInput();
        //    Idx = BytesRead = 0;
        //    Size = 1 << 17;
        //    Buffer = new byte[Size];
        //}
        //[MethodImpl(MethodImplOptions.AggressiveInlining)]
        //public static int ReadInt () {
        //    byte _ReadByte;
        //    //For trimming
        //    do {
        //        _ReadByte = ReadByte();
        //    }
        //    while (_ReadByte < '-');
        //    bool neg = false;
        //    //Checking sign of number
        //    if (_ReadByte == '-') {
        //        neg = true;
        //        _ReadByte = ReadByte();
        //    }
        //    int m = _ReadByte - '0';
        //    while (true) {
        //        _ReadByte = ReadByte();
        //        if (_ReadByte < '0') break;
        //        m = m * 10 + (_ReadByte - '0');
        //    }
        //    if (neg) return -m;
        //    return m;
        //}
        //[MethodImpl(MethodImplOptions.AggressiveInlining)]
        //private static void ReadConsoleInput () {
        //    Idx = 0;
        //    BytesRead = ReadStream.Read(Buffer, 0, Size);
        //    if (BytesRead <= 0) Buffer[0] = 32;
        //}

        //[MethodImpl(MethodImplOptions.AggressiveInlining)]
        //private static byte ReadByte () {
        //    if (Idx == BytesRead) ReadConsoleInput();
        //    return Buffer[Idx++];
        //}

        //[MethodImpl(MethodImplOptions.AggressiveInlining)]
        //public static void Dispose () {
        //    ReadStream.Close();
        //}
        //static void Main (string[] args) {
        //    Initialze();
        //    int n, d, m, count = 0;
        //    m = ReadInt();
        //    d = ReadInt();
        //    while (m-- > 0) {
        //        n = ReadInt();
        //        if (n % d == 0)
        //            count++;
        //    }
        //    Dispose();
        //    Console.WriteLine(count);
        //}
    }
}
