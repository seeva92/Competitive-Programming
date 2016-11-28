#include <bits/stdc++.h>
typedef unsigned long long ll;
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
	ll t, n, p, k;
	__int128 N, P, K;
	cin >> t;
	while (t--) {
		cin >> n >> k >> p;
		N = n, K = k, P = p;
		if ((K + P - 1) % N == 0) cout << ll(N);
		else cout << ll((K + P - 1) % N);

		if (p % 2 == 0)  cout << " truth\n";
		else cout << " dare\n";
	}
}
