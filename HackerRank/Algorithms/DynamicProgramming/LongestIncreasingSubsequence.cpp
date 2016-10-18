#include <bits/stdc++.h>
const int mod = 1e9 + 7;
using namespace std;
#define vi vector<int>
vi arr(1000007), dp(1000007, 1), L(1000007), Lid(1000007), P(1000007);
int n;
void computedp() {

	for (int i = n - 1; i >= 0; i--)
		for (int j = i + 1; j < n; j++) {
			if (arr[i] < arr[j] && dp[i] < (dp[j] + 1))
				dp[i] = dp[j] + 1;
		}
	int res = 0;
	for (int i = 0; i < n; i++) res = max(dp[i], res);
	cout << res << '\n';
}
void print(int end) {
	int x = end;
	stack<int> s;
	for (; P[x] >= 0; x = P[x]) s.push(arr[x]);
	cout << "[" << arr[x];
	for (; !s.empty(); s.pop()) cout << " " << s.top();
	cout << "]\n";
}
void computedc() {
	int lis = 0, lis_end = 0;
	for (int i = 0; i < n; i++) {
		int pos = lower_bound(L.begin(), L.begin() + lis, arr[i]) - L.begin();
		L[pos] = arr[i];
		Lid[pos] = i;
		P[i] = pos ? Lid[pos - 1] : -1;
		if (pos + 1 > lis) {
			lis = pos + 1;
			lis_end = i;
		}
		// print(i);
	}
	// for (int i = 0; i < n; i++) cout << L[i] << " "; cout << '\n';
	cout << lis << '\n';
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	computedc();
}
