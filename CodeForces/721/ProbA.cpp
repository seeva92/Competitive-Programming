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
	int n; cin >> n;
	string s; cin >> s;

	bool flag = false;
	int c = 0;
	vector<int> v;

	for (int i = 0; i < n; i++) {
		if (s[i] == 'W') continue;
		int j;
		for (j = i; j < n && s[j] != 'W'; j++) {
			c++;
		}
		i = j;
		if (c > 0) v.push_back(c);
		c = 0;
	}
	cout << int(v.size()) << '\n';
	for (auto i : v) cout << i << " ";
}
