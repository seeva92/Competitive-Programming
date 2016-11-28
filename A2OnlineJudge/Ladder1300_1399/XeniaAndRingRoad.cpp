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
	long long n, m, x;
	cin >> n >> m;
	long long total = 0;
	long long curr = 1;
	for (long long i = 1; i <= m; i++) {
		cin >> x;
		if (curr == x) continue;
		else if (curr < x) {
			total += x - curr;
			curr = x;
		} else {
			total += (n - curr) + (x);
			curr = x;
		}
	}
	cout << total;
}
