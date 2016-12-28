#include <bits/stdc++.h>
typedef long long ll;
const int mod = 1e9 + 7;
const int MAX = 2e5 + 7;
using namespace std;
typedef vector<int> vi;
pair<ll, ll> arr[MAX];
ll stations[MAX];
int n, k, s, t;
bool can(ll val) {
	ll dist;
	ll taken = 0;
	for (int i = 0; i < k; i++) {
		if (i > 0) dist = stations[i] - stations[i - 1];
		else dist = stations[i];
		if (val < dist) return false;
		taken += 2 * dist - min(dist, val - dist);
	}
	return taken <= t;
}
ll getPetrol() {
	ll l = 0, r = s * 3LL;
	ll res = 0;
	while ((r - l) > 1) {
		ll mid = (l + (r - l) / 2LL);
		if (can(mid)) {
			res = mid;
			r = mid;
		} else l = mid;
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

	cin >> n >> k >> s >> t;
	for (int i = 0; i < n; i++) cin >> arr[i].first >> arr[i].second;

	for (int i = 0; i < k; i++) cin >> stations[i];
	stations[k++] = s;
	sort(stations, stations + k);
	ll w = getPetrol();
	if (w == 0) { cout << -1; return 0 ;}
	ll chp = INT_MAX;
	for (int i = 0; i < n; i++) {
		if (w <= arr[i].second) {
			chp = min(chp, arr[i].first);
		}
	}
	if (chp == (ll)INT_MAX) cout << -1;
	else cout << chp;
}
