#include <bits/stdc++.h>
typedef long long ll;
const int mod = 1e9 + 7;
const int MAX = 1e5 + 7;
using namespace std;
typedef vector<int> vi;
class GreenAndBlackTea
{
public:
	void solve() {
		int n, k, a, b;
		cin >> n >> k >> a >> b;
		int cnt = 0;
		string res = "";
		int parity = 0;
		if (a > b) {
			parity = 0;
		} else parity = 1;
		while (a || b) {
			if (parity % 2 == 0) {
				if (a > b) {
					for (int i = 0; i < min(a - b, k); i++) res.push_back('G');
					a -= min(a - b, k);
				} else {
					if (a == 0) break;
					res.push_back('G');
					a--;
				}
			} else {
				if (b > a) {
					for (int i = 0; i < min(b - a, k); i++) res.push_back('B');
					b -= min(b - a, k);
				} else {
					if (b == 0) break;
					res.push_back('B');
					b--;
				}
			}
			parity++;
		}
		if (a == 0 && b == 0)cout << res;
		else cout << "NO\n";
	}

};
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	GreenAndBlackTea g; g.solve();
}
