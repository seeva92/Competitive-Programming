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
	int rd, rm, ry, ad, am, ay;
	cin >> rd >> rm >> ry >> ad >> am >> ay;
	if (ry > ay) cout << "10000\n";
	else if (ry == ay) {
		if (rm > am) cout << (rm - am) * 500 << '\n';
		else if (rm == am) {
			if (rd > ad) cout << (rd - ad) * 15 << '\n';
			else cout << "0\n";
		}
		else cout << "0\n";
	}
	else cout << "0\n";

}
