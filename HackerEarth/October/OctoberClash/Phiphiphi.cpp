#include <bits/stdc++.h>
// #include <stdio.h>
// #include <stdlib.h>
const int mod = 1e9 + 7;
typedef long long ll;
ll N, K;
using namespace std;
inline ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b);}
inline ll modexp(__int128 a, __int128 b, __int128 c) {
	__int128 res = 1;
	while (b) {
		if (b & 1) res = (res * a) % c;
		a = (a * a) % c;
		b /= 2;
	}
	return ll(res);
}
inline ll rho(__int128 n) {
	if ((n & 1) == 0) return 2;
	__int128 x, y;
	x = y = 2;
	__int128 a = rand() % n + 1;
	__int128 g = 1;
	while (g == 1) {
		x = ((x * x) % n + a) % n;
		y = ((y * y) % n + a) % n;
		y = ((y * y) % n + a) % n;
		g = gcd(abs(ll(x - y)), n);
	}
	return g == n ? rho(n) : g;
}
inline bool miller_rabin(__int128 n, int k) {
	if (n < 2) return false;
	if (n == 2) return true;
	__int128 d = n - 1;
	int c = 0;
	while (d % 2 == 0) {
		d /= 2;
		c++;
	}
	for (int i = 0; i < k; i++) {
		__int128 a = rand() % (n - 1) + 1;
		__int128 x = modexp(a, d, n);
		if (x == 1 || x == n - 1) continue;
		for (int j = 0; j < (c - 1); j++) {
			x = (x * x) % n ;
			if (x == 1) return false;
			if (x == n - 1) break;
		}
		if (x == n - 1) continue;
		return false;
	}
	return true;
}
map<ll, int> pfs;
inline void factors(ll n) {
	if (n == 1) return;
	if (miller_rabin(n, 17)) {
		pfs[n]++;
		return;
	}
	ll fact = rho(n);
	factors(fact);
	factors(n / fact);
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> K;
	while (N > 1 && K > 0) {
		ll temp = N;
		pfs.clear();
		factors(temp);
		for (auto i : pfs) {
			temp -= temp / i.first;
		}
		N = temp;
		// cout << N << " ";
		K--;
	}
	cout << N;
}
