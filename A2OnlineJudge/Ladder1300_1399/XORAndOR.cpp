#include <bits/stdc++.h>
typedef long long ll;
const int mod = 1e9 + 7;
const int MAX = 1e5 + 7;
using namespace std;
typedef vector<int> vi;
class XORAndOR
{
	string a, b;
public:
	void solve() {
		cin >> a >> b;
		if (a.size() != b.size()) { cout << "NO"; return;}

		int len = a.size();
		int p = 0, q = 0;
		for (int i = 0; i < len; i++) {
			if (a[i] == '1') p = 1;
			if (b[i] == '1') q = 1;
		}
		if (len == 1) p = 0;
		if (a == b) {
			p = 1; q = 1;
		}
		if (p && q) cout << "YES";
		else cout << "NO";
	}
};
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	XORAndOR x;
	x.solve();
}
