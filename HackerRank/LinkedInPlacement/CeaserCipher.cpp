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
	int n, k; string s; cin >> n >> s >> k;
	for (auto i : s) {
		if ('A' <= i && i <= 'Z') cout << char((((i - 'A') + k) % 26) + 'A');
		else if ('a' <= i && i <= 'z')cout << char((((i - 'a') + k) % 26) + 'a');
		else cout << i;
	}
}
