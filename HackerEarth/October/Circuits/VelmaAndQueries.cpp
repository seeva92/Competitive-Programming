#include <bits/stdc++.h>
const int mod = 1e9 + 7;
using namespace std;
typedef vector<int> vi;
typedef long long ll;
ll T, N, Q, u, v;
ll iter;
ll arr[100007], vis[100007];
pair<ll, ll> rangeIdx[100007];
set<ll> g[100007];
vector<ll> idx[100007], tot[100007];
void dfs(ll i, ll l) {
	if (vis[i]) return;
	vis[i] = 1;
	rangeIdx[i].first = iter++;

	idx[l].push_back(rangeIdx[i].first);
	if (tot[l].empty()) tot[l].push_back(arr[i]);
	else tot[l].push_back(tot[l].back() + arr[i]);

	for (auto j : g[i]) {
		if (vis[i])
			dfs(j, l + 1);
	}
	rangeIdx[i].second = iter - 1;
}
void compute(ll u, ll l) {
	ll lo = rangeIdx[u].first;
	ll hi = rangeIdx[u].second;
	auto lowI = lower_bound(idx[l].begin(), idx[l].end(), lo);
	auto highI = upper_bound(idx[l].begin(), idx[l].end(), hi);
	// cout << highI - lowI << '\n';
	int i = lowI - idx[l].begin(), j = highI - idx[l].begin();
	if (i == j) cout << "0\n";
	else {
		if (i - 1 >= 0) cout << tot[l][j - 1] - tot[l][i - 1] << '\n';
		else cout << tot[l][j - 1] << '\n';
	}
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> T;
	while (T--) {
		cin >> N >> Q;
		memset(vis, 0, sizeof vis);
		for (int i = 1; i <= N; i++) cin >> arr[i];
		for (int i = 1; i <= (N - 1); i++) {
			cin >> u >> v;
			g[u].insert(v);
			g[v].insert(u);
		}
		iter = 0;
		dfs(1, 1);
		for (int i = 1; i <= Q; i++) {
			cin >> u >> v;
			compute(u, v);
		}
		// for (int i = 1; i <= 5; i++) {
		// 	for (auto j : tot[i]) {
		// 		cout << j << " ";
		// 	}
		// 	cout << '\n';
		// }
		for (int i = 0; i <= N; i++) {
			g[i].clear(); idx[i].clear(); tot[i].clear();
		}
	}
}
