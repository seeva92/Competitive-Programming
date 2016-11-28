#include <bits/stdc++.h>
typedef unsigned long long ll;
const ll mod = 1e9 + 7;
using namespace std;
typedef vector<ll> vi;
ll x, N;
ll arr[100007];
inline bool check(int k) {
	k++;
	ll res = 0;
	for (int i = 0; i < k; i++) res += arr[i];
	if (res > x) return false;
	for (int i = k; i < N; i++) {
		res -= arr[i - k]; res += arr[i];
		if (res > x) return false;
	}
	return true;
}
int search() {
	int l = 0, r = N - 1;
	int res = 0;
	while (l <= r) {
		int mid = (l + r) / 2;
		if (check(mid)) {
			res = mid + 1;
			l = mid + 1;
		} else r = mid - 1;
	}
	return res;
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> x;
	for (ll i = 0; i < N; i++) cin >> arr[i];
	cout << search();
}
