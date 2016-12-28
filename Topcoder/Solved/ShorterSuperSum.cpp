#include <bits/stdc++.h>
typedef long long ll;
const int mod = 1e9 + 7;
const int MAX = 1e5 + 7;
using namespace std;
typedef vector<int> vi;
int dp[57][57];
class ShorterSuperSum
{
public:
	int calculate(int k, int n) {
		memset(dp, 0, sizeof dp);
		for (int i = 0; i <= n; i++) dp[0][i] = i;
		for (int i = 1; i <= k; i++) {
			for (int j = 1; j <= n; j++) {
				int sum = 0;
				for (int l = 0; l < j; l++) sum += dp[i - 1][l];
				dp[i][j] = sum;
			}
			for (int j = 1; j <= n; j++)
				dp[i][j] += dp[i - 1][j];
		}

		// for (int i = 0; i <= k; i++, cout << '\n')
		// for (int j = 0; j <= n; j++) cout << dp[i][j] << " ";
		return dp[k][n];
	}
};
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	ShorterSuperSum s;
	cout << s.calculate(14, 14);
}
