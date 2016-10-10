#include <bits/stdc++.h>
const long long mod = 1e9 + 7;
using namespace std;
typedef long long ll;
int t, n, m, x, y, c;
vector<pair<ll, ll>> v[1507];
bool vis[1507];
void prims(ll i) {
	memset(vis, 0, sizeof vis);
	priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> p;
	p.push({1, i});
	long long res = 1LL;
	while (!p.empty()) {
		auto x = p.top(); ll u = x.second, w = x.first;
		p.pop();
		if (vis[u]) continue;
		vis[u] = 1;
		res = (res * w) % mod;
		for (auto i : v[u]) {
			if (!vis[i.second]) p.push({ i.first, i.second});
		}
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
	cin >> t;
	while (t--) {
		cin >> n >> m ;
		for (int i = 0; i <= n; i++) v[i].clear();
		while (m--) {
			cin >> x >> y >> c;
			v[x].push_back({c, y});
			v[y].push_back({c, x});
		}
		prims(1);
	}
}
