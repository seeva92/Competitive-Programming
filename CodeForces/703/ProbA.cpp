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
	int n, m, c, mis = 0, chris = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> m >> c;
		if (m > c) mis++;
		else if (c > m) chris++;
	}
	if (mis > chris) cout << "Mishka";
	else if (chris > mis) cout << "Chris";
	else cout << "Friendship is magic!^^";
}
