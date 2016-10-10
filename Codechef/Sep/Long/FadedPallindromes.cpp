#include <bits/stdc++.h>
const int mod = 1e9 + 7;
using namespace std;
int t; string s;
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> t;
	while (t--) {
		cin >> s;
		int len = s.size();
		bool f = 1;
		for (int i = 0, j = len - 1; i <= j; i++, j--) {
			if (s[i] == '.' && s[j] != '.') s[i] = s[j];
			else if (s[i] != '.' && s[j] == '.') s[j] = s[i];
			else if (s[i] == '.' && s[j] == '.') s[i] = s[j] = 'a';
			else if (s[i] != s[j]) { f = 0; break; }
		}
		if (f) cout << s;
		else cout << -1;
		cout << '\n';
	}
}
