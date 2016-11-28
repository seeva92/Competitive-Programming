#include <bits/stdc++.h>
const int mod = 1e9 + 7;
using namespace std;
typedef vector<int> vi;
int main() {
#ifndef ONLINE_JUDGE
	freopen("1.txt", "r", stdin);
	freopen("2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	string a, b;
	cin >> a >> b;
	for (int i = 0; i < int(a.size()); i++) {
		if (a[i] == b[i]) cout << '0';
		else cout << '1';
	}
}
