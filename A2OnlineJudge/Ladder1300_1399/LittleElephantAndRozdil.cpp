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
	int n, x;
	vector<int> v; cin >> n;
	int res = 1e9 + 7, resi;
	for (int i = 0; i < n; i++) {
		cin >> x; v.push_back(x);
		if (res > x) {
			res = x;
			resi = i + 1;
		}
	}

	if (count(v.begin(), v.end(), res) == 1) cout << resi;
	else cout << "Still Rozdil";
}
