#include <bits/stdc++.h>
const int mod = 1e9 + 7;
using namespace std;
const int MAX = 1000007;
int arr[MAX], pre[MAX], bit[MAX], ans[MAX];
map<int, int> mp;
vector<pair<int, int>> v[MAX];
void upd(int i, int v) {
	i++;
	while (i < MAX) {
		bit[i] ^= v;
		i += (i & -i);
	}
}
int sum(int i) {
	i++;
	int res = 0;
	while (i > 0) {
		res ^= bit[i];
		i -= (i & -i);
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

	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		pre[i + 1] = pre[i] ^ arr[i];
	}

	int m; cin >> m;
	int l, r;
	for (int i = 0; i < m; i++) {
		cin >> l >> r;
		v[l - 1].push_back({r, i});
	}

	for (int i = n - 1; i >= 0; i--) {
		if (mp.count(arr[i])) upd(mp[arr[i]], arr[i]);
		mp[arr[i]] = i;
		upd(i, arr[i]);
		for (auto j : v[i]) {
			ans[j.second] = pre[i] ^ pre[j.first] ^ sum(j.first - 1);
		}
	}
	for (int i = 0; i < m; i++) cout << ans[i] << '\n';
}
