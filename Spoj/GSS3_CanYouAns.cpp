#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <cstring>
#include <climits>
#define left(x) (x<<1)
#define right(x) (x<<1)+1
#define ll long long

using namespace std;
struct node {
	ll best, sum, left, right;
};
inline node mknode(ll b, ll s, ll l, ll r) {
	node t;
	t.best = b; t.sum = s; t.left = l; t.right = r;
	return t;
}

ll arr[50010];
node seg[200010];
node calculate(node f, node s) {
	ll left = f.left;
	if (f.sum + s.left > left) left = f.sum + s.left;
	ll right = s.right;
	if (s.sum + f.right > right) right = s.sum + f.right;
	ll best = max(f.right + s.left, max(f.best, s.best));
	return mknode(best, f.sum + s.sum, left, right);
}
node build(int idx, int l, int r) {
	if (l == r) return seg[idx] = mknode(arr[l], arr[l], arr[l], arr[l]);

	node left = build(left(idx), l, (l + r) / 2);
	node right = build(right(idx), (l + r) / 2 + 1, r);
	return seg[idx] = calculate(left, right);
}
node max_range(int idx, int l, int r, int i, int j) {
	if (l > r || i > r || j < l) return mknode(INT_MIN, INT_MIN, INT_MIN, INT_MIN);
	if (i <= l && r <= j) return seg[idx];

	node left = max_range(left(idx), l, (l + r) / 2, i, j);
	node right = max_range(right(idx), (l + r) / 2 + 1, r, i, j);
	return calculate(left, right);
}
void update(int idx, int l, int r, int i, int j) {
	if (l > r || i < l || i > r) return;
	if (l == r) {
		seg[idx] = mknode(j, j, j, j); return;
	}
	if (i <= (l + r) / 2)
		update(left(idx), l, (l + r) / 2, i, j);
	else update(right(idx), (l + r) / 2 + 1, r, i, j);
	seg[idx] = calculate(seg[left(idx)], seg[right(idx)]);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("/home/shiva/Learning/1.txt", "r", stdin);
	freopen("/home/shiva/Learning/2.txt", "w", stdout);
#endif
	// ios::sync_with_stdio(false); cin.tie(0);
	int n; scanf("%d", &n);
	for (int i = 1; i <= n; i++) {cin >> arr[i];}
	build(1, 1, n);
	int m; scanf("%d", &m); int x, y;
	int t;
	while (m--) {
		scanf("%d %d %d",&t, &x, &y);
		if(t==0)
			update(1,1,n,x,y);
		else
		printf("%lld\n", max_range(1, 1, n, x, y).best);
	}
}
