#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <cstring>
#include <climits>
using namespace std;
int arr[110], val[110];
int dp[510][110], price[510][110];
int ans = 0;
int party(int W, int n) {
	if (W <= 0 || n == 0) return 0;
	if (dp[W][n] != -1) return dp[W][n];
	if (W < arr[n - 1]) return party(W, n - 1);

	return dp[W][n] = max(val[n - 1] + party(W - arr[n - 1], n - 1), party(W, n - 1));
}
void partydp(int W, int n) {
	for (int i = 0; i <= W; i++) {
		for (int j = 0; j <= n; j++)
			if (i == 0 || j == 0) {dp[i][j] = 0; price[i][j] = 0;}
			else if (i < arr[j - 1]) {dp[i][j] = dp[i][j - 1]; price[i][j] = price[i][j - 1];}
			else {
				if ((val[j - 1] + dp[i - arr[j - 1]][j - 1]) >= dp[i][j - 1]) {
					dp[i][j] = val[j - 1] + dp[i - arr[j - 1]][j - 1];
					price[i][j] = arr[j - 1] + price[i - arr[j - 1]][j - 1];
				}
				else {
					dp[i][j] = dp[i][j - 1];
					price[i][j] = price[i][j - 1];
				}

			}
	}
	int temp = dp[W][n];
	ans = INT_MAX;
	for (int i = 0; i <= W; i++) {
		if (dp[i][n] == temp && ans > price[i][n])
			ans = price[i][n];
	}
	cout << ans << " " << dp[W][n] << endl;
}
int main() {
// #ifndef ONLINE_JUDGE
// 	freopen("/home/shiva/Learning/1.txt", "r", stdin);
// 	freopen("/home/shiva/Learning/2.txt", "w", stdout);
// #endif
	ios::sync_with_stdio(false); cin.tie(0);
	int n, m;
	while (cin >> m >> n && (n || m)) {
		memset(dp, -1, sizeof dp); memset(price, 0, sizeof price);
		int x, y;
		vector<pair<int, int>> v;
		for (int i = 0; i < n; i++) {
			cin >> x >> y; v.push_back(make_pair(x, y));
		} sort(v.begin(), v.end());
		for (int i = 0; i < n; i++) {arr[i] = v[i].first; val[i] = v[i].second;}
		partydp(m, n);
	}
}