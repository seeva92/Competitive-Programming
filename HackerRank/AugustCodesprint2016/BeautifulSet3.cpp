#include <bits/stdc++.h>
const int mod = 1e9 + 7;
using namespace std;
set<int> x, y, z;
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n; cin >> n;
	bool flag = true;
	int pi = 0, pj = 0, pk = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			for (int k = 0; k < n; k++)
				if (x == y && y == z && i + j + k == n) {
					cout << i << " " << j << " " << k << '\n';
					flag = false;
				}
	}
}
