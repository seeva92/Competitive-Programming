#include <bits/stdc++.h>
const int mod = 1e9 + 7;
using namespace std;
long long n, m, T, u, v, t;
int edges[5007][3];
int dp[5007][5007];
int path[5007][5007];
void compute() {
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			dp[i][j] = T + 1;
		}
	dp[1][1] = 0;
	int ans;

	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			int u = edges[j][0], v = edges[j][1], t = edges[j][2];
			if (dp[i - 1][u] + t < dp[i][v]) {
				dp[i][v] = dp[i - 1][u] + t;
				path[i][v] = u;
			}

		}
		if (dp[i][n] <= T) {
			ans = i;
		}
	}
	cout << ans << "\n";
	int j = n;
	stack<int> res;
	for (int i = ans; i >= 1; i--) {
		res.push(j);
		j = path[i][j];
	}
	while (!res.empty()) {
		cout << res.top() << " "; res.pop();
	}
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> T;
	for (long long i = 1; i <= m; i++) {
		cin >> u >> v >> t;
		edges[i][0] = u; edges[i][1] = v; edges[i][2] = t;
	}
	compute();
}
