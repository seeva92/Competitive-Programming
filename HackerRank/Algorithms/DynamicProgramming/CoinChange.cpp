#include <bits/stdc++.h>
const int mod = 1e9 + 7;
using namespace std;
typedef vector<int> vi;
int arr[57];
long long dp[257][57];
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m; cin >> n >> m;
	for (int i = 0; i < m; i++) cin >> arr[i];
	long long x, y;
	for (int i = 0; i <= m; i++) dp[0][i] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < m; j++ ) {
			x = (i - arr[j] >= 0) ? dp[i - arr[j]][j] : 0;
			y =  (j - 1 >= 0) ? dp[i][j - 1] : 0;
			dp[i][j] = x + y;
		}
	}
	// for (int i = 1; i <= n; i++, cout << '\n')
	// for (int j = 0; j < m; j++) cout << dp[i][j] << " ";
	cout << dp[n][m - 1];
}
