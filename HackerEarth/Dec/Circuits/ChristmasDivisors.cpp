#include <bits/stdc++.h>
typedef long long ll;
const int mod = 1e9 + 7;
const int MAX = 1e5 + 7;
using namespace std;
typedef vector<int> vi;
vector<ll> v;
set<ll> st;
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll k;
	v.push_back(1LL);
	cin >> k;
	ll a, b;
	for (ll i = 0; i < k; i++) {
		cin >> a >> b;
		for (ll j = 0; j < b; j++)
			v.push_back(a);
	}

	ll len = v.size();
	cout << (1LL << len);
	for (ll i = 0; i < (1LL << len); i++) {
		ll res = 1;
		for (ll j = 0; j < len; j++) {
			if (i & (1LL << j)) {
				res *= v[j];
			}
		}
		st.insert(res);
	}
	for (auto i : st) cout << i << " ";
}
