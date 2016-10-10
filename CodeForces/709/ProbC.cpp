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
	string s; cin >> s;
	bool flag = true;
	bool found = false;
	string res = "";
	for (auto i : s) {
		if (i == 'a') {
			res += i;
			if (found) flag = false;
		}
		else {
			if (flag) {
				res += (char)((int)i - 1);
				found = true;
			} else {
				res += i;
			}
		}
	}
	if (!found) res[int(s.size()) - 1] = 'z';
	cout << res;
}
