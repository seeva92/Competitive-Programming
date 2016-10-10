#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
const __int128 mod = 1e18 + 7;
const ll MAX = 1e6 + 7;
const int iter = 20;
ll primes[MAX];
ll pIdx = 0;
bitset<MAX> bs;
ll u = 0;
void sieve() {
	bs.set(); bs[0] = bs[1] = 0;
	ll i, j;
	for (i = 2; i < MAX; i++)
		if (bs[i]) {
			for (j = 2 * i; j < MAX; j += i) bs[j] = 0;
			primes[pIdx++] = i;
		}

	__int128 t;
	for (i = 1; i < pIdx; i++) {
		t = primes[i] * primes[i - 1];
		if (t < mod) {
			primes[i] *= primes[i - 1];
			cout << primes[i] << '\n';
			u = i;
		}
		else break;
	}
	// cout << primes[pIdx - 1];
}


ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b);}
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout << gcd(26, 36);
	// sieve();
	// ll q, n; cin >> q;
	// for (int i = 1; i <= q; i++) {
	// 	cin >> n;
	// 	if (n == 1) {cout << 0 << '\n'; continue;}

	// 	int j;
	// 	for (j = 0; j <= u; j++) {
	// 		if (primes[j] > n) { break;}
	// 	}
	// 	cout << j << '\n';
	// }
}

// set<ll> compute(ll n) {
// 	set<ll> factors;
// 	if (n == 1) return factors;
// 	for (int i = 0; (i < pIdx) && (primes[i]*primes[i] <= n); i++) {
// 		if (n % primes[i] == 0) {
// 			while (n % primes[i] == 0) 	n /= primes[i];
// 			factors.insert(primes[i]);
// 		}
// 	}
// 	if (n != 1) factors.insert(n);
// 	return factors;
// }
// ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b);}
// ll modpow(ll a, ll b, ll c) {
// 	ll res = 1;
// 	while (b) {
// 		if (b & 1) res = (res * a) % c;
// 		a = (a * a) % c;
// 		b >>= 1;
// 	}
// 	return res % c;
// }
// inline bool miller_rabin_test(ll N) {
// 	if (0 <= N && N < MAX) return bs[N];
// 	if (N < 2) return false;
// 	if (N != 2 && N % 2 == 0) return false;

// 	ll D = N - 1;
// 	while (D % 2 == 0) { D /= 2; }

// 	for (int i = 1; i <= iter; i++) {
// 		ll A = (rand() % (N - 1)) + 1;
// 		ll X = modpow(A, D, N);

// 		if (X == 1 || X == N - 1) continue;
// 		while ((D != N - 1) && (X != 1) && (X != N - 1)) {
// 			X = (X * X) % N;
// 			D <<= 1;
// 		}
// 		if (X != N - 1 && D % 2 == 0) return false;
// 	}
// 	return true;
// }
// ll pollardrho(ll n) {
// 	int x, y, a, g = 1;
// 	x = y = rand() % n + 1;
// 	a = rand() % n + 1;
// 	while (g == 1) {
// 		x = (x * x + a) % n;
// 		y = (y * y + a) % n;
// 		y = (y * y + a) % n;
// 		g = gcd(abs(x - y), n);
// 	}
// 	return g;
// }
// set<ll> solve(ll n) {
// 	if (n == 0 || n == 1) return set<ll>();
// 	if ((primes[pIdx - 1] * primes[pIdx - 1]) >= n) return compute(n);

// 	if (miller_rabin_test(n)) {
// 		set< ll > res;
// 		res.insert(n); return res;
// 	}
// 	ll x = pollardrho(n);
// 	set<ll> lt = solve(x);
// 	if (x > 0 && (n / x < n)) {
// 		set<ll> rt = solve(n / x);
// 		lt.insert(rt.begin(), rt.end());
// 	}

// 	return lt;
// }
