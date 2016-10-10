#include <bits/stdc++.h>
const int mod = 1e9 + 7;
using namespace std;
long long arr[1000007];
int l, r;
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, q; cin >> n >> q;
	arr[0] = 0LL;
	long long x;
	for (int i = 1; i <= n; i++) {
		cin >> x;
		arr[i] = (log2(x) + 1) + arr[i - 1];
	}
	int cnt = 0;
	while (q--) {
		cin >> l >> r;
		long long res = arr[r] - arr[l - 1];
		// cout << res << '\n';
		if (res & 1) cout << "Mishki\n";
		else cout << "Hacker\n";
	}

}
