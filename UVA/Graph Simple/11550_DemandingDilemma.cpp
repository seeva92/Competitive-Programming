#include <bits/stdc++.h>
using namespace std;
int main() {
#ifndef ONLINE_JUDGE
	freopen("1.txt", "r", stdin);
	freopen("2.txt", "w", stdout);
#endif
	int t, n, m, idx, i, j;
	int arr[9][9];
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &n, &m);
		vector<vector<int>> e(m);
		memset(arr, 0, sizeof arr);
		for (i = 1; i <= n; i++)
			for (j = 0; j < m; j++) {
				scanf("%d", &idx);
				if (idx == 1) e[j].push_back(i);
			}
		for (j = 0; j < m; j++) {
			if ((int)e[j].size() == 2 && arr[e[j][0]][e[j][1]] == 0 && arr[e[j][1]][e[j][0]] == 0) {
				arr[e[j][0]][e[j][1]] = 1; arr[e[j][1]][e[j][0]] == 1;
			} else
				break;
		}
		if (j == m) printf("Yes\n");
		else printf("No\n");
	}

}