using System;
using System.IO;
class ModuloSum {
	static void Main(String [] args) {
		//Console.SetIn(new StreamReader(File.OpenRead("C:\\Users\\Shiva\\Desktop\\319_Div2ProbB.txt")));
		var input = Console.ReadLine().Split(new char[] {' '});
		var n = int.Parse(input[0]);
		var m = int.Parse(input[1]);

		input = Console.ReadLine().Split(new char[] {' '});

		var arr = new int[n];
		for (int i = 0; i < n; i++)
			arr[i] = int.Parse(input[i]);
		input = null;
		var dpArray = new bool[m];

		for (int i = 0; i < n; i++)
		{
			var currArray = (bool [])dpArray.Clone();
			int temp = arr[i] % m;
			for (int j = 0; j < m; j++)
				if (currArray[j]) dpArray[(j + temp) % m] = true;
			dpArray[temp] = true;
			if (dpArray[0]) { Console.WriteLine("YES"); return;}
		}

		Console.WriteLine("NO");
	}
}
