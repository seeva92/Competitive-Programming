#include <bits/stdc++.h>
const int mod = 1e9 + 7;
using namespace std;
int t, n, m, a, b;
int color[1007], G[1007][1007];
bool compute(int i, int c) {
	color[i] = c;
	for (int j = 1; j <= n; j++) {
		if (j != i && G[i][j]) {
			if (color[j] == 0) {
				if (!compute(j, 3 - color[i])) return 0;
			}
			if (color[j] != 3 - color[i]) return 0;
		}
	}
	return 1;
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> t;
	while (t--) {
		cin >> n >> m;
		memset(color, 0, sizeof color);
		for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) G[i][j] = 1;
		for (int i = 1; i <= m; i++) {
			cin >> a >> b; G[a][b] = G[b][a] = 0;
		}
		bool good = 1;
		for (int i = 1; i <= n; i++) {
			if (color[i] == 0)
				if (!compute(i, 1)) good = 0;
		}
		if (good) cout << "YES\n";
		else cout << "NO\n";
	}
}
