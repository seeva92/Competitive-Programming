#include <bits/stdc++.h>
typedef long long ll;
const int mod = 1e9 + 7;
const int MAX = 1e5 + 7;
using namespace std;
typedef vector<int> vi;
int n, k, d;
ll dp[200][200];
class K_Tree {
public:
	int compute(int sum, int flag) {
		if (sum < n) return 0;
		if (sum == 0) return flag ;
		int  res = 0;
		for (int i = 1; i <= k; i++)
			if (flag) {
				dp[sum][i] = compute(sum - i, 1);
				res = res + dp[sum][i];
			}
			else {
				dp[sum][i] = compute(sum - i, i == d);
				res = res + dp[sum][i];
			}
		return dp[sum][k] = res;
	}
	void solve() {
		memset(dp, -1, sizeof dp);
		cin >> n >> k >> d;
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
