#include <bits/stdc++.h>
const int mod = 1e9 + 7;
using namespace std;
int arr[26];
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	int g, n; cin >> g;
	while (g--) {
		cin >> n;
		memset(arr, 0, sizeof arr);
		char c;
		string s;
		bool under = false;
		for (int i = 1; i <= n; i++) {
			cin >> c; s += c;
			if (c != '_')
				arr[c - 'A']++;
			else under = true;
		}
		if (under) {
			int even = 0, odd = 0;
			for (int i = 0; i < 26; i++ ) {
				if (arr[i] == 0) continue;
				if (arr[i] > 1) even++;
				else odd++;
			}
			if (odd == 0) cout << "YES\n";
			else cout << "NO\n";
		} else {
			int cnt = 0;
			char prev = '-'; bool fail = false;
			for (int i = 0; i < int(s.size()); i++) {
				if (prev == '-') {
					cnt = 1;
					prev = s[i];
				} else if (prev == s[i]) {
					cnt++;
				} else if (cnt > 1) {
					cnt = 1;
					prev = s[i];
				} else {
					fail = true; break;
				}
			}
			if (fail || cnt == 1) cout << "NO\n";
			else cout << "YES\n";
		}

	}
}
