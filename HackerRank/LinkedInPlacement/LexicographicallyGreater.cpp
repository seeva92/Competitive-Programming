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
	int t; cin >> t;
	string s;
	while (t--) {
		cin >> s;
		if (next_permutation(s.begin(), s.end()))
			cout << s << '\n';
		else cout << "no answer\n";
	}
}
