using System;
using System.IO;
class _308_Div2_ProbD {
	static void Main() {
		Console.SetIn(new StreamReader(File.OpenRead("308_Div2_ProbD.txt")));
		int n = int.Parse(Console.ReadLine());
		int [] xarr = new int[n];
		int [] yarr = new int[n];
		string [] input;
		for (int i = 0; i < n; i++)
		{
			input = Console.ReadLine().Split(new char[] {' '});
			xarr[i] = int.Parse(input[0]);
			yarr[i] = int.Parse(input[1]);
		}
		int count = 0;
		double val = 0;
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				for (int k = j + 1; k < n; k++) {
					val = xarr[i] * (yarr[j] - yarr[k]) + xarr[j] * (yarr[k] - yarr[i]) + xarr[k] * (yarr[i] - yarr[j]);
					val = val / 2;
					if (val > 0)
						count++;
				}
			}
		}



		Console.WriteLine(count);


	}
}