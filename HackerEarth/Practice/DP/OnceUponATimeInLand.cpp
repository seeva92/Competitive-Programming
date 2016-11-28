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
	int T, N, K; cin >> T;
	while (T--) {
		cin >> N >> K;
		long long * arr, *dp;
		arr = new long long[N];
		dp = new long long[N + 1];
		for (int i = 0; i < N; i++) {
			cin >> arr[i];
			dp[i] = 0;
		}
		dp[N] = 0;
		for (int i = 1; i <= K; i++) dp[i] = max(dp[i - 1], arr[i - 1]);
		for (int i = K + 1; i <= N; i++) {
			dp[i] = max(dp[i - 1], arr[i - 1] + dp[i - K - 1]);
		}
		cout << dp[N] << '\n';

		delete [] arr;
		delete [] dp;
	}
}
