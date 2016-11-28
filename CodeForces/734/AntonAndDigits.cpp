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
	int k2, k3, k5, k6; cin >> k2 >> k3 >> k5 >> k6;
	unsigned long long res = 0;
	while (k2 > 0 && k5 > 0 && k6 > 0) {
		res += 256;
		k2--; k5--; k6--;
	}
	while (k2 > 0 && k3 > 0) {
		res += 32;
		k2--; k3--;
	}
	cout << res << '\n';
}
