#include <bits/stdc++.h>
typedef long long ll;
const int mod = 1e9 + 7;
const int MAX = 1e5 + 7;
using namespace std;
typedef vector<int> vi;
string a;
int dp[1007][1007];
int lps(int i, int j) {
	if (dp[i][j] != -1) return dp[i][j];
	if (i == j) return 1;
	if (a[i] == a[j] && i + 1 == j) return 2;
	if (a[i] == a[j]) return 2 + lps(i + 1, j - 1);
	return dp[i][j] = max(lps(i, j - 1), lps(i + 1, j));
}
void lpsdp() {
	memset(dp, 0, sizeof dp);
	int n = a.size();
	for (int i = 1; i <= n; i++) dp[i][i] = 1;
	for (int l = 2; l <= n; l++) {
		for (int i = 0; i < n - l + 1; i++) {
			int j = i + l - 1;
			if (a[i] == a[j] && i + 1 == j) dp[i][j] = 2;
			else if (a[i] == a[j]) dp[i][j] = 2 + dp[i + 1][j - 1];
			else dp[i][j] = max(dp[i][j - 1], dp[i + 1][j]);
		}
	}
	cout << dp[0][n - 1];
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	memset(dp, -1, sizeof dp);
	cin >> a;
	// cout << lps(0, a.size() - 1);
	lpsdp();
}
