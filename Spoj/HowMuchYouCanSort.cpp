#include <bits/stdc++.h>
typedef unsigned long long ll;
const int mod = 1e9 + 7;
const int MAX = 1e5 + 7;
using namespace std;
typedef vector<int> vi;
int t;
long double n;
void compute() {
	ll l = 1, r = 1e18 + 7;
	ll mid, res;
	while (l <= r) {
		mid = (l + r) / 2;
		long double temp = (mid * (long double)log((long double)(mid)) / log((long double)3));
		if (temp <= n) {
			res = mid;
			l = mid + 1;
		}
		else r = mid - 1;
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
		cin >> n;
		compute();

	}
}
