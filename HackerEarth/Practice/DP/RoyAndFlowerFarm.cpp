#include <bits/stdc++.h>
typedef long long ll;
const int mod = 1e9 + 7;
const int MAX = 1e5 + 7;
using namespace std;
typedef vector<int> vi;
int t, n, x, y, p;
pair<int, int> P[1007];
int dp[107][10007];
void solve() {
	cin >> t;
	while (t--) {
		memset(dp, 0, sizeof dp);
		cin >> n >> p;
		for (int i = 0; i < n; i++) {
			cin >> P[i].first >> P[i].second;
			P[i].first -= P[i].second;
		}
		// sort(P, P + n);

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= p; j++) {
				if (P[i - 1].second <= j) dp[i][j] = max(dp[i - 1][j], P[i - 1].first + dp[i - 1][j - P[i - 1].second]);
				else dp[i][j] = dp[i - 1][j];
			}
		}
		int profit = dp[n][p];
		int j = p;
		while (j >= 0 && dp[n][j] == profit) {
			j--;
		}
		j += 1;
		cout << j << " " << profit + p << "\n";
	}
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
}
