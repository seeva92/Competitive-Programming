#include <bits/stdc++.h>
#define vi vector<int>
#define pi pair<int,int>
#define vii vector<pi>
#define ll long long
const ll mod = 1e9 + 7;
ll compute(ll a, ll b) {
	ll res = 1;
	ll temp = a;
	while (b) {
		if (b & 1) res = (res * a) % mod;
		a = (a * a) % mod;
		b >>= 1;
	}
	res = (res * (temp + 1)) % mod;
	return res;
}
using namespace std;
int main() {
#ifndef ONLINE_JUDGE
	freopen("/home/shiva/Learning/1.txt", "r", stdin);
	freopen("/home/shiva/Learning/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false); cin.tie(0);
	ll t, n, k;
	cin >> t;
	while (t--) {
		cin >> n >> k;
		cout << compute(k - 1, n - 1) << endl;
	}

}