#include <bits/stdc++.h>
const int mod = 1e9 + 7;
using namespace std;
int n, m, K;
long long c[107], cost[107][107], dp[107][107][107];
void compute() {
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= m; j++)
			for (int k = 0; k <= K; k++) dp[i][j][k] = 1e18;
	dp[0][0][0] = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			for (int k = 0; k <= K; k++) {
				if (dp[i][j][k] == (long long)1e18) continue;
				if (c[i] == 0) {
					for (int l = 0; l < m; l++) {
						int nk = j != l || i == 0 ? k + 1 : k;
						if (nk <= K) dp[i + 1][l][nk] = min(dp[i + 1][l][nk], dp[i][j][k] + cost[i][l]);
					}
				} else {
					int l = c[i] - 1;
					int nk = j != l || i == 0 ? k + 1 : k;
					if (nk <= K) dp[i + 1][l][nk] = min(dp[i + 1][l][nk], dp[i][j][k]);
				}
			}
	long long res = 1e18;
	for (int i = 0; i < m; i++) res = min(res, dp[n][i][K]);
	if (res == (long long)1e18) cout << -1;
	else cout << res;
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> K;
	for (int i = 0; i < n; i++) cin >> c[i];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) cin >> cost[i][j];
	compute();

}
