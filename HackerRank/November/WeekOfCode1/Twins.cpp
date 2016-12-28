#include <bits/stdc++.h>
typedef long long ll;
const int mod = 1e9 + 7;
const int MAX = 1e5 + 7;
using namespace std;
typedef vector<int> vi;
int n, m;
class Twins
{
public:
	inline ll modexp(ll a, ll b, ll c) {
		ll res = 1;
		while (b) {
			if (b & 1) res = (res * a) % c;
			a = (a * a) % c;
			b /= 2;
		}
		return ll(res);
	}
	inline bool miller_rabin(ll n, int k) {
		if (n < 2) return false;
		if (n == 2) return true;
		ll d = n - 1; int c = 0;
		while (d % 2 == 0) {
			d /= 2;
			c++;
		}
		for (int i = 0; i < k; i++) {
			ll a = rand() % (n - 1) + 1;
			ll x = modexp(a, d, n);
			if (x == 1 || x == n - 1) continue;
			for (int j = 0; j < c - 1; j++) {
				x = (x * x) % n;
				if (x == 1) return false;
				if (x == n - 1) break;
			}
			if (x == n - 1) continue;
			return false;
		}
		return true;
	}
	void solve() {
		cin >> n >> m;
		int prev = -1;
		int cnt = 0;
		for (int i = n; i <= m; i++ ) {
			if (i == 1) continue;
			if (miller_rabin(i, 9)) {
				// cout << i << " ";
				if (prev != -1) {
					cnt += abs(prev - i) == 2;
				}
				prev = i;
			}
		}
		cout << cnt;
	}

};
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	Twins t; t.solve();
}
