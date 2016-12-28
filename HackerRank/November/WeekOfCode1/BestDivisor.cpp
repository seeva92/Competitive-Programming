#include <bits/stdc++.h>
typedef long long ll;
const int mod = 1e9 + 7;
const int MAX = 1e5 + 7;
using namespace std;
typedef vector<int> vi;

class BestDivisor
{
	int n;
public:
	int digits(int tmp) {
		int c = 0;
		while (tmp) {
			c += tmp % 10; tmp /= 10;
		}
		return c;
	}
	void solve() {
		cin >> n;
		int len = sqrt(n);
		int res = 0, resi = 0;
		for (int i = 1; i <= len; i++) {
			if (n % i == 0) {
				int tmp = digits(i);
				if (res < tmp) {
					res = tmp; resi = i;
				} else if (res == tmp) {
					resi = min(resi, i);
				}
				if (i != n / i) {
					tmp = digits(n / i);
					if (res < tmp) {
						res = tmp; resi = n / i;
					} else if (res == tmp) {
						resi = min(resi, n / i);
					}
				}
			}
		}
		cout << resi;
	}
};
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	BestDivisor b; b.solve();
}
