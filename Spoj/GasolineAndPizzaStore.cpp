#include <bits/stdc++.h>
typedef long long ll;
const ll INF = 1e9 + 7;
const int MAX = 1e5 + 7;
using namespace std;
typedef vector<int> vi;
int t, n, m;
ll G[507][507];
ll a, b, l;
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
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++) {
				G[i][j] = INF;
			}

		for (int i = 0; i < m; i++) {
			cin >> a >> b >> l;
			G[a][b] = min(G[a][b], l);
			G[b][a] = G[a][b];
		}

		for (int k = 0; k < n; k++)
			for (int i = 0; i < n; i++)
				for (int j = 0; j < n; j++) {
					G[i][j] = min(G[i][j], G[i][k] + G[k][j]);
				}

		ll res = 0;
		for (int i = 0; i < n; i++)
			for (int j = i + 1; j < n; j++) {
				res = max(res, G[i][j]);
			}
		if (res == INF) cout << -1 << '\n';
		else cout << res << '\n';
	}
}
