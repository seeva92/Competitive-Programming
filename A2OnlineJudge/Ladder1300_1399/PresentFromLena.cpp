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
	int col = 2 * n + 1;
	int inc = 1, dec = -2;
	for (int i = 0, l = 2 * n; i >= 0 && i < col; i += inc, l += dec) {
		for (int j = 1; j <= l; j++) cout << " ";
		if (i == 0 || i == col - 1) cout << "0";
		else {
			cout << "0 ";
			int k = 1;
			for ( k = 1; k < i; k++) cout << k << " ";
			for (; k >= 1; k--) cout << k << " ";
			cout << "0";
		}
		// for (int j = 1; j <= l; j++) cout << " ";
		if (l == 0) dec = 2;
		if (i == n) inc = -1;
		cout << '\n';
	}
}
