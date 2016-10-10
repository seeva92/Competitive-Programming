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
int stamps[int(1e4 + 2)];
int main() {
#ifndef ONLINE_JUDGE
	freopen("1.txt", "r", stdin);
	freopen("2.txt", "w", stdout);
#endif
	int k, n, m, x;
	vector<set<int>> v;
	set<int> tmp;
	set<int> unique;
	scanf("%d", &k); int count = 0; int ind = 0;
	double d = 0.0;
	for (int i = 0; i < k; i++) {
		scanf("%d", &n);
		memset(stamps, 0, sizeof stamps);
		v.clear();
		unique.clear();
		count = 0;
		for (int j = 0; j < n; j++) {
			scanf("%d", &m); tmp.clear();
			for (int l = 0; l < m; l++) {
				scanf("%d", &x);
				tmp.insert(x);
			}
			v.push_back(tmp);
			for (auto it : tmp) {
				stamps[it]++;
				if (stamps[it] == 1)
					count++;
				else if (stamps[it] - 1 == 1)
					count--;
			}
		}
		printf("Case %d: ", i + 1);
		int y = 0;
		for (auto it : v) {
			ind = 0;
			for (auto it1 : it) {
				if (stamps[it1] == 1)
					ind++;
			}
			d = double(ind) / double(count) * 100;
			if (y++ == 0) {
				if (d == d)
					printf("%0.6f%%", double(ind) / double(count) * 100);
			} else {
				if (d == d)
					printf(" %0.6f%%", double(ind) / double(count) * 100);
			}

		}
		printf("\n");
	}
}


