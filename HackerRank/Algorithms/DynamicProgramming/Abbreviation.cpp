#include <bits/stdc++.h>
const int mod = 1e9 + 7;
using namespace std;
typedef vector<int> vi;
int t;
string a, b;
bool dp[1007][1007];
bool compute() {
	memset(dp, 0, sizeof dp);
	int al = a.size(), bl = b.size();
	memset(dp, 0, sizeof dp);
	dp[0][0] = true;
	for (int i = 0; i < al; i++)
		for (int j = 0; j <= bl; j++) {
			if (dp[i][j]) {
				if (toupper(a[i]) == b[j]) dp[i + 1][j + 1] = true;
				if (islower(a[i])) dp[i + 1][j] = true;
			}

		}

	for (int i = 0; i <= al; i++, cout << '\n')
		for (int j = 0; j <= bl; j++) cout << dp[i][j] << " ";

	return dp[al][bl];
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> t;
	while (t--) {
		cin >> a >> b;
		if (int(a.size()) < int(b.size())) cout << "NO\n";
		if (compute()) cout << "YES\n";
		else cout << "NO\n";
	}
}
