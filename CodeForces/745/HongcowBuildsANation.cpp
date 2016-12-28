#include <bits/stdc++.h>
typedef long long ll;
const int mod = 1e9 + 7;
const int MAX = 1e5 + 7;
using namespace std;
typedef vector<int> vi;
bool gov[1007];
set<int> g[1007];
bool vis[1007];
class HongcowBuildsANation
{
	int n, m, k, x, u, v;
	ll cnt = 0;
	ll res = 0;
	bool isgov = false;
	ll result = 0;
public:
	void dfs(int i) {
		if (vis[i]) return;
		if (gov[i]) {
			isgov = true;
		}
		vis[i] = true; cnt++;
		for (auto j : g[i]) {
			if (!vis[j]) dfs(j);
		}
	}

	void compute() {
		int totex = 0;
		for (int i = 1; i <= n; i++) {
			if (!vis[i]) {
				isgov = false;  cnt = 0;
				dfs(i);
				if (isgov) {
					res = max(res, cnt);
					result += (cnt * (cnt - 1)) / 2;
				} else {
					totex += cnt;
				}
			}
		}
		result -= (res * (res - 1)) / 2;
		res += totex;
		result += (res * (res - 1)) / 2;
		cout << result - m;
	}
	void solve() {
		memset(vis, 0, sizeof vis);
		cin >> n >> m >> k;
		for (int i = 0; i < k; i++) {
			cin >> x;
			gov[x] = true;
		}
		for (int i = 0; i < m; i++) {
			cin >> u >> v;
			g[u].insert(v);
			g[v].insert(u);
		}
		compute();
	}

};
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	HongcowBuildsANation h; h.solve();
}
