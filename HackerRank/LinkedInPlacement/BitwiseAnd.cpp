#include <bits/stdc++.h>
const int mod = 1e9 + 7;
using namespace std;
typedef vector<int> vi;
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t, n, k; cin >> t;
	int cnt = 0;
	while (t--) {
		cin >> n >> k;
		int res = 0;
		for (int i = 1; i <= n; i++)
			for (int j = i + 1; j <= n; j++) {
				if ((i & j) < k) res = max(res, (i & j));
				cnt++;
			}
		cout << res << '\n';
	}
	cout << "Tot " << cnt << '\n';
}
