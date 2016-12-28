#include <bits/stdc++.h>
typedef long long ll;
const int mod = 1e9 + 7;
const int MAX = 1e5 + 7;
using namespace std;
typedef vector<int> vi;
vector<int> divs[int(1e5 + 7)];
ll dp[15][MAX];
class DivFreed2
{
public:
	void sieve(int k) {
		for (int i = 1; i <= k; i++)
			for (int j = 2 * i; j <= k; j += i) {
				divs[j].push_back(i);
			}
	}
	int count(int n, int k) {
		memset(dp, 0, sizeof dp);
		sieve(k);
		for (int i = 1; i <= k; i++) dp[1][i] = 1;
		for (int i = 2; i <= n; i++) {
			ll sum = 0;
			for (int j = 1; j <= k; j++) {
				sum += dp[i - 1][j];
			}
			sum %= mod;

			for (int j = 1; j <= k; j++) {
				dp[i][j] = sum;
				for (int v : divs[j]) dp[i][j] = (dp[i][j] + mod - dp[i - 1][v]) % mod;
			}

		}
		ll sum = 0;
		for (int i = 1; i <= k; i++) sum = (sum +  dp[n][i]) % mod;
		return sum;
	}
};
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
}
