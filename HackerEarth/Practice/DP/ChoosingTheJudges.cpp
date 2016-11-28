#include <bits/stdc++.h>
const int mod = 1e9 + 7;
using namespace std;
typedef vector<int> vi;
int main() {
#ifndef ONLINE_JUDGE
	freopen("1.txt", "r", stdin);
	freopen("2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t, n;
	cin >> t;
	int x = 1;
	while (t--) {
		cin >> n;
		cout << "Case " << x << ": "; x++;
		long long * arr = new long long[n + 1];
		long long * dp = new long long[n + 1];
		for (long long i = 0; i < n; i++) cin >> arr[i];
		if (n == 1) {
			cout << arr[0] << '\n';
		}
		else if (n == 2) {
			cout << max(arr[0], arr[1]) << '\n';
			continue;
		} else {
			dp[1] = arr[0], dp[2] = max(dp[1], arr[1]);
			for (long long i = 3; i <= n; i++) {
				dp[i] = max(dp[i - 1], arr[i - 1] + dp[i - 2]);
			}
			cout << dp[n] << '\n';
		}

		delete [] arr;
		delete [] dp;
	}
}
