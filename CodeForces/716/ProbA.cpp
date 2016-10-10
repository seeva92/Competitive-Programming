#include <bits/stdc++.h>
const int mod = 1e9 + 7;
using namespace std;
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, c; cin >> n >> c;
	int a, b;
	cin >> a;
	int res = 1;
	for (int i = 2; i <= n; i++) {
		cin >> b;
		if (b - a <= c) res++;
		else res = 1;
		a = b;
	}
	cout << res << '\n';
}
