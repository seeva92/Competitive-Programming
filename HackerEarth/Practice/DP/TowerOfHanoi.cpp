#include <bits/stdc++.h>
const int mod = 1e9 + 7;
using namespace std;
typedef vector<int> vi;
long long dp[207];
pair<long long, long long> RH[207];
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> RH[i].first >> RH[i].second;
		}
		sort(RH, RH + n);
		for (int i = 0; i < n; i++) dp[i] = RH[i].second;
		long long res = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < i; j++) {
				if ((RH[i].first > RH[j].first) && (RH[i].second > RH[j].second) && (dp[i] < dp[j] + RH[i].second))
					dp[i] = dp[j] + RH[i].second;
			}
			res = max(res, dp[i]);
		}
		cout << res << '\n';
	}
}
