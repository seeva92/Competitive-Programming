#include <bits/stdc++.h>
typedef long long ll;
const int mod = 1e9 + 7;
const int MAX = 1e5 + 7;
using namespace std;
typedef vector<int> vi;
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n; cin >> n; int res = 0, curr = 1;
	int h, m, ph = -1, pm = -1;
	for (int i = 0; i < n; i++) {
		cin >> h >> m;
		if (h == ph && m == pm) {
			curr++;
		} else curr = 1;
		res = max(res, curr);
		// cout << res << " " << curr << '\n';
		ph = h; pm = m;
	}
	cout << res;
}
