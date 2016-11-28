#include <bits/stdc++.h>
typedef long long ll;
const int mod = 1e9 + 7;
const int MAX = 1e5 + 7;
using namespace std;
typedef vector<int> vi;
ll arr[MAX], inc = 0, c, x, y;
ll seg[4 * MAX], lazy[4 * MAX];
void build(int idx, int s, int e) {
	if (s == e) {
		seg[idx] = arr[s]; return;
	}
	build(2 * idx, s, (s + e) / 2); build(2 * idx + 1, (s + e) / 2 + 1, e);
	seg[idx] = seg[2 * idx] + seg[2 * idx + 1];
}
void update(int idx, int s, int e, int l, int r, int val) {
	if (lazy[idx] != -1) {
		seg[idx] += (e - s + 1) * lazy[idx];
		if (s != e) {
			lazy[2 * idx] += lazy[idx]; lazy[2 * idx + 1] += lazy[idx];
		}
		lazy[idx] = 0;
	}
	if (s > l || r < s || l > e) return;
	if (l <= s && e <= r) {
		seg[idx] += (e - s + 1) * val;
		// cout << "Update " << seg[idx] << '\n';
		if (s != e) {
			lazy[2 * idx] += val;
			lazy[2 * idx + 1] += val;
		}
		return;
	}
	update(2 * idx, s, (s + e) / 2, l, r, val);
	update(2 * idx + 1, (s + e) / 2 + 1, e, l, r, val);
	seg[idx] = seg[2 * idx] + seg[2 * idx + 1];
}
ll query(int idx, int s, int e, int l, int r) {

	if (s > l || r < s || l > e) return 0;
	if (lazy[idx] != -1) {
		// cout << seg[idx] << " " << s << " " << e << " " << (e - s + 1) * lazy[idx] << '\n';
		seg[idx] += (e - s + 1) * lazy[idx];
		// cout << seg[idx] << " " << s << " " << e << '\n';
		if (s != e) {
			lazy[2 * idx] += lazy[idx]; lazy[2 * idx + 1] += lazy[idx];
		}
		lazy[idx] = 0;
	}
	if (l <= s && e <= r) {
		return seg[idx];
	}
	ll tl = query(2 * idx, s, (s + e) / 2, l, r);
	ll tr = query(2 * idx + 1, (s + e) / 2 + 1, e, l, r);
	// seg[idx] = seg[2 * idx] + seg[2 * idx + 1];
	return tl + tr;
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m; cin >> n >> m;
	memset(lazy, 0, sizeof lazy);
	for (int i = 1; i <= n; i++) cin >> arr[i];
	build(1, 1, n);
	ll temp;
	for (int i = 0; i < m; i++) {
		cin >> c >> x;
		if (c == 1) {
			cin >> y;
			temp = query(1, 1, n, x, x);
			// cout << x << " " << temp << '\n';
			update(1, 1, n, x, x, y - temp);
		} else if (c == 2) {
			update(1, 1, n, 1, n, x);
		} else {
			cout << query(1, 1, n, x, x) << '\n';
		}
	}
}
