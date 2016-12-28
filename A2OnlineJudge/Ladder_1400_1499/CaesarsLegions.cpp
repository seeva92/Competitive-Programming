#include <bits/stdc++.h>
typedef long long ll;
const ll mod = 1e8;
const int MAX = 1e5 + 7;
using namespace std;
typedef vector<int> vi;
ll dp[105][105][15][15];
class CaesarsLegions
{
	int n1, n2, k1, k2;
public:
	//My solution
	ll compute(int N1, int N2, int kN1, int kN2) {
		if (N1 < 0 || N2 < 0) return 0;
		if ((N1 == 0) && (N2 == 0)) return 1;

		ll & res = dp[N1][N2][kN1][kN2];
		if (res != -1 ) return res;

		res = 0;
		if (kN1 > 0 && N1 > 0)
			res += compute(N1 - 1, N2, kN1 - 1, k2);
		if (kN2 > 0 && N2 > 0)
			res += compute(N1, N2 - 1, k1, kN2 - 1);
		res = res % mod;

		return res;
	}

	//Editorial Solution
	ll compute() {
		memset(dp, 0, sizeof dp);
		dp[0][0][0][0] = 1;
		for (int i = 0; i <= n1; i++)
			for (int j = 0; j <= n2; j++)
				for (int k = 0; k <= k1; k++) {
					if (k > i) break;
					for (int l = 0; l <= k2; l++) {
						if (l > j) break;
						dp[i + 1][j][k + 1][0] = (dp[i + 1][j][k + 1][0] + dp[i][j][k][l]) % mod;
						dp[i][j + 1][0][l + 1] = (dp[i][j + 1][0][l + 1] + dp[i][j][k][l]) % mod;
					}
				}
		ll res = 0;
		for (int i = 0; i <= k1; i++)
			for (int j = 0; j <= k2; j++)
				res = (res + dp[n1][n2][i][j]) % mod;

		return res;
	}
	void solve() {
		memset(dp, -1, sizeof dp);
		cin >> n1 >> n2 >> k1 >> k2;
		// cout << compute(n1, n2, k1, k2);
		cout << compute();
	}
};
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	CaesarsLegions c; c.solve();
}
