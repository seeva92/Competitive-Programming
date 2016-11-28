#include <bits/stdc++.h>
typedef long long ll;
const int mod = 1e9 + 7;
const int MAX = 1e5 + 7;
using namespace std;
typedef vector<ll> vi;
ll primes[MAX], pId = 0;
bitset<MAX> bs;
void init() {
	bs.set(); bs[0] = bs[1] = 0;
	for (ll i = 2; i * i < MAX; i++)
		if (bs[i]) {
			for (ll j = i * i; j < MAX; j += i) bs[j] = 0;
		}
	for (int i = 0; i < MAX; i++) if (bs[i]) primes[pId++] = i;
	// for (int i = 0; i < pId; i++) cout << primes[i] << "\n";
}
ll cnt(ll n) {
	ll res = n;
	for (int i = 0; i < MAX && primes[i] * primes[i] <= n; i++) {
		if (n % primes[i] == 0) res -= res / primes[i];
		while (n % primes[i] == 0) { n /= primes[i];}
	}
	if (n != 1) res -= res / n;
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
}
