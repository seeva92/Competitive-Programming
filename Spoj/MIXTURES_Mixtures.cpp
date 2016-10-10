#include <bits/stdc++.h>
#define vi vector<int>
#define pi pair<int,int>
#define vii vector<pi>
#define ll long long
using namespace std;
int arr[200], n;
int dp[107][107];
int csum(int i, int j) {
	int sum = 0;
	for (int k = i; k <= j; k++) sum = (sum + arr[k]) % 100;
	return sum;
}
int compute(int i, int j) {
	if (i == j) return 0;
	if (dp[i][j] != -1) return dp[i][j];
	int res = INT_MAX;
	int count;
	for (int k = i; k < j; k++) {
		count = compute(i, k) + compute(k + 1, j) + (csum(i, k) * csum(k + 1, j));
		if (count < res) res = count;
	}
	dp[i][j] = res;
	return res;
}

int compute() {
	int count, res;
	for (int i = 0; i < n; i++) dp[i][i] = 0;
	for (int l = 1; l < n; l++) {
		for (int i = 0, j = l; j < n; i++, j++) {
			res  = INT_MAX;
			for (int k = i; k < j; k++) {
				count = dp[i][k] + dp[k + 1][j] + (csum(i, k) * csum(k + 1, j));
				if (count < res) res = count;
			}
			dp[i][j] = res;
		}
	}
	return dp[0][n - 1];
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("/home/shiva/Learning/1.txt", "r", stdin);
	freopen("/home/shiva/Learning/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false); cin.tie(0);
	while (cin >> n) {
		memset(arr, 0, sizeof arr);
		memset(dp, 0, sizeof dp);
		for (int i = 0; i < n; i++) cin >> arr[i];
		cout << compute() << endl;

	}


}