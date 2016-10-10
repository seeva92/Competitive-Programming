#include <bits/stdc++.h>
const int mod = 1e9 + 7;
const int INF = 1e9;
using namespace std;
int t, n, m, x, y, q, k, c, a;
vector < pair<int, int >> v[10007];
int dist[10007];
void compute() {
	for (int i = 0; i <= n; i++) dist[i] = INF;
	dist[1] = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int> >> q;
	q.push({0, 1});
	while (!q.empty()) {
		auto t = q.top(); q.pop();
		if (dist[t.second] < t.first) continue;
		int i = t.second;
		for (int j = 0; j < int(v[i].size()); j++) {
			if (dist[i] != INF && (dist[v[i][j].first] > (dist[i] + v[i][j].second))) {
				dist[v[i][j].first] = dist[i] + v[i][j].second;
				q.push({dist[v[i][j].first], v[i][j].first});
			}
		}
	}
	// for (int i = 1; i <= n; i++) cout << dist[i] << " ";
	// cout << '\n';
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
		for (int i = 0; i <= n; i++) v[i].clear();

		for (int i = 1; i <= m; i++) {
			cin >> x >> y >> c;
			v[x].push_back({y, c});
			v[y].push_back({x, c});
		}
		compute();
		cin >> q;
		while (q--) {
			cin >> a >> k;
			if (k > (2 * dist[a]))
				cout << k - (2 * dist[a]);
			else cout << 0;
			cout << '\n';
		}
	}
}
