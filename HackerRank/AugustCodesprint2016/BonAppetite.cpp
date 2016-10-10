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
	int n, x, k, a; cin >> n >> k;
	int total = 0;
	int kitem = 0;
	for (int i = 0; i < n; i++) {
		cin >> x;
		if (k == i) kitem += x;
		else total += x;
	}
	cin >> a;
	if (total / 2 == a) cout << "Bon Appetit";
	else cout << abs(a - (total / 2));
}

