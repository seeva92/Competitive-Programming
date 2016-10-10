#include <bits/stdc++.h>
typedef long long ll;
const int mod = 1e9 + 7;
const int MAX = 1E6 + 7;
using namespace std;
ll R, P, r1, r2, t;
vector<ll> g[MAX];
vector<pair<ll, ll>> v[MAX];
bool vis[MAX];
ll dis[MAX];
vector<ll> topo;
void dfs(ll i) {
	vis[i] = 1;
	for (auto j : g[i]) {
		if (!vis[j]) dfs(j);
	}
	topo.push_back(i);
}
void compute() {
	memset(vis, 0, sizeof vis);
	memset(dis, 0, sizeof dis);
	for (int i = 1; i <= R; i++) {
		if (!vis[i]) dfs(i);
	}
	reverse(topo.begin(), topo.end());
	ll res = 0;
	for (auto x : topo) {
		for (auto y : v[x]) {
			dis[x] = max(dis[x], 2 + dis[y.first] + y.second);
		}
		res = max(res, dis[x]);
	}
	cout << res << '\n';
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> R >> P;
	for (int i = 1; i <= P; i++) {
		cin >> r1 >> r2 >> t;
		g[r1].push_back(r2);
		v[r2].push_back({r1, t});
	}
	compute();
}
