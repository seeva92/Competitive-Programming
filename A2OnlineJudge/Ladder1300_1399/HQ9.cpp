#include <bits/stdc++.h>
const int mod = 1e9 + 7;
using namespace std;
typedef vector<int> vi;
int main() {
#ifndef ONLINE_JUDGE
	freopen("1.txt", "r", stdin);
	freopen("2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	string s; cin >> s;
	bool flag = false;
	for (auto i : s) {
		if (i == 'H' || i == 'Q' || i == '9') {
			flag = true; break;
		}
	}
	if (flag) cout << "YES";
	else cout << "NO";
}
