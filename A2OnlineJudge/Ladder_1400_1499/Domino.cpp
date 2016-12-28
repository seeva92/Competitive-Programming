#include <bits/stdc++.h>
typedef long long ll;
const int mod = 1e9 + 7;
const int MAX = 1e5 + 7;
using namespace std;
typedef vector<int> vi;
int X[107], Y[107];
map<vector<int>, int> mp;
class Domino
{
	int n;
public:
	int compute(int n, int ls, int rs) {
		// cout << ls << " " << rs << '\n';
		if (mp.count({n, ls, rs})) return mp[ {n, ls, rs}];
		if ((ls >= 0 && ls % 2 == 0) && (rs >= 0 && rs % 2 == 0)) return 0;
		if (n == 0) return mod;
		int temp = min(1 + compute(n - 1, ls - X[n - 1] + Y[n - 1], rs - Y[n - 1] + X[n - 1]), compute(n - 1, ls, rs));
		return mp[ {n, ls, rs}] = temp;
	}
	void solve() {
		cin >> n;
		int ls = 0, rs = 0;
		for (int i = 0; i < n; i++) {
			cin >> X[i] >> Y[i];
			ls += X[i]; rs += Y[i];
		}
		// cout << ls << " " << rs;
		int temp = compute(n, ls, rs);
		if (temp >= mod) cout << -1;
		else cout << temp;
	}

};
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	Domino d; d.solve();
	// int x = -10;
	// cout << x % 2;
}
