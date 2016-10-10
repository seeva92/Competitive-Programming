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
	int a, b, c;
	cin >> a >> b >> c;
	int res = 1e5;
	for (int i = min(a, min(b, c)); i <= max(a, max(b, c)); i++) {
		int temp = (abs(a - i) + abs(b - i) + abs(c - i));
		res = min(temp, res);
	}
	cout << res << '\n';
}
