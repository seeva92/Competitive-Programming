#include <bits/stdc++.h>
const int mod = 1e9 + 7;
using namespace std;
typedef vector<int> vi;
int t, n; string a, b, c;
void compute(string tmp, long long &c, long long &s) {
	c = 0, s = 0;
	for (auto i : tmp) {
		if (i == '0') { s = 0;}
		else {
			c++; s++;
		}
	}
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> t;
	while (t--) {
		cin >> a >> b >> c >> n;
		long long ac, as, bc, bs, cc, cs;
		compute(a, ac, as);
		compute(b, bc, bs);
		compute(c, cc, cs);
		long long ans = ac + (bc * n) + cc;
		if (cs == 0) ans++;
		else if (cs < int(c.size())) ans -= cs - 1;
		else if (bs < int(b.size())) ans -= bs + cs - 1;
		else ans -= as + (n * bs) + cs - 1;
		cout << ans << '\n';
	}
}
