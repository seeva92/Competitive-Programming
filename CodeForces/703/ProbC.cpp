#include <bits/stdc++.h>
const int mod = 1e9 + 7;
using namespace std;
typedef long long ll;
long long x[10010], y[10010];
int n, w, v, u;

bool poss() {
	for (int i = 0; i < n; i++) {
		if (ll(x[i])*u < ll(y[i])*v) return 0;
	}
	return 1;
}
long double get() {
	long double res = (long double)w / u;
	for (int i = 0; i < n; i++) {
		res = max(res, (long double)x[i] / v + (long double)(w - y[i]) / u);
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
	cin >> n >> w >> v >> u;
	for (int i = 0; i < n; i++) cin >> x[i] >> y[i];
	if (poss()) cout << fixed << setprecision(15) << (long double)w / u;
	else cout << fixed << setprecision(15) << get();
}
