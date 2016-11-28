#include <bits/stdc++.h>
typedef long long ll;
const ll mod = 1e9 + 7;
const ll MAX = 1e5 + 7;
const ll EMAX = 1e6 + 7;
using namespace std;
typedef vector<ll> vi;
ll N, X;
ll primes[EMAX], pIdx = 0;
bitset<EMAX> bs;
void init() {
	bs.set(); bs[0] = bs[1] = 0;
	for (ll i = 2; i * i < EMAX; i++)
		if (bs[i]) {
			for (ll j = i * i; j < EMAX; j += i) bs[j] = 0;
		}
	for (ll i = 0; i < EMAX; i++) if (bs[i]) primes[pIdx++] = i;
}
ll cntDiv(ll n) {
	ll res = 1, cnt = 0;
	for (ll i = 0; (i < pIdx) && (primes[i] * primes[i] <= n); i++) {
		cnt = 0;
		while (n % primes[i] == 0) {
			cnt++;
			n /= primes[i];
		}
		res *= (cnt + 1);
		if (res > 3) return res;
	}
	if (n != 1) res *= (1 + 1);
	// cout << res << '\n';
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
	cin >> N;
	for (ll i = 0; i < N; i++) {
		cin >> X;
		ll temp = sqrt(X);
		if ((temp * temp == X) && bs[temp]) cout << "YES\n";
		else cout << "NO\n";
	}
}
