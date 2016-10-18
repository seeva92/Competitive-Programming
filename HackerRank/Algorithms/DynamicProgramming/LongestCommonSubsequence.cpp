#include <bits/stdc++.h>
const int mod = 1e9 + 7;
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
vi A(1007), B(1007);
vvi dp(1007, vi(1007, 0));
int n, m;
void compute() {
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (A[i - 1] == B[j - 1]) {
				dp[i][j] = 1 + dp[i - 1][j - 1];
			} else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}

	int i = n, j = m; stack<int> s;
	while (i > 0 && j > 0) {
		if (A[i - 1] == B[j - 1]) {
			s.push(A[i - 1]); i--; j--;
		} else if (dp[i - 1][j] > dp[i][j - 1]) i--;
		else j--;
	}
	while (!s.empty()) {cout << s.top() << " "; s.pop();}
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> A[i];
	for (int i = 0; i < m; i++) cin >> B[i];
	compute();
}
