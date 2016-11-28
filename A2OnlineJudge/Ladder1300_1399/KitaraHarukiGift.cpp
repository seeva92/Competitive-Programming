#include <bits/stdc++.h>
typedef long long ll;
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
	int o = 0, t = 0, x;
	int n; cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> x; if (x == 100) o++; else t++;
	}
	int sum = o * 100 + t * 200;
	if (sum % 200 != 0) cout << "NO";
	else {
		int tmp = sum / 2; bool flag = false;
		for (int i = 0; i <= t; i++) {
			if (200 * i <= tmp && (tmp - (200 * i) <= o * 100)) { flag = true; break;}
		}
		if (flag) cout << "YES"; else cout << "NO";
	}
}
