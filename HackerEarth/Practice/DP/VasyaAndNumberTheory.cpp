#include <bits/stdc++.h>
typedef long long ll;
const int mod = 1e9 + 7;
const int MAX = 1e5 + 7;
using namespace std;
typedef vector<int> vi;
int n;
int arr[1007], dp[1007];
void solve() {
	cin >> n;
	vi v(n), dp(n, 1);
	for (auto & i : v) cin >> i;
	sort(v.begin(), v.end());
	reverse(v.begin(), v.end());

	for (int i = 1; i < n; i++)
		for (int j = 0; j < i; j++)
			if (v[j] % v[i] == 0) dp[i] = max(dp[i], dp[j] + 1);
	int tmp = *max_element(dp.begin(), dp.end());
	if (tmp == 1) cout << -1;
	else cout << tmp;
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
}
