#include <bits/stdc++.h>
typedef long long ll;
const int mod = 1e9 + 7;
const int MAX = 1e5 + 7;
using namespace std;
typedef vector<int> vi;
class XeniaAndBitOperations
{
	int n, m, p, b;
	vector<ll> v, seg;
public:
	void build(int idx, int i, int j, int flag) {
		if (i == j) { seg[idx] = v[i]; return;}
		build(2 * idx + 1, i, (i + j) / 2, !flag);
		build(2 * idx + 2, (i + j) / 2 + 1, j, !flag);
		if (flag) seg[idx] = seg[2 * idx + 1] | seg[2 * idx + 2];
		else seg[idx] = seg[2 * idx + 1] ^ seg[2 * idx + 2];
	}
	void update(int idx, int i, int j, int pos, int val, int flag) {
		if (i > j || pos < i || pos > j) return;
		if (i == j) {
			seg[idx] = val; return;
		}
		update(2 * idx + 1, i, (i + j) / 2, pos, val, !flag);
		update(2 * idx + 2, (i + j) / 2 + 1, j, pos, val, !flag);

		if (flag) seg[idx] = seg[2 * idx + 1] | seg[2 * idx + 2];
		else seg[idx] = seg[2 * idx + 1] ^ seg[2 * idx + 2];
	}

	void solve() {
		cin >> n >> m;
		int N = (1 << n);
		v.assign(N, 0);
		seg.assign(4 * N, 0);
		for (int i = 0; i < N; i++) cin >> v[i];

		bool flag = n % 2 != 0;
		build(0, 0, N - 1, flag);
		for (int i = 0; i < m; i++) {
			cin >> p >> b;
			update(0, 0, N - 1, p - 1, b, flag);
			cout << seg[0] << '\n';
		}
	}

};
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	XeniaAndBitOperations x; x.solve();
}
