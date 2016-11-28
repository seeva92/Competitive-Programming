#include <bits/stdc++.h>
typedef long long ll;
const int mod = 1e9 + 7;
const int MAX = 1e5 + 7;
using namespace std;
typedef vector<int> vi;
map<string, int> mp;
map<string, int> up;
int n, q; string s;
string arr[5 * MAX];
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	string tmp;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];

		int & c = mp[arr[i]]; c = c + 1;
		int & v = up[arr[i]];
		if (v == 0) { v = i;}
		else {
			int x = mp[arr[v]];
			if (c == x) {
				if (arr[i] <= arr[v]) v = i;
			} else if (c > x) v = i;
		}
		tmp = arr[i]; tmp.pop_back();
		while (!tmp.empty()) {
			int & y = up[tmp];
			if (y == 0) { y = i;}
			else {
				int x = mp[arr[y]];
				if (c == x) {
					if (arr[i] <= arr[y]) y = i;
				} else if (c > x) y = i;
			}
			tmp.pop_back();
		}
	}

	cin >> q;
	int x;
	while (q--) {
		cin >> tmp;
		x = up[tmp];
		if (x == 0) cout << "-1\n";
		else cout << arr[x] << " " << mp[arr[x]] << '\n';

	}
}
