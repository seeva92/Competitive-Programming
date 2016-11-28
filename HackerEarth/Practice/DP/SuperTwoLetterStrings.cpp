#include <bits/stdc++.h>
const int mod = 1e9 + 7;
using namespace std;
typedef vector<int> vi;
long long dp[10007][17];
int N, P;
long long f(int i, int pi) {
	if (i == 0) return 1;
	if (dp[i][pi] != -1) return dp[i][pi];
	if (pi != 0 ) return dp[i][pi] = (f(i - 1, pi - 1) + f(i - 1, P - 1)) % mod;
	return dp[i][pi] = f(i - 1, P - 1);
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t; cin >> t;
	while (t--) {
		memset(dp, -1, sizeof dp);
		cin >> N >> P;
		cout << f(N - 1, P - 1) << '\n';
	}
}
