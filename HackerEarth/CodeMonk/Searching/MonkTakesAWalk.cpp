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
	int T; cin >> T; string s;
	while (T--) {
		cin >> s;
		char c;
		int cnt = 0;
		for (auto i : s) {
			c = tolower(i);
			if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') cnt++;
		}
		cout << cnt << '\n';
	}
}
