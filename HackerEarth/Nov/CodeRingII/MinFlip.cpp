#include <bits/stdc++.h>
typedef long long ll;
const int mod = 1e9 + 7;
const int MAX = 1e5 + 7;
using namespace std;
typedef vector<int> vi;
int n, p, q;
string a, b, c;
int cnt = 0;
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> p >> q;
	cin >> a >> b >> c;
	int len = c.size();
	bool flag = true;
	for (int i = 0; i < len; i++) {
		if (c[i] == '0') {
			if (a[i] != b[i]) {
				if (p >= q) {
					if (p == 0) { flag = false; break;}
					p--; cnt++;
				} else {
					if (q == 0) { flag = false; break;}
					q--; cnt++;
				}
			}
		} else {
			if (a[i] == b[i]) {
				if (p >= q) {
					if (p == 0) { flag = false; break;}
					p--; cnt++;
				} else {
					if (q == 0) { flag = false; break;}
					q--; cnt++;
				}
			}
		}
	}
	if (flag) cout << cnt;
	else cout << -1;
}
