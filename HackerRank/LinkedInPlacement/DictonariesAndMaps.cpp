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
	int n, x; string s; cin >> n;
	map<string, int> mp;
	while (n--) {
		cin >> s >> x; mp[s] = x;
	}
	cin >> s;
	while (!s.empty()) {
		if (mp.count(s)) cout << s << "=" << mp[s] << '\n';
		else cout << "Not found\n";
		s.clear();
		cin >> s;
	}
}
