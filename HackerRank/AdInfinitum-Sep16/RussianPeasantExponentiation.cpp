#include <bits/stdc++.h>
// const int mod = 1e9 + 7;
typedef long long ll;
using namespace std;
struct point {
	ll x, y;
	point() {}
	point(ll xx, ll yy) { x = xx, y = yy;}
};
ll q, a, b, k, m;
point mul(point A, point B) {
	point res;
	ll rl, rr, il, ir;
	rl = (A.x * B.x) % m; rl = rl < 0 ? rl + m : rl;
	rr = (A.y * B.y * -1LL) % m; rr = rr < 0 ? rr + m : rr;
	il = (A.x * B.y) % m; il = il < 0 ? il + m : il;
	ir = (A.y * B.x) % m; ir = ir < 0 ? ir + m : ir;
	res.x = (rl + rr) % m;
	res.y = (il + ir) % m;
	return res;
}
void compute(point A) {
	point res(1, 0);
	while (k) {
		if (k & 1) res = mul(res, A);
		A = mul(A, A);
		k >>= 1;
	}
	cout << res.x << " " << res.y << '\n';
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> q;
	while (q--) {
		cin >> a >> b >> k >> m;
		point A(a, b);
		compute(A);
	}
}
