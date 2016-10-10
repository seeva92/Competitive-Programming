#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;
long long dp[11][11][11][11][5];
long long f(long long a, long long b, long long c, long long d, long long l) {
	if (a < 0 || b < 0 || c < 0 || d < 0) return 0;
	if (a == 0 && b == 0 && c == 0 && d == 0) return 1;
	if (dp[a][b][c][d][l] != -1) return dp[a][b][c][d][l];
	long long ca, cb, cc, cd;
	ca = cb = cc = cd = 0;
	if (l != 0) ca = f(a - 1, b, c, d, 0);
	if (l != 1) cb = f(a, b - 1, c, d, 1);
	if (l != 2) cc = f(a, b, c - 1, d, 2);
	if (l != 3) cd = f(a, b, c, d - 1, 3);
	dp[a][b][c][d][l] = ca + cb + cc + cd;
	return dp[a][b][c][d][l];
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("/home/shiva/Learning/1.txt", "r", stdin);
	freopen("/home/shiva/Learning/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false); cin.tie(0);
	memset(dp, -1, sizeof dp);
	long long a, b, c, d;
	cin >> a >> b >> c >> d;
	cout << f(a, b, c, d, 4) << endl;

}