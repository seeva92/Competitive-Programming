#include <bits/stdc++.h>
typedef long long ll;
const int mod = 1e9 + 7;
const int MAX = 1e5 + 7;
using namespace std;
typedef vector<int> vi;
ll arr[2 * MAX], seg[8 * MAX], upd[8 * MAX], reorder[2 * MAX];
pair<int, int> pr[2 * MAX], queries[2 * MAX];
int n, q;
class LittleGirlAndMaximumSum
{
public:
	void update(int i, int j, int idx, int l, int r, int val) {
		if (upd[idx] != 0) {
			seg[idx] += (j - i + 1) * upd[idx];
			if (i != j) {
				upd[2 * idx] += upd[idx];
				upd[2 * idx + 1] += upd[idx];
			}
			upd[idx] = 0;
		}
		if (i > j || r < i || j < l) return;

		if (l <= i && j <= r) {
			seg[idx] += (j - i + 1) * val;
			if (i != j) {
				upd[2 * idx] += val;
				upd[2 * idx + 1] += val;
			}
			return;
		}
		update(i, (i + j) / 2, 2 * idx, l, r, val);
		update((i + j) / 2 + 1, j, 2 * idx + 1, l, r, val);
		seg[idx] = seg[2 * idx] + seg[2 * idx + 1];
	}
	int query(int i, int j, int idx, int l, int r) {
		if (i > j || r < i || j < l) return 0;
		if (upd[idx] != 0) {
			seg[idx] += (j - i + 1) * upd[idx];
			if (i != j) {
				upd[2 * idx] += upd[idx];
				upd[2 * idx + 1] += upd[idx];
			}
			upd[idx] = 0;
		}

		if (l <= i && j <= r) return seg[idx];
		return query(i, (i + j) / 2, 2 * idx, l, r) +
		       query((i + j) / 2 + 1, j, 2 * idx + 1, l, r);
	}
	void solve() {
		cin >> n >> q;
		for (int i = 1; i <= n; i++) cin >> arr[i];
		sort(arr + 1, arr + n + 1, greater<ll>());
		memset(seg, 0, sizeof seg); memset(upd, 0, sizeof upd);

		int l, r;
		for (int i = 1; i <= q; i++) {
			cin >> l >> r; queries[i].first = l; queries[i].second = r;
			update(1, n, 1, l, r, 1);
		}

		for (int i = 1; i <= n; i++) {
			pr[i].first = query(1, n, 1, i, i);
			pr[i].second = i;
		}

		sort(pr + 1, pr + n + 1, greater<pair<int, int>>());
		for (int i = 1; i <= n; i++) reorder[pr[i].second] = arr[i];

		for (int i = 1; i <= n; i++) {
			reorder[i] += reorder[i - 1];
		}

		ll res = 0;
		for (int i = 1; i <= q; i++) {
			res += (reorder[queries[i].second] - reorder[queries[i].first - 1]);
		}
		cout << res;
	}
};
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	LittleGirlAndMaximumSum l;
	l.solve();
}
