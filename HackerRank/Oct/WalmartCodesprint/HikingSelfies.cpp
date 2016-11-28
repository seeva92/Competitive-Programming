#include <bits/stdc++.h>
const int mod = 1e9 + 7;
using namespace std;
typedef vector<int> vi;
long long fact[15];
void init() {
	fact[0] = fact[1] = 1;
	for (long long i = 2; i < 15; i++) fact[i] = fact[i - 1] * i;
	// for (int i = 1; i < 15; i++) cout << fact[i] << " ";
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	init();
	int n, x;
	cin >> n >> x;
	long long coms = 0;
	for (long long r = 1; r <= n; r++) {
		coms += (fact[n] / (fact[r] * fact[n - r]));
	}
	cout << abs(x - coms) << '\n';
}
