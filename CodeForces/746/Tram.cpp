#include <bits/stdc++.h>
typedef long long ll;
const int mod = 1e9 + 7;
const int MAX = 1e5 + 7;
using namespace std;
typedef vector<int> vi;
class Tram
{
public:
	void solve() {
		int s, x1, x2, t1, t2, p, d;
		cin >> s >> x1 >> x2 >> t1 >> t2 >> p >> d;
		if (x1 <= x2) {
			if (x1 < p) {
				if (d == 1) {
					cout << min(t2 * (x2 - x1), t1 * (2 * s + (x2 - p)));
				} else {
					cout << min(t2 * (x2 - x1), t1 * (x2 + p));
				}
			} else {
				if (d == 1) {
					cout << min(t2 * (x2 - x1), t1 * (x2 - p));
				} else {
					cout << min(t2 * (x2 - x1), t1 * (x2 + p));
				}
			}
		} else {
			if (x1 <= p) {
				if (d == 1) {
					cout << min(t2 * (x1 - x2), t1 * (s - p + s - x2));
				} else {
					cout << min(t2 * (x1 - x2), t1 * (p - x2));
				}
			} else {
				if (d == 1) {
					cout << min(t2 * (x1 - x2), t1 * (s - p + s - x2));
				} else {
					cout << min(t2 * (x1 - x2), t1 * (2 * s + (p - x2)));
				}
			}
		}
	}

};
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	Tram t; t.solve();
}
