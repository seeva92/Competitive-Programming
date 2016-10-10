#include <bits/stdc++.h>
const int mod = 1e9 + 7;
using namespace std;
int t, n, m, x, y, c, s, a, h;
vector< pair<int, int >> v[107];
int d[3][107];

int shortestpath() {
	int temp [] = {s, a, h};
	for (int ii = 0; ii < 3; ii++) {
		for (int i = 0; i <= 100; i++) d[ii][i] = 1e9; d[ii][temp[ii]] = 0;

		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> p;
		p.push({0, temp[ii]});
		while (!p.empty()) {
			auto pr = p.top(); p.pop();
			if (d[ii][pr.second] < pr.first) continue;
			int j = pr.second;
			for (int i = 0; i < int(v[j].size()); i++) {
				auto u = v[j][i];
				if (d[ii][u.first] > (d[ii][j] + u.second)) {
					d[ii][u.first] = d[ii][j] + u.second;

					p.push({d[ii][u.first], u.first});
				}
			}
		}
	}

	int res = 0;
	for (int i = 1; i <= n; i++) {
		if (i != s && i != a && i != h) {
			if (res < (d[0][i] + (2 * d[1][i]) + d[2][i]))
				res = (d[0][i] + (2 * d[1][i]) + d[2][i]);
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
		for (int i = 0; i <= 100; i++) { v[i].clear();}
		for (int i = 1; i <= m; i++) {
			cin >> x >> y >> c;
			v[x].push_back({y, c});
			v[y].push_back({x, c});
		}
		cin >> s >> a >> h;
		cout << shortestpath() << '\n';
	}
}
