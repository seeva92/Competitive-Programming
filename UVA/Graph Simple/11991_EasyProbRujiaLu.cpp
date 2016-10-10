#include <bits/stdc++.h>
using namespace std;
const int size = (int)1e6 + 10;
vector<vector<int>> mp(size);
int main() {
#ifndef ONLINE_JUDGE
	freopen("1.txt", "r", stdin);
	freopen("2.txt", "w", stdout);
#endif
	int n, m, x, i, k, v;
	while (scanf("%d %d", &n, &m) != EOF) {
		fill(mp.begin(),mp.end(),vector<int>());
		for (i = 1; i <= n; i++) {scanf("%d", &x); mp[x].push_back(i);}
		for (i = 0; i < m; i++) {
			scanf("%d %d", &k, &v);
			if ((int)mp[v].size() > 0 && k <= (int)mp[v].size() ) {
				printf("%d\n", mp[v][k - 1]);
			} else
				printf("0\n");
		}
	}

}