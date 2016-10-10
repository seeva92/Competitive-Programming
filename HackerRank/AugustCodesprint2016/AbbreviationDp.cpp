#include <bits/stdc++.h>
const int mod = 1e9 + 7;
using namespace std;
int q; string a, b;
bool dp[1010][1010];
bool compute() {
	memset(dp, 0, sizeof dp);
	int alen = a.size(), blen = b.size();
	dp[0][0] = true;
	for (int i = 0; i < alen; i++) {
		for (int j = 0; j <= blen; j++) {
			if (dp[i][j]) {
				if ((j < blen) && (toupper(a[i]) == b[j])) dp[i + 1][j + 1] = true;
				if (islower(a[i])) dp[i + 1][j] = true;
			}
		}
	}
	return dp[alen][blen];

}
int main() {
#ifndef ONLINE_JUDGE7
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> q;
	while (q--) {
		cin >> a >> b;
		if (compute()) cout << "YES\n";
		else cout << "NO\n";
	}
}
