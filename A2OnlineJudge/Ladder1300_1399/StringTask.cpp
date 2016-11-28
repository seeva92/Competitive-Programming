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
	string res; char c;
	for (auto i : s) {
		c = i; c = tolower(c);
		if (c == 'a' || c == 'e' ||
		        c == 'i' || c == 'o' ||
		        c == 'u' || c == 'y') continue;
		res.push_back('.'); res.push_back(c);
	}
	cout << res << '\n';
}
