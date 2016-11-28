#include <bits/stdc++.h>
typedef long long ll;
const int mod = 1e9 + 7;
const int MAX = 1e5 + 7;
using namespace std;
typedef vector<int> vi;
vector<ll> v;
void f() {
	string tmp;
	queue<string> q; q.push("4"); q.push("7");
	while (!q.empty() && q.front().size() < 11) {
		tmp = q.front(); v.push_back(stoll(tmp)); q.pop();
		q.push(tmp + "4"); q.push(tmp + "7");
	}
	// cout << v.size() << '\n';
	// for (auto i : v) cout << i << " ";
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	f();
	ll l, r; cin >> l >> r; ll res = 0;
	ll j = 0, len = v.size();
	for (ll i = l; i <= r;) {
		if (j == (ll)v.size()) break;
		if (i <= v[j]) {
			res += (min(v[j], r) - i + 1) * v[j];
			i = v[j] + 1;
		}
		j++;
	}
	cout << res;
}
