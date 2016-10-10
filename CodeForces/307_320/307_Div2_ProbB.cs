using System;
using System.IO;
using System.Collections.Generic;
using System.Collections;
using System.Text;
class _307_Div2_ProbB {


	static void Main() {
		//Console.SetIn(new StreamReader(File.OpenRead("307_Div2_ProbB.txt")));
		string a = Console.ReadLine();
		string b = Console.ReadLine();
		string c = Console.ReadLine();
		int [] acount = new int[26];
		int [] bcount = new int[26];
		int [] ccount = new int[26];
		foreach (var i in a)
			acount[i - 'a']++;
		foreach (var i in b)
			bcount[i - 'a']++;
		foreach (var i in c)
			ccount[i - 'a']++;

		int bRes = int.MaxValue;
		for (int i = 0; i < 26; i++) {
			if (bcount[i] > 0) {
				bRes = Math.Min(bRes, acount[i] / bcount[i]);
			}
		}

		// int cRes = int.MaxValue;
		// for (int j = 0; j < 26; j++) {
		// 	if (ccount[j] > 0) {
		// 		cRes = Math.Min(cRes, (acount[j] - ccount[j]));
		// 	}
		// }

		int ansB = 0, ansC = 0;
		for (int i = 0; i <= bRes; i++) {
			int cRes = int.MaxValue;
			for (int j = 0; j < 26; j++) {
				if (ccount[j] > 0) {
					cRes = Math.Min(cRes, (acount[j] - (bcount[j] * i)) / ccount[j]);
				}

			}
			if ((i + cRes) > (ansB + ansC)) {
				ansB = i; ansC = cRes;
			}
		}

		// Console.Write(ansB + " " + ansC);
		for (int i = 0; i < ansB; i++)
			Console.Write(b);
		for (int i = 0; i < ansC; i++)
			Console.Write(c);
		for (int i = 0; i < 26; i++) {
			for (int j = 0; j < (acount[i] - (bcount[i]*ansB) - (ccount[i]*ansC)); j++)
				Console.Write((char)(i + 'a'));
		}


	}
}