#include <bits/stdc++.h>
const int mod = 1e9 + 7;
using namespace std;
long long A[100007], B[100007];
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m; cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> A[i];
	for (int i = 1; i <= m; i++) cin >> B[i];
	B[0] = -(1LL << 40); B[m + 1] = (1LL << 40);

	long long res = 0LL;
	m += 2;
	for (int i = 0; i < n; i++) {
		int idx = lower_bound(B, B + m, A[i]) - B;
		res = max(res, min(B[idx] - A[i], A[i] - B[idx - 1]));
	}
	cout << res << '\n';
}
