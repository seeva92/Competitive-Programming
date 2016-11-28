#include <bits/stdc++.h>
typedef long long ll;
const ll mod = 1e9 + 7;
const int MAX = 1e5 + 7;
using namespace std;
typedef vector<int> vi;
ll x, y, n;
vector<ll> v;
void compute() {
	for (int i = 0; i < 4; i++)
		v.push_back(v[v.size() - 1] - v[v.size() - 2]);
	// for (auto i : v) cout << i << " "; cout << '\n';
	ll temp = v[(n - 1) % 6];
	temp %= mod;
	if (temp < 0) temp += mod;
	cout << temp % mod;
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> x >> y >> n;
	v.push_back(x); v.push_back(y);
	compute();
}
