#include <bits/stdc++.h>
typedef long long ll;
const int mod = 1e9 + 7;
const int MAX = 1e5 + 7;
using namespace std;
typedef vector<int> vi;

class CinemaLine
{
	int n;
	int t, f, o;
public:
	void solve() {
		int x;  t = f = o = 0;
		cin >> n;
		bool flag = true;
		for (int i = 0; i < n; i++) {
			cin >> x;
			if (flag) {
				if (x == 100) {
					if (f > 0 && t > 0) { f--; t--; }
					else if (t > 2) { t -= 3;}
					else flag = false;
					o++;
				} else if (x == 50) {
					if (t > 0) { t--; }
					else flag = false;
					f++;
				} else t++;
			}
		}
		if (flag) cout << "YES";
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
	CinemaLine c; c.solve();
}
