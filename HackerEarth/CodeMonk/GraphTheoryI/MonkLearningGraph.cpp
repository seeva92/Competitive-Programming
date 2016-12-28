#include <bits/stdc++.h>
typedef long long ll;
const int mod = 1e9 + 7;
const int MAX = 1e5 + 7;
using namespace std;
typedef vector<int> vi;
vector<pair<int, int>> g[1007];
int val[1007];
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		cin >> val[i];
	}
	int x, y;
	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		g[x].push_back({val[y], y});
		g[y].push_back({val[x], x});
	}
	for (int i = 1; i <= n; i++) {
		sort(g[i].begin(), g[i].end(), greater<pair<int, int>>());
		if (g[i].size() < k) cout << -1;
		else cout << g[i][k - 1].second << '\n';
	}
}
