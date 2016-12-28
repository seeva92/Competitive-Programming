#include <bits/stdc++.h>
typedef long long ll;
const int mod = 1e9 + 7;
const int MAX = 1e5 + 7;
using namespace std;
typedef vector<int> vi;
ll dp[2007][2007];
vector<int> facts[2007];
class MashmokhAndACM
{
	int n, k;
public:
	void precomp(int n) {
		for (int i = 2; i <= n; i++) {
			for (int j = 1; j * i <= n; j++) {
				facts[i].push_back(j * i);
			}
		}
	}
	void solve() {
		memset(dp, 0, sizeof dp);
		cin >> n >> k;
		precomp(n);
		for (int i = 1; i <= n; i++) dp[i][0] = 1;

		ll sum = n;
		for (int i = 1; i < k; i++) {
			dp[1][i] = sum;
			for (int j = 2; j <= n; j++) {
				for (auto k : facts[j])
					dp[j][i] = dp[j][i] + dp[k][i - 1];
				dp[j][i] %= mod;
				sum = (dp[j][i] + sum) % mod;
			}
		}
		cout << sum;
	}
};
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	MashmokhAndACM m; m.solve();
}
