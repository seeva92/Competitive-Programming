#include <bits/stdc++.h>
#define vi vector<int>
#define pi pair<int,int>
#define vii vector<pi>
#define ll long long
const ll mod = 1e9 + 7;
ll seg[int(3e6)];
using namespace std;
set<ll> st;
map<ll, ll> cache;
string s, temp;
ll val, ans, len, templl;
inline ll amaze(ll a) {
	st.clear();
	s = to_string(a);
	len = (long long)(s.size()); //reverse(s.begin(), s.end());
	val = 0, ans = 0;
	for (ll i = 0; i < len; i++) {
		val  = 0;
		temp = s.substr(i); templl = stol(temp);
		if (cache.count(templl) != 0) {
			val = cache[templl];
			if (st.count(val) == 0) {
				ans += val; st.insert(val);
			}
		} else {
			for (ll j = i; j < len; j++) {
				val ^= (long long)(s[j] - '0');
				if (st.count(val) == 0) {
					ans += val;
					st.insert(val);
				}
			}
			cache[templl] = val;
		}

	}
	return ans;
}
void build(int i, int j, int idx) {
	if (i == j) {
		// cout << i << endl;
		seg[idx] += amaze(i); return;
	}
	build(i, (i + j) / 2, idx << 1);
	build((i + j) / 2 + 1, j, (idx << 1) + 1);
	seg[idx] = (seg[idx << 1] + seg[(idx << 1) + 1]) % mod;
}
ll query(ll i, ll j, ll l, ll r, ll idx) {
	if (i > j || r < i || j < l) return 0;
	if (l <= i && j <= r) {
		return seg[idx];
	}
	return (query(i, (i + j) / 2, l, r, (idx << 1)) + query((i + j) / 2 + 1, j, l, r, (idx << 1) + 1)) % mod;
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("/home/shiva/Learning/1.txt", "r", stdin);
	freopen("/home/shiva/Learning/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false); cin.tie(0);
	memset(seg, 0, sizeof seg);
	build(1, (long long)(1e6), 1);
	ll t, l, r, res = 0; cin >> t;
	while (t--) {
		cin >> l >> r;
		res = 0;
		if (1 <= l && r <= (long long)(1e6)) cout << query(1, 1e6, l, r, 1) << endl;
		else if (1 <= l && l <= (long long)(1e6) && r > (long long)(1e6)) {
			res = query(1, (long long)(1e6), l, 1e6, 1);
			for (ll i = (long long)(1e6) + 1; i <= r; i++) res = (res + amaze(i)) % mod;
			// cout << "wow";
			cout << res << endl;
		} else if (l > (long long)(1e6)) {
			for (ll i = l; i <= r; i++) res = (res + amaze(i)) % mod;
			// cout << "wow";
			cout << res << endl;
		}

	}

}