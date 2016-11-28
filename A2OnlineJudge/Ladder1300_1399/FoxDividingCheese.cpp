#include <bits/stdc++.h>
typedef long long ll;
const int mod = 1e9 + 7;
const int MAX = 1e5 + 7;
using namespace std;
typedef vector<int> vi;
map<pair<ll, ll>, ll> mp;
ll compute(ll x, ll y) {
	if (x == y) return 0;
	if (mp.count({x, y})) return mp[ {x, y}];
	ll res = 1e18;
	// cout << x << " " << y << '\n';
	if (x > 0) {
		if (x % 2 == 0) res = min(res, 1 + compute(x - (x / 2), y));
		if (x % 3 == 0) res = min(res, 1 + compute(x - ((x * 2) / 3), y));
		if (x % 5 == 0) res = min(res, 1 + compute(x - ((x * 4) / 5), y));
	}
	if (y > 0) {
		if (y % 2 == 0) res = min(res, 1 + compute(x, y - (y / 2)));
		if (y % 3 == 0) res = min(res, 1 + compute(x, y - ((y * 2) / 3)));
		if (y % 5 == 0) res = min(res, 1 + compute(x, y - ((y * 4) / 5)));
	}
	return mp[ {x, y}] = res;
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll a, b;
	cin >> a >> b;

	ll cnt = compute(a, b);
	if (cnt == 1e18) cout << -1;
	else cout << cnt;

}
