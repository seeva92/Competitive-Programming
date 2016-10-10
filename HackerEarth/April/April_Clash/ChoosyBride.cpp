#include <bits/stdc++.h>
#define vi vector<int>
#define pi pair<int,int>
#define vii vector<pi>
#define ll long long
#define lt(x) x<<1
#define rt(x) (x<<1)+1
using namespace std;
vector<ll> arr;
int t, n, q;
int tp, l, r, val;
struct node {
	ll lx_c = 1, rx_c = 1;
	ll mx ;
};
class Seg {

public:
	vector<ll> v;
	vector<node> seg;
	inline node newnode(ll val) {
		node tmp; tmp.mx = val;
		return tmp;
	}
	inline node mge(node a, node b) {
		node tmp;
		if (a.mx > b.mx) {
			tmp.mx = a.mx; tmp.rx_c++;
		} else {
			tmp.mx = b.mx; tmp.lx_c++;
		}
		return tmp;
	}
	Seg(vector<ll> & vp) {
		v.assign(vp.begin(), vp.end());
		seg.assign(3 * int(vp.size()), node());
		build(0, int(v.size()) - 1, 1);
	}
	void build(int i, int j, int idx) {
		if (i == j) {
			seg[idx] = newnode(v[i]); return;
		}
		build(i, (i + j) / 2, lt(idx));
		build((i + j) / 2 + 1, j, rt(idx));
		seg[idx] = mge(seg[lt(idx)], seg[rt(idx)]);
		cout << seg[idx].mx << " " << seg[idx].lx_c << " " << seg[idx].rx_c << endl;
	}
	node query(int i, int j, int l, int r, int idx) {
		if (i > j || l > j || r < i) return node();
		if (l <= i && j <= r) return seg[idx];
		node left = query(i, (i + j) / 2, l, r, lt(idx));
		node right = query((i + j) / 2 + 1, j, l, r, rt(idx));
		return mge(left, right);
	}
};

int main() {
#ifndef ONLINE_JUDGE
	freopen("/home/shiva/Learning/1.txt", "r", stdin);
	freopen("/home/shiva/Learning/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> t;
	while (t--) {
		arr.clear();
		cin >> n >> q;
		ll x;
		for (int i = 0; i < n; i++) {
			cin >> x; arr.push_back(x);
		}
		for (auto it : arr) cout << it << " ";
		cout << endl;
		arr[0] += 2; arr[1] += 2;
		for (auto it : arr) cout << it << " ";
		cout << endl;
		Seg s(arr);

		for (auto it : s.seg) {
			cout << it.mx << " " << it.lx_c <<" "<< it.rx_c << endl;
		}
		node tmp = s.query(0, n - 1, 1, 2, 1);
		cout << tmp.lx_c + 1 << " " << tmp.rx_c + 1 << endl;
		// for (int i = 0; i < q; i++) {
		// 	cin >> tp >> l >> r;
		// 	if (tp == 2) {
		// 		cin >> val;
		// 	} else {
		// 		cout<<s.query(0, n - 1, l - 1, r - 1, 1);
		// 	}

		// }
	}

}