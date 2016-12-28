#include <bits/stdc++.h>
typedef long long ll;
const int mod = 1e9 + 7;
const int MAX = 1e5 + 7;
using namespace std;
typedef vector<int> vi;

class MaximumAbsurdity
{
	int n, k;
	vector<int> v;
	vector<ll> kv, seg;
public:
	void build(int i, int j, int idx) {
		if (i == j) { seg[idx] = i; return;}
		build(i, (i + j) >> 1, (idx << 1) + 1);
		build((i + j) / 2 + 1, j, (idx << 1) + 2);
		seg[idx] = kv[seg[(idx << 1) + 1]] >= kv[seg[(idx << 1) + 2]] ? seg[(idx << 1) + 1] : seg[(idx << 1) + 2];
	}
	int query(int i, int j, int idx, int l, int r) {
		if (i > j || r < i || l > j) return -1;
		if (l <= i && j <= r) return seg[idx];

		int lval = query(i, (i + j) / 2, 2 * idx + 1, l, r);
		int rval = query((i + j) / 2 + 1, j, 2 * idx + 2, l, r);
		if (lval != -1 && rval != -1) return kv[lval] >= kv[rval] ? lval : rval;
		else if (lval != -1) return lval;
		return rval;
	}
	void solve() {
		cin >> n >> k;
		v.assign(n, 0);
		for (int i = 0; i < n; i++) cin >> v[i];

		ll sum = 0;
		for (int i = 0; i < k; i++) sum += v[i];
		kv.push_back(sum);
		for (int i = k; i < n; i++) {
			sum -= v[i - k]; sum += v[i]; kv.push_back(sum);
		}
		// for (auto i : kv) cout << i << " "; cout << '\n';
		int kvlen = kv.size();
		seg.assign(4 * kvlen, 0);
		build(0, kvlen - 1, 0);
		// cout << query(0, kvlen - 1, 0, 0, -2);

		ll res = 0; int ra, rb, ca, cb;
		for (int i = 0; i < kvlen; i++) {
			ca = query(0, kvlen - 1, 0, 0, i - k);
			cb = i;
			// cout  << ca << " " << cb << '\n';
			if (ca != -1) {
				// cout << kv[ca] + kv[cb] << '\n';
				if (res < kv[ca] + kv[cb]) {
					res = kv[ca] + kv[cb]; ra = ca; rb = cb;
				}
			}
			ca = i; cb = query(0, kvlen - 1, 0, i + k, kvlen - 1);
			// cout << ca << " " << cb << '\n';
			if (cb != -1) {
				// cout << kv[ca] + kv[cb] << '\n';
				if (res < kv[ca] + kv[cb]) {
					res = kv[ca] + kv[cb]; ra = ca; rb = cb;
				}
			}
			// cout << '\n';
		}
		cout << ra + 1 << " " << rb + 1;
	}

};
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	MaximumAbsurdity m;
	m.solve();
}
