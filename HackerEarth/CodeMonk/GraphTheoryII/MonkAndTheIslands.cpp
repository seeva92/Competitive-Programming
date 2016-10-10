#include <bits/stdc++.h>
const int INF = 1e9;
const int mod = INF + 7;
using namespace std;
int t, n, m, x, y;
vector<int> v[100007];
int d[100007];

void compute() {

	for (int i = 0; i <= n; i++) d[i] = INF;

	queue<int> q; q.push(1);
	d[1] = 0;
	while (!q.empty()) {
		int x = q.front(); q.pop();
		for (int i = 0; i < int(v[x].size()); i++) {
			if (d[v[x][i]] == INF) {
				d[v[x][i]] = d[x] + 1;
				q.push(v[x][i]);
			}
		}
	}
	cout << d[n] << '\n';
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
			cin >> x >> y;
			v[x].push_back(y);
			v[y].push_back(x);
		}
		compute();
	}

}
