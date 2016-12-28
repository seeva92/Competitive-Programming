#include <bits/stdc++.h>
typedef long long ll;
const int mod = 1e9 + 7;
const int MAX = 1e5 + 7;
using namespace std;
typedef vector<int> vi;
int n, q, x, y;
vector<int> g[MAX];
pair<int, int> edges[MAX];
int cnt[MAX];
int dfs(int i) {
	cnt[i] = 1;
	for (auto j : g[i]) {
		if (cnt[j] == 0) {
			cnt[i] += dfs(j);
		}
	}
	return cnt[i];
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> q;
	for (int i = 0; i < n - 1; i++) {
		cin >> x >> y;
		g[x].push_back(y);
		g[y].push_back(x);
		edges[i].first = x; edges[i].second = y;
	}
	memset(cnt, 0, sizeof cnt);
	for (int i = 1; i <= n; i++) {
		if (cnt[i] == 0) {
			dfs(i);
		}
	}

	for (int i = 0; i < q; i++) {
		cin >> x; x--;
		if (cnt[edges[x].first] < cnt[edges[x].second]) {
			cout << (ll)cnt[edges[x].first] * (ll)(n - cnt[edges[x].first]) << '\n';
		} else {
			cout << (ll)cnt[edges[x].second] * (ll)(n - cnt[edges[x].second]) << '\n';
		}
	}
}
