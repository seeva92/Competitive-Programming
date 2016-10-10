#include <bits/stdc++.h>
#define vi vector<int>
#define pi pair<int,int>
#define vii vector<pi>
#define ll long long
using namespace std;
int T, E, F, N, P, W;
int Wt[507], Pt[507];
int arr[507][10007];
int dp[10007];
void compute() {
	fill(dp, dp + 10007, INT_MAX);
	for (int i = 1; i <= F; i++)
		for (int j = 0; j < N; j++) {
			if (i == Wt[j]) dp[i] = min(dp[i], Pt[j]);
			else if (i > Wt[j] && dp[i - Wt[j]] != INT_MAX)
				dp[i] = min(dp[i - Wt[j]] + Pt[j], dp[i]);
		}

	if (dp[F] != INT_MAX)
		cout << "The minimum amount of money in the piggy-bank is " << dp[F] << ".\n";
	else
		cout << "This is impossible.\n";
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("/home/shiva/Learning/1.txt", "r", stdin);
	freopen("/home/shiva/Learning/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> T;

	while (T--) {
		cin >> E >> F >> N;
		memset(arr, -1, sizeof arr);
		F = F - E;
		for (int i = 0; i < N; i++) cin >> Pt[i] >> Wt[i];
		compute();


	}
}