#include <bits/stdc++.h>
const int mod = 1e9 + 7;
using namespace std;
typedef vector<int> vi;
int q, n, m, u, v;
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> q;
	while (q--) {
		cin >> n >> m;
		vector<int> g[1007], vis(n + 1, 0), dis(n + 1, -1);
		for (int i = 0; i < m; i++) {
			cin >> u >> v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		int s; cin >> s;
		queue<int> q; q.push(s); dis[s] = 0; vis[s] = 1;
		while (!q.empty()) {
			int p = q.front(); q.pop();
			for (auto j : g[p]) {
				if (!vis[j]) {
					q.push(j);
					dis[j] = dis[p] + 6;
					vis[j] = 1;
				}
			}
		}
		for (int i = 1; i <= n; i++) {
			if (i != s) cout << dis[i] << " ";
		}
		cout << '\n';
	}
}
