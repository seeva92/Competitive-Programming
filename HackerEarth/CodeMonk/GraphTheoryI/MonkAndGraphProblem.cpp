#include <bits/stdc++.h>
typedef long long ll;
const int mod = 1e9 + 7;
const int MAX = 1e5 + 7;
using namespace std;
typedef vector<int> vi;
vector<int> g[MAX];
bool vis[MAX];
vector<int> nodes;
void dfs(int i) {
	if (vis[i]) return;
	vis[i] = true;
	nodes.push_back(i);
	for (auto j : g[i]) {
		if (!vis[j]) dfs(j);
	}
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	memset(vis, 0, sizeof vis);
	int n, m; cin >> n >> m;
	int x, y;
	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	int res = 0;
	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			nodes.clear();
			dfs(i);
			int tot = 0;
			for (auto j : nodes) {
				tot += (int)g[j].size();
			}
			res = max(res, tot / 2);
		}
	}
	cout << res;
}
