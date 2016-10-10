#include <bits/stdc++.h>
#define vi vector<int>
#define pi pair<int,int>
#define vii vector<pi>
#define ll long long
using namespace std;
int t;
ll arr[10007];
ll dp[10007];
ll compute(int n) {
	if (n <= 0 ) return 0;
	if (dp[n] != -1) return dp[n];
	return dp[n] = max(compute(n - 2) + arr[n - 1], compute(n - 1));
}
ll computeIter(int n) {
	dp[0] = arr[0];
	dp[1] = dp[0] > arr[1] ? dp[0] : arr[1];
	for (int i = 2; i < n; i++)
		if (dp[i - 1] > (dp[i - 2] + arr[i]))
			dp[i] = dp[i - 1];
		else
			dp[i] = dp[i - 2] + arr[i];
	return dp[n - 1];
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("/home/shiva/Learning/1.txt", "r", stdin);
	freopen("/home/shiva/Learning/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> t;
	for (int a = 1; a <= t; a++) {
		int n;
		memset(dp, 0, sizeof dp);
		cin >> n;
		for (int i = 0; i < n; i++) cin >> arr[i];
		cout << "Case " << a << ": ";
		cout << computeIter(n) << endl;
	}
}