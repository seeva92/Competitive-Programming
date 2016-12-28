#include <bits/stdc++.h>
typedef long long ll;
const int mod = 1e9 + 7;
const int MAX = 1e5 + 7;
using namespace std;
typedef vector<int> vi;
class LCMChallenge
{
	ll n;
public:
	void solve() {
		ll res = 0;
		cin >> n;
		for (ll i = max(1LL, n - 6); i <= n; i++)
			for (ll j = max(1LL, n - 6); j <= n; j++)
				for (ll k = max(1LL, n - 6); k <= n; k++) {
					ll temp = i * (j / __gcd(i, j));
					temp = temp * (k / __gcd(temp, k));
					// cout << i << " " << j << " " << k << " " << temp << '\n';
					if (res < temp) {
						res = temp;
					}
				}
		cout << res;
	}

};
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	LCMChallenge l; l.solve();
}
