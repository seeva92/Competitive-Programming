#include <bits/stdc++.h>
const int mod = 1e9 + 7;
using namespace std;
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n; cin >> n;
	int prev = -1, curr = -1;
	int cres = 1, res = -1e9;
	cin >> prev;
	for (int i = 1; i < n; i++) {
		cin >> curr;
		if (prev < curr) {
			cres++;
			res = max(res, cres);
		} else
			cres = 1;
		prev = curr;
	}
	res = max(res, cres);
	cout << res << '\n';
}
