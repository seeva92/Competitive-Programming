#include <bits/stdc++.h>
const int mod = 1e9 + 7;
using namespace std;
typedef vector<int> vi;
int arr[26];
int main() {
#ifndef ONLINE_JUDGE
	freopen("1.txt", "r", stdin);
	freopen("2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; string x; cin >> t;
	while (t--) {
		cin >> x;
		memset(arr, 0, sizeof arr);
		for (auto i : x) arr[i - 'a']++;
		int i;
		for (i = 0; i < 26 && arr[i] % 2 == 0; i++);
		if (i == 26) cout << 1;
		else cout << -1;
		cout << '\n';
	}
}
