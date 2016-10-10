/*
Author : Shivakkumar K R
File name : 316_Div2_ProbA.cs
*/
using System;
using System.Collections;
using System.Linq;
using System.Text;
using System.IO;
public class _316_Div2_ProbA {

	static void Main(string [] args) {
		//Console.SetIn(new StreamReader(File.OpenRead("C://Users//Shiva//Desktop//316_Div2_ProbA.txt")));
		var input = Console.ReadLine().Split(new char[] {' '});
		var n = int.Parse(input[0]); var m = int.Parse(input[1]);

		int [,] cityCandidate = new int[m + 1, n + 1];
		int [] wonCities = new int[n + 1];
		for (int i = 1; i <= m; i++ )
		{
			int firstMax = int.MinValue;
			input = Console.ReadLine().Split(new char[] {' '});
			for (int j = 1; j <= n; j++) {
				cityCandidate[i, j] = int.Parse(input[j - 1]);
				if (firstMax < cityCandidate[i, j]) {
					firstMax = cityCandidate[i, j];
					cityCandidate[i, 0] = j;
				}
			}

			wonCities[cityCandidate[i, 0]]++;
		}

		int secondMax = int.MinValue;
		int secondMaxIndex = 0;
		for (int i = 1; i <= n; i++)
			if (secondMax < wonCities[i]) {
				secondMax = wonCities[i];
				secondMaxIndex = i;
			}

		Console.WriteLine(secondMaxIndex);
	}
}