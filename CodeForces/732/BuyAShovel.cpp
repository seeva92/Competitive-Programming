#include <bits/stdc++.h>
typedef long long ll;
const int mod = 1e9 + 7;
const int MAX = 1e5 + 7;
using namespace std;
typedef vector<int> vi;
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll k, r; cin >> k >> r;
	if (k == r || k == 10) { cout << 1; return 0;}

	int icnt = 0, ecnt = 0;
	for (int i = 1; i <= 10; i++) {
		icnt++;
		if ((k * i) % 10 == r) break;

	}
	for (int i = 1; i <= 10; i++) {
		ecnt++;
		if ((k * i) % 10 == 0) break;
	}
	// cout << icnt << " " << ecnt << '\n';
	cout << min(icnt, ecnt);
}
