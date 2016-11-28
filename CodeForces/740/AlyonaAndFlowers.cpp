#include <bits/stdc++.h>
typedef long long ll;
const int mod = 1e9 + 7;
const int MAX = 1e5 + 7;
using namespace std;
typedef vector<int> vi;
int arr[107], N, M;
int val[107], dp[107];
int x, y;
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	memset(dp, 0, sizeof dp);
	memset(val, 0, sizeof val);
	cin >> N >> M;
	for (int i = 0; i < N; i++) cin >> arr[i];
	for (int i = 0; i < M; i++) {
		cin >> x >> y;
		for (int j = x - 1; j <= y - 1; j++) {
			val[i] += arr[j];
		}
		dp[i] = val[i];
	}
	for (int i = 1; i < M; i++)
		for (int j = 0; j < i; j++) {
			if (dp[i] < dp[j] + val[i]) dp[i] = dp[j] + val[i];
		}
	int res = 0;
	for (int i = 0; i < M; i++) res = max(res, dp[i]);
	cout << res;
}
