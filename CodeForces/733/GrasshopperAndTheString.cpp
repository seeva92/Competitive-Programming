#include <bits/stdc++.h>
const int mod = 1e9 + 7;
using namespace std;
typedef vector<int> vi;
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	string s; cin >> s;
	int res = 0;
	int d = 0;
	for (int i = 0; i < int(s.size()); i++) {
		if (s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U' || s[i] == 'Y') {
			d++;
			res = max(res, d);
			d = 0;
		} else {
			d++;
		}
	}
	d++;
	res = max(res, d);
	cout << res;
}
