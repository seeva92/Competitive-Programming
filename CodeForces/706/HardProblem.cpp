#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
#define vi vector<int>
#define all(v) v.begin(), v.end()
#define pii pair<int, int>
#define mp make_pair
#define ll long long
const int mod = 1e9 + 7;
const long long MAX = 1e18;
using namespace std;
long long e[100007];
long long dp[100007][2];
string st[100007], rt[100007];
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n; cin >> n;
	for (int i = 0; i < n; i++) cin >> e[i];
	for (int i = 0; i < n; i++) {
		cin >> st[i]; rt[i] = st[i]; reverse(rt[i].begin(), rt[i].end());
		dp[i][0] = dp[i][1] = MAX;
	}
	dp[0][0] = 0; dp[0][1] = e[0];
	for (int i = 1; i < n; i++) {
		if (st[i - 1] <= st[i]) dp[i][0] = dp[i - 1][0];
		if (rt[i - 1] <= st[i]) dp[i][0] = min(dp[i][0], dp[i - 1][1]);
		if (st[i - 1] <= rt[i]) dp[i][1] = dp[i - 1][0] + e[i];
		if (rt[i - 1] <= rt[i]) dp[i][1] = min(dp[i][1], dp[i - 1][1] + e[i]);
	}
	long long res = min(dp[n - 1][0], dp[n - 1][1]);
	if (res == MAX) cout << -1 << '\n';
	else cout << res << '\n';
}
