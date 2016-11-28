#include <bits/stdc++.h>
const int mod = 1e9 + 7;
using namespace std;
typedef unsigned long long ll;
typedef vector<int> vi;
pair<ll, ll> v[100007];
ll arr[100007];
ll n, q, x;
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> q;
	cin >> v[0].first >> v[0].second;
	arr[0] = v[0].second - v[0].first + 1;
	for (int i = 1; i < n; i++) {
		cin >> v[i].first >> v[i].second;
		arr[i] = arr[i - 1] + ( v[i].second - v[i].first + 1);
	}
	// for (int i = 0; i < n; i++)cout << arr[i] << " " ;

	int tmp;
	while (q--) {
		cin >> x;
		tmp = lower_bound(arr, arr + n, x) - arr;
		if (tmp == n) cout << 0 << '\n';
		else {
			if (tmp - 1 >= 0) cout << v[tmp].first + (x - arr[tmp - 1]) - 1 << '\n';
			else cout << v[tmp].first + x - 1 << '\n';
		}
	}
}
