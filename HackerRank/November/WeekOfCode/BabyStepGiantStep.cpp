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
	int q, a, b, d;
	cin >> q;
	while (q--) {
		cin >> a >> b >> d;
		if (d == 0) { cout << 0 << '\n'; continue;}
		int ad = mod, bd = mod , abd = mod, bad = mod;
		if (d >= a) {
			if (d % a == 0) ad = d / a;
			else {
				ad = (d / a) + 2;
				if ((d - (a * ((d / a) - 1))) < 2 * a)
					ad = (d / a) + 1;
				abd = d / a;
				abd += (d % a == b ? 1 : 2);
			}
		} else  ad = 2;

		if (d >= b) {
			if (d % b == 0) bd = d / b;
			else {
				bd = (d / b) + 2;
				if ((d - (b * ((d / b) - 1))) < 2 * b)
					bd = (d / b) + 1;
				bad = d / b;
				bad += (d % b == a ? 1 : 2);
			}
		}
		else bd = 2;

		cout << min(min(ad, bd), min(abd, bad)) << '\n';
	}
}
