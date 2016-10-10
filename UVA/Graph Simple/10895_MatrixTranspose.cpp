#include <bits/stdc++.h>
using namespace std;
int main() {
#ifndef ONLINE_JUDGE
	freopen("1.txt", "r", stdin);
	freopen("2.txt", "w", stdout);
#endif
	int m, n, s, x, row, col, i, j;
	while (scanf("%d %d", &m, &n) != EOF) {
		vector < vector<pair<int, int>>> v(n + 1);
		vector<int> idx;
		for (int k = 1; k <= m; k++) {
			scanf("%d", &s); idx.clear();
			for (i = 0; i < s; i++) { scanf("%d", &x); idx.push_back(x);}
			for (i = 0; i < s; i++) {scanf("%d", &x); v[idx[i]].push_back(make_pair(k, x));}
		}
		printf("%d %d\n", n, m);
		for (i = 1; i <= n; i++) {
			if ((int)v[i].size() > 0) {
				printf("%d", v[i].size());
				for (j = 0, col = (int)v[i].size(); j < col; j++) printf(" %d", v[i][j].first);
				printf("\n");
				for (j = 0, col = (int)v[i].size(); j < col - 1; j++) printf("%d ", v[i][j].second);
				printf("%d\n", v[i][j].second);
			}else printf("0\n\n");
		}
	}
}