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
	int n; cin >> n;
	if (n <=  10) cout << 0;
	else if (n - 10 <= 9 || n - 10 == 11) cout << 4;
	else if (n - 10 == 10) {
		cout << 15;
	} else cout << 0;
}
