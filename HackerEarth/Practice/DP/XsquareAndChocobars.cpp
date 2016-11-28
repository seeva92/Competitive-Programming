#include <bits/stdc++.h>
const int mod = 1e9 + 7;
using namespace std;
typedef vector<int> vi;
int t; string s;
vector<int> v;
void compute() {
	v.assign(s.size(), 0);
	if (s.size() < 3) { cout << s.size() << "\n"; return;}
	int res = 0;
	for (int i = 2; i < int(s.size()); i++) {
		if (!(s[i - 1] == s[i - 2] && s[i - 1] == s[i])) {
			if (i - 3 >= 0) v[i] = 3 + v[i - 3];
			else v[i] = 3;
		}
		res = max(res, v[i]);
	}
	cout << int(s.size()) - res << '\n';
}
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
		compute();
	}
}
