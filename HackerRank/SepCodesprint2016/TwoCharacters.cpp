#include <bits/stdc++.h>
const int mod = 1e9 + 7;
using namespace std;
int n; string s;
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	cin >> s;
	int res = 0;
	for (int i = 0; i < 26; i++) {
		for (int j = 0; j < 26; j++) {
			// cout << (char)('a' + i) << " " << (char)('a' + j) << '\n';
			if (i == j) continue;
			bool flag = true;
			int curr = 0;
			int vis = 0;
			for (int k = 0; k < n; k++ ) {
				if (s[k] == char('a' + i) || s[k] == char('a' + j)) {
					vis++;
					// cout << s[k];
					if (flag && s[k] == char('a' + i)) {
						curr++;
						flag = !flag;
					} else if (!flag && s[k] == char('a' + j)) {
						curr++;
						flag = !flag;
					} else break;
				}
			}
			// cout << char('a' + i) << " " << char('a' + j) << " " << vis << " " << curr << '\n';
			if (vis == curr)
				res = max(curr, res);
		}
	}
	if (res == 1) cout << 0 << '\n';
	else cout << res << '\n';
}
