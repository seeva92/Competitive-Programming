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
	string s;
	int n;
	bool flag = false;
	vector <string> res;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s;
		if (!flag) {
			if (s[0] == 'O' && s[0] == s[1]) {
				s[0] = s[1] = '+';
				flag = true;
			} else if (s[3] == 'O' && s[3] == s[4]) {
				s[3] = s[4] = '+';
				flag = true;
			}
		}
		res.push_back(s);
	}
	if (flag) {
		cout << "YES\n";
		for (auto i : res) cout << i << '\n';
	} else cout << "NO\n";
}
