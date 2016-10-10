#include <iostream>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <deque>
#include <sstream>
#include <set>
#include <climits>
#include <cstdio>
#include <string>
#include <map>
#include <unordered_map>
using namespace std;
char textend[] = "****END_OF_TEXT****";
char inputend[] = "****END_OF_INPUT****";
char str[25];
char *p;
string pr;
inline string normalise(string tr) {
	for (int i = 0; i < tr.size(); i++)
		tr[i] = tolower(tr[i]);
	return tr;
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("1.txt", "r", stdin);
	freopen("2.txt", "w", stdout);
#endif
	while (scanf("%s", &str), strcmp(str, inputend) != 0) {
		int lambda = 0;
		map<string, int> count;
		double et = 0.0, erel = 0.0, emax = 0.0;
		double logone = double(log10(1));
		while (strcmp(str, textend) != 0) {

			p = strtok((char *)str, ",.:;!?\"\t() \n\0");
			while (p) {
				pr = normalise(p);
				count[pr]++;
				lambda++;
				p = strtok(NULL, ",.:;!?\"\t() \n\0");
			}


			scanf("%s", &str);
		}
		emax = log10(lambda);


		for (auto it : count) {
			et += (it.second) * (log10(lambda) - log10(it.second));
		}
		et /=  (double)lambda;
		erel = (et * 100) / emax;
		if (lambda == 0)
			printf("0 0.0 0");
		else
			printf("%d %.1lf %.0lf\n", lambda, et, et * 100 / emax);
		// printf("%d %.1f %d\n", lambda, et, (int)erel);



	}
}


