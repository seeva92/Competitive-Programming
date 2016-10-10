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
char str[500];
string binder, ck;
char ing[200], req[200];
int t, m, n, b, c, k, x;

bool compare(pair<string, int> a, pair<string, int> b) {
	if (a.second < b.second)
		return true;
	else if (a.second == b.second) {
		return a.first <= b.first;
	}
	return false;
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("1.txt", "r", stdin);
	freopen("2.txt", "w", stdout);
#endif

	gets(str);
	sscanf(str, "%d", &t);
	map<string, int> price;
	for (int i = 0; i < t; i++) {
		gets(str);
		binder = string(str);

		gets(str);
		sscanf(str, "%d %d %d", &m, &n, &b);
		price.clear();
		for (int j = 0; j < m; j++) {
			gets(str);
			sscanf(str, "%s %d", &ing, &c);
			price[ing] = c;
		}
		vector<pair<string, int>> cakes;

		for (int l = 0; l < n; l++) {
			gets(str);
			ck = string(str);
			gets(str);
			sscanf(str, "%d", &k);
			int total = 0;
			for (int m = 0; m < k; m++) {
				gets(str);
				sscanf(str, "%s %d", req, &x);
				total += price[req] * x;
			}
			if (total <= b)
				cakes.push_back(make_pair(ck, total));
		}

		sort(cakes.begin(), cakes.end(), compare);
		int len = binder.length();
		for (int z = 0; z < len; z++)
			binder[z] = toupper(binder[z]);
		printf("%s\n", binder.c_str());
		for (auto it : cakes)
			printf("%s\n", it.first.c_str());
		if (cakes.size() == 0)
			printf("Too expensive!\n");
		printf("\n");
	}
}


