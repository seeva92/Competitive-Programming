#include <bits/stdc++.h>
typedef long long ll;
const int mod = 1e9 + 7;
const int MAX = 1e5 + 7;
using namespace std;
typedef vector<int> vi;
ll solve(ll bb, ll dd, ll ss) {
	ll sum = bb + dd + ss;
	ll hi = max(max(bb, dd), ss);
	if (hi == dd) return 3 * hi - sum;
	if (hi == ss) return 3 * hi - sum - 1;
	if (hi == bb) return 3 * hi - sum - 2;
	return -1;
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll b, d, s; cin >> b >> d >> s;
	ll ans = solve(b, d, s);
	ans = min(ans, solve(d, s, b));
	ans = min(ans, solve(s, b, d));
	cout << ans;
}
