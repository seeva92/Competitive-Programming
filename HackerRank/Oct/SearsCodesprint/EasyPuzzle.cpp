#include <bits/stdc++.h>
const int mod = 1e9 + 7;
using namespace std;
typedef vector<int> vi;
__int128 gcd(__int128 a, __int128 b) {
	return  b == 0 ? a : gcd(b, a % b);
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	long long t, n, k; cin >> t;
	while (t--) {
		cin >> n >> k;
		__int128 val = 0;
		long long curr;
		for (int i = 1; i <= n; i++) {
			if (i == 1) {
				cin >> curr;
				val = curr;
			} else {
				cin >> curr;
				val = (val * curr) / gcd(val, curr);
			}
		}
		if (val % k == 0) cout << "YES\n";
		else cout << "NO\n";
	}
}
