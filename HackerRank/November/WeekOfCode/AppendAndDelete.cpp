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
	string s, t; int k, i, j, sl, tl;
	cin >> s >> t >> k;
	sl = s.size(); tl = t.size();
	for (i = 0, j = 0; i < sl && j < tl && s[i] == t[j]; i++, j++);
	if (i == sl && j == tl) {
		if (k % 2 == 0 || (2 * sl <= k)) cout << "Yes";
		else cout << "No";
	} else if (i == sl || j == tl) {
		if (abs(tl - sl) <= k && (k - abs(tl - sl)) % 2 == 0) cout << "Yes";
		else if ((sl + tl) <= k) cout << "Yes";
		else cout << "No";
	}
	else {
		int temp = (sl - i) + (tl - i);
		if (temp <= k && (k - temp) % 2 == 0) cout << "Yes";
		else if ((sl + tl) <= k) cout << "Yes";
		else cout << "No";
	}
}
