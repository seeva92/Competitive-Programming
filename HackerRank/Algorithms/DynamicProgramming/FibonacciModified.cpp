#include <bits/stdc++.h>
const int mod = 1e9 + 7;
using namespace std;
typedef vector<int> vi;
long long t1, t2, n;
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> t1 >> t2 >> n;
	for (int i = 2; i < n; i++) {
		long long temp = t2;
		t2 = t1 + (t2 * t2);
		t1 = temp;
		cout << t2 << '\n';
	}
}
