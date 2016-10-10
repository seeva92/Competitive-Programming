#include <bits/stdc++.h>
const int mod = 1e9 + 7;
using namespace std;
int arr[1007];
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	int total = 0, x;
	for (int i = 1; i <= n; i++) {
		cin >> x; total += x;
	}
	if (total / 2 == (n - 1)) cout << "Yes";
	else cout << "No";
}
