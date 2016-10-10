#include <bits/stdc++.h>
const int mod = 1e9 + 7;
using namespace std;
int t, n, m, x, y, c, s, a, h;
int d[107][107];
int shortestpath() {
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++) {
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
			}

	int res = 0;
	for (int i = 1; i <= n; i++) {
		if (i != s && i != a && i != h) {
			if (res < (d[s][i] + (2 * d[a][i]) + d[h][i]))
				res = (d[s][i] + (2 * d[a][i]) + d[h][i]);
		}
	}

	return res;
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
		for (int i = 0; i < 101; i++) for (int j = 0; j < 101; j++) d[i][j] = 1e9;
		for (int i = 1; i <= m; i++) {
			cin >> x >> y >> c;
			if (d[x][y] > c) {
				d[x][y] = c ;
				d[y][x] = c;
			}
		}
		cin >> s >> a >> h;
		cout << shortestpath() << '\n';
	}
}
