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
	int t, n, m, c; cin >> t;
	while (t--) {
		cin >> n >> m >> c;
		int csq = sqrt(c) + 1;
		int cnt = 0;
		set<pair<int, int>> st;
		for (int i = 1; i <= csq; i++ ) {
			if (c % i == 0) {
				if ((i <= n) && (c / i) <= m) st.insert({i, c / i});
				if ((c / i <= n) && (i <= m)) st.insert({c / i, i});
			}
		}
		cout << int(st.size()) << '\n';

	}
}
