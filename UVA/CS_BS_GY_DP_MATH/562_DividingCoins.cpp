#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cstring>
using namespace std;
int arr[110];
int mp[110][110 * 510];
int dividing(int n, int W, int took) {
	if (n < 0)
		return took;
	
	if (mp[n][took] != -1)
		return mp[n][took];

	if (arr[n] > W)
		return dividing(n - 1, W, took);

	mp[n][took] = max(dividing(n - 1, W - arr[n], took + arr[n]), dividing(n - 1, W, took));
	return mp[n][took];
}
// int dp[110][110 * 510];
// int dividing(int n, int W) {
// 	for (int i = 0; i <= W; i++) dp[0][i] = 0;

// 	for (int i = 1; i <= n; i++)
// 		for (int j = 1; j <= W; j++) {
// 			if (arr[i] <= j)
// 				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - arr[i]] + arr[i]);
// 			else
// 				dp[i][j] = dp[i - 1][j];
// 		}
// 	return dp[n][W];
// }
int main() {
#ifndef ONLINE_JUDGE
	freopen("E:/Shiva backup/Shiva/Learning/Learning/UVA/1.txt", "r", stdin);
	freopen("E:/Shiva backup/Shiva/Learning/Learning/UVA/2.txt", "w", stdout);
#endif
	int n, m;
	scanf("%d", &n);
	while (n--) {
		scanf("%d", &m);
		int sum = 0;
		for (int i = 0; i < m; i++) {
			scanf("%d", &arr[i]);
			sum += arr[i];
		}
		memset(mp, -1, sizeof mp);
		printf("%d\n", sum - (dividing(m - 1, sum / 2, 0) * 2));
	}

}