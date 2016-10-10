#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#define vi vector<int>
#define all(v) v.begin(),v.end()
#define pii pair<int,int>
#define mp make_pair
using namespace std;
string a, b;
int dp[2010][2010];
int mem(int i, int j) {
	if (i == 0) return j;
	if (j == 0) return i;
	if (dp[i][j] != -1) return dp[i][j];
	if (a[i - 1] == b[j - 1])
		return mem(i - 1, j - 1);
	int del = mem(i - 1, j);
	int ins = mem(i, j - 1);
	int rep = mem(i - 1, j - 1);
	return dp[i][j] = min(del, min(ins, rep)) + 1;
}
int dynamic(int n, int m) {
	for (int i = 0; i <= m; i++) dp[0][i] = i;
	for (int i = 0; i <= n; i++) dp[i][0] = i;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (a[i - 1] == b[j - 1]) dp[i][j] = dp[i - 1][j - 1];
			else {
				dp[i][j] = min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1])) + 1;
			}
	return dp[n][m];
}
int main() {
// #ifndef ONLINE_JUDGE
// 	freopen("/home/shiva/Learning/1.txt", "r", stdin);
// 	freopen("/home/shiva/Learning/2.txt", "w", stdout);
// #endif
	int t;
	scanf("%d", &t);
	char arr[2010], brr[2010];
	while (t--) {
		cin >> a >> b;
		memset(dp, -1, sizeof dp);
		printf("%d\n", dynamic(int(a.size()), int(b.size())));
	}

}