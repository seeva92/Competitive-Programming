#include <bits/stdc++.h>
typedef long long ll;
const int mod = 1e9 + 7;
const int MAX = 1e5 + 7;
using namespace std;
typedef vector<int> vi;
class Compote
{
public:
	void solve() {
		int a, b, c;
		cin >> a >> b >> c;
		ll res = 0;
		for (int i = 1; i <= 1000; i++) {
			int aa = i, bb = i * 2, cc = i * 4;
			if (a >= aa && b >= bb && c >= cc) {
				res = i;
			} else break;
		}
		cout << (res + (res * 2) + (res * 4));
	}

};
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	Compote c; c.solve();
}
