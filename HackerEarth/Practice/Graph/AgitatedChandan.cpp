#include <bits/stdc++.h>
const int mod = 1e9 + 7;
using namespace std;
typedef vector<int> vi;
int t, n, a, b, w;
vector<pair<int, int>> g[100007];
int vis[100007];
int temp;
int dfs(int i, int & res) {
	vis[i] = 1;
	int fm = 0, sm = 0;
	for (auto j : g[i]) {
		if (!vis[j.first]) {
			temp = dfs(j.first, res);
			temp += j.second;
			// int temp = j.second + dfs(j.first, res);
			if (fm < temp) {
				sm = fm;
				fm = temp;
			} else if (sm < temp) {
				sm = temp;
			}
		}
	}
	if (res < fm + sm) res = fm + sm;
	return fm > sm ? fm : sm;

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
		memset(vis, 0, sizeof vis);
		cin >> n;
		for (int i = 0; i < n - 1; i++) {
			cin >> a >> b >> w;
			g[a].push_back({b, w});
			g[b].push_back({a, w});
		}
		int res = 0;
		dfs(1, res);
		for (int i = 1; i <= n; i++) {
			g[i].clear();
		}

		if (res > 10000) cout << 10000 << " " << res;
		else if (res > 1000) cout << 1000 << " " << res;
		else if (res > 100) cout << 100 << " " << res;
		else cout << 0 << " " << res;
		cout << '\n';
	}
}
