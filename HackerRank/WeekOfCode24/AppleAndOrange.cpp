#include <bits/stdc++.h>
const int mod = 1e9 + 7;
using namespace std;
int s, t, a, b, m, n, d;
void sum(int n) {
	int c = 0;
	while (n > 0) {
		n -= (n & -n);
		cout << n << " ";
		c++;
	}
	cout << "Count " << c << '\n';
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> s >> t >> a >> b >> m >> n;
	int ac = 0, ao = 0;
	for (int i = 1; i <= m; i++) {
		cin >> d;
		if (s <= a + d && a + d <= t) ac++;
	}
	for (int i = 1; i <= n; i++) {
		cin >> d;
		if (s <= b + d && b + d <= t) ao++;
	}
	cout << ac << '\n' << ao;
	sum(7);
}
