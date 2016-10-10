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
	int n, m, t, k;
	bool flag = true;
	cin >> n >> m;
	int p = 0;
	while (m--) {
		cin >> t >> k;
		if (t & 1) {
			p = (p + k) % n;
		} else {
			p = (n + k - p) % n;
			flag = !flag;
		}
	}
	if (flag) {
		cout << "1 " << (n - p) << '\n';
	} else {
		cout << "2 " << p << '\n';
	}
}
