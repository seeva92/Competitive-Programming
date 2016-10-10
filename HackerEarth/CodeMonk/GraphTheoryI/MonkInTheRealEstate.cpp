#include <bits/stdc++.h>
const int mod = 1e9 + 7;
using namespace std;
set<int> s;
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t, e, x, y; cin >> t;
	while (t--) {
		cin >> e;
		s.clear();
		for (int i = 1; i <= e; i++) {
			cin >> x >> y;
			s.insert(x); s.insert(y);
		}

		cout << int(s.size()) << '\n';

	}
}
