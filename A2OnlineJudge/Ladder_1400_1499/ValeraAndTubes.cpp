#include <bits/stdc++.h>
typedef long long ll;
const int mod = 1e9 + 7;
const int MAX = 1e5 + 7;
using namespace std;
typedef vector<int> vi;
class ValeraAndTubes
{
	int n, m, k;
public:
	void solve() {
		cin >> n >> m >> k;
		int prod = n * m;
		int share = (n * m) / k;
		int lastShare = share + (prod % k);
		int l = 1, r = 1;
		bool fwd = true;
		for (int i = 0; i < k; i++) {
			int curr;
			if (i + 1 == k) {
				curr = lastShare;
				cout << curr;
			}
			else {
				curr = share;
				cout << curr;
			}
			for (int j = 0; j < curr; j++) {
				cout << " " << l << " " << r;
				if (fwd) {
					if (r + 1 > m) {
						l++; fwd = false;
					} else r++;
				} else {
					if (r - 1 < 1) {
						l++; fwd = true;
					} else r--;
				}
			}
			cout << '\n';
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
	ValeraAndTubes v; v.solve();
}
