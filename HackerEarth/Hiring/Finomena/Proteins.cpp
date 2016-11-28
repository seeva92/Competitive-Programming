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
	int t; cin >> t;
	while (t--) {
		string s; cin >> s;
		int n, len;
		len = s.size();
		cin >> n;
		for (int i = 0; i < n; i++) {
			string q; cin >> q;
			int qlen = q.size();
			int rs = 0, re = 0, rd = 1e9;

			for (int j = 0; j < len; j++) {
				int cs, ce;
				if (s[j] == q[0]) {
					cs = j; ce = j;
					int k, l;
					for (k = 1, l = j + 1; k < qlen && l < len; l++) {
						if (s[l] == q[k]) {
							ce = l;
							k++;
						}
					}
					if (k == qlen) {
						if ((ce - cs) < rd) {
							rd = ce - cs;
							rs = cs; re = ce;
						}
						// cout << cs + 1 << " " << ce + 1 << '\n';
					}
				}
			}
			if (rd != int(1e9))
				cout << (rs + 1) << "," << (re + 1) << '\n';
			else cout << "-1\n";
		}
	}
}
