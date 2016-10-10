#include <bits/stdc++.h>
const int mod = 1e9 + 7;
using namespace std;
int t; string s;
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> t;
	while (t--) {
		int e = 0, o = 0;
		cin >> s;
		if (s.size() == 1) { cout << "Yes\n"; continue;}
		for (int i = 0; i < int(s.size()); i++)
				if (s[i] == '0') o++; else e++;
		if (o == 1 || e == 1) cout << "Yes\n";
		else cout << "No\n";
	}
}
