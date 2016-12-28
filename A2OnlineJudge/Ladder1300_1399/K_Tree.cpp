#include <bits/stdc++.h>
typedef long long ll;
const int mod = 1e9 + 7;
const int MAX = 1e5 + 7;
using namespace std;
typedef vector<int> vi;
int n, K, d;
ll dp[200][2];
class K_Tree {
public:
	int compute(int sum, int flag) {
		if (sum < 0) return 0;
		if (sum == 0) return flag;
		if (dp[sum][flag] != -1) return dp[sum][flag];
		dp[sum][flag] = 0;
		for (int i = 1; i <= K; i++) {
			dp[sum][flag] += compute(sum - i, flag || i >= d ? 1 : 0);
			if (dp[sum][flag] >= mod) dp[sum][flag] -= mod;
		}
		return dp[sum][flag];
	}
	void solve() {
		memset(dp, -1, sizeof dp);
		cin >> n >> K >> d;
		cout << compute(n, 0);
	}
};
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	K_Tree kt; kt.solve();

}
