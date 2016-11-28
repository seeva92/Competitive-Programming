#include <bits/stdc++.h>
typedef long long ll;
const ll mod = 1e9 + 7;
using namespace std;
typedef vector<ll> vi;
vector<ll> primes;
bitset<55> bs;
ll T, N, L, R;
void init() {
	bs.set(); bs[0] = bs[1] = 0;
	ll len = 50;
	for (ll i = 2; i * i <= len; i++ ) {
		if (bs[i]) {
			for (ll j = i * i; j <= len; j += i) {
				bs[j] = 0;
			}
		}
	}
	for (ll i = 0; i <= len; i++) if (bs[i]) primes.push_back(i);
	// for (auto i : primes) cout << i << " ";
}
ll cnt(ll X) {
	ll res = 0;
	ll len = upper_bound(primes.begin(), primes.end(), N) - primes.begin();
	for (int i = 1; i < (1 << len); i++) {
		ll lcm = 1;
		int cnt = 0;
		for (int j = 0; j < len; j++) {
			if (((i >> j) & 1)) {
				lcm = (lcm * primes[j]) / __gcd(lcm, primes[j]);
				cnt++;
			}
		}
		if (cnt & 1) res += (X / lcm);
		else res -= (X / lcm);
	}

	return res;
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	init();
	cin >> T;
	while (T--) {
		cin >> N >> L >> R;
		cout << cnt(R) - cnt(L - 1) <<  '\n';
	}
}
