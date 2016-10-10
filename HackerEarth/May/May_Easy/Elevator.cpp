#include <bits/stdc++.h>
#define vi vector<int>
#define pi pair<int,int>
#define vii vector<pi>
#define ll long long
const ll mod = 1e9 + 7;
using namespace std;
bool oddDivisors(ll val) {
	ll tmp = sqrt(val + .5);
	return (tmp * tmp) == val;
}
ll mult(ll a, ll b, ll p) {
	__int128 res = a;
	res *= b;
	res %= p;
	a = res;
	return a;
}
ll powmod(ll a, ll b, ll p) {
	ll x = 1, y = a;
	while (b>0) {
		if (b % 2 == 1) {
			x = mult(x, y, p);
		}
		y = mult(y, y, p);
		b /= 2;
	}
	return x % p;
}
//Iterations - K define the accuracy For safer side we can set it from 15 - 17. Handle upto 2^64
bool miller_rabin_prime_test(ll n, ll k) {
	if (n < 2) return false;
	if ((n != 2) && (n % 2 == 0)) return false;

	//We take only odd numbers
	ll d = n - 1; // d would be a even number
	//We need to represent n = d * (2^s). Identify the d whose value is odd
	while (d % 2 == 0) {
		d /= 2;
	}
	//Found the odd d value
	//Executing the iterations
	for (int i = 0; i < k; i++) {
		ll temp = d;
		//Generate a random number less n-1
		ll a = rand() % (n - 1) + 1;
		ll modn = powmod(a, temp, n);
		bool flag = false;
		while ((temp != n - 1) && (modn != 1) && (modn != n - 1)) {
			modn = mult(modn, modn, n);
			temp *= 2;
		}
		if (modn != n - 1 && temp%2==0) return false;
	}
	return true;
}
// 84378082 510376552

int main() {
#ifndef ONLINE_JUDGE
	freopen("/home/shiva/Learning/1.txt", "r", stdin);
	freopen("/home/shiva/Learning/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false); cin.tie(0);

	ll n, q, f, k, t;
	cin >> n >> q;
	ll curr = 1, cap = 0;
	ll dis = 0;
	bool flag = false;
	for (ll i = 0; i < q; i++) {
		cin >> t >> f >> k;
		if (t == 1 && !miller_rabin_prime_test(f + k, 15)) continue;
		if (t == 2 && !oddDivisors(f + k)) continue;

		if (t == 1) cap += k;
		else cap -= k;
		dis = (dis + abs(curr - f));
		curr = f;

	}
	cout << dis%mod << " " << cap << endl;

}

