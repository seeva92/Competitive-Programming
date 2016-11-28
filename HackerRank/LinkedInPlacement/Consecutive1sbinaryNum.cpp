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
	int n; cin >> n;
	int c = 0, res = 0;
	while (n) {
		if (n & 1) {
			c++; res = max(res, c);
		}
		else c = 0;
		n >>= 1;
	}
	cout << res << '\n';
}
