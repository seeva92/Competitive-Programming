#include <bits/stdc++.h>
typedef long long ll;
const int mod = 1e9 + 7;
const int MAX = 1e5 + 7;
using namespace std;
typedef vector<int> vi;
class MammothGenomeEncoding
{
	int a = 0, g = 0, c = 0, t = 0, q = 0;
	int n; string s;

public:
	void check() {
		a = g = c = t = q = 0;
		for (int i = 0; i < n; i++) {
			switch (s[i]) {
			case 'A': a++; break;
			case 'G': g++; break;
			case 'C': c++; break;
			case 'T': t++; break;
			case '?': q++; break;
			}
		}
	}
	void solve() {
		cin >> n >> s;
		check();
		int tot = max(max(a, g), max(c, t));
		int na = tot - a;
		int ng = tot - g;
		int nc = tot - c;
		int nt = tot - t;
		if (q < (na + ng + nc + nt)) {
			cout << "===";
		}
		else if ((q - (na + ng + nc + nt)) % 4 == 0) {
			int temp = (q - (na + ng + nc + nt));
			na += (temp / 4);
			ng += (temp / 4);
			nc += (temp / 4);
			nt += (temp / 4);
			for (int i = 0; i < n; i++) {
				if (s[i] == '?') {
					if (na) {
						s[i] = 'A'; na--;
					} else if (ng) {
						s[i] = 'G'; ng--;
					} else if (nc) {
						s[i] = 'C'; nc--;
					} else if (nt) {
						s[i] = 'T'; nt--;
					}
				}
			}
			cout << s;
		} else {
			cout << "===";
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
	MammothGenomeEncoding m; m.solve();
}
