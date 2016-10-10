#include <bits/stdc++.h>
#define mp make_pair
#define vi vector<int>
#define pi pair<int,int>
#define vii vector<pi>
#define ll long long
const ll MAX = 1e11;
using namespace std;
ll get_min(ll r, ll g, ll b) {
	ll res = 1e11;
	if (r > 0 && res > r) res = r;
	if (g > 0 && res > g) res = g;
	if (b > 0 && res > b) res = b;
	return res;
}
ll get_mul(ll r, ll g, ll b) {
	ll c = 0;
	if (r > 0) c++; if (g > 0) c++; if (b > 0) c++;
	return c++;
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("/home/shiva/Learning/1.txt", "r", stdin);
	freopen("/home/shiva/Learning/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false); cin.tie(0);
	ll t, r, g, b, k, mul; cin >> t;
	while (t--) {
		cin >> r >> g >> b >> k;
		if (k == 1) {cout << k << endl; continue;}
		ll total = 0;
		ll low = 0;
		ll mul = 3;
		k--;
		while (k) {
			low = get_min(r, b, g);
			if (low >= k) {
				total += (k * mul);
				r -= k; b -= k, g -= k, k -= k;
				continue;
			}
			total += low * mul;
			r -= low, b -= low, g -= low, k -= low;
			mul = get_mul(r, g, b);

		}
		if (get_min(r, b, g) != MAX) total++;
		cout << total << endl;
	}


}