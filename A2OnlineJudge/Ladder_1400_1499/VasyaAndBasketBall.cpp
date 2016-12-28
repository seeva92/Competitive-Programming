#include <bits/stdc++.h>
typedef long long ll;
const int mod = 1e9 + 7;
const int MAX = 2e5 + 7;
using namespace std;
typedef vector<int> vi;
ll n, m, d;
pair<ll, ll> arr[2 * MAX];
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	int k = 0;
	for (ll i = 0; i < n; i++) {
		cin >> d;
		arr[k].first = d; arr[k].second = 1;
		k++;
	}
	cin >> m;
	for (ll i = 0; i < m; i++) {
		cin >> d;
		arr[k].first = d; arr[k].second = 2;
		k++;
	}
	sort(arr, arr + k);
	ll curra = 3LL * n, currb = 3LL * m;
	ll resa = 3LL * n, resb = 3LL * m;
	ll x = 0, y = 0;
	for (int i = 0; i < k; i++) {
		if (arr[i].second == 1) x++;
		else y++;
		if (resa - resb < (curra - x) - (currb - y)) {
			resa = curra - x;
			resb = currb - y;
		}
	}
	cout << resa << ":" << resb;
}
