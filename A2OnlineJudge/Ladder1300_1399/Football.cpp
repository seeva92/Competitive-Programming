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
	int n; cin >> n;
	map<string, int> mp;
	string s, res; int cnt = 0;
	for (int i = 0; i < n; i++) {
		cin >> s; mp[s]++;
		if (mp[s] > cnt) {
			cnt = mp[s]; res = s;
		}
	}
	cout << res << '\n';
}
