#include <bits/stdc++.h>
#define lt(x) x<<1
#define rt(x) (x<<1)+1
using namespace std;
class STree {
private: vector<int> v, st; int n;
public: STree(vector<int> &vi) {
		v = vi; n = int(v.size()); st.assign(4 * n, 0); build(0, n - 1, 1);
	}
	void build(int i, int j, int x) {
		if (i == j) { st[x] = v[i];}
		else {
			build(i, (i + j) / 2, lt(x)); build((i + j) / 2 + 1, j, rt(x));
			st[x] = st[lt(x)] + st[rt(x)];
		}
	}
	void update(int i, int j, int pos, int val, int x) {
		if (i > j || pos < i || pos > j) return;
		if (i == j) { st[x] = val; return;}
		else if (pos <= (i + j) / 2) update(i, (i + j) / 2, pos, val, lt(x));
		else if (pos > (i + j) / 2) update((i + j) / 2 + 1, j, pos, val, rt(x));
		st[x] = st[lt(x)] + st[rt(x)];
	}
	int query(int i, int j, int l, int r, int x) {
		if (i > j || l > j || r < i) return 0;
		if (l <= i && j <= r) return st[x];
		return query(i, (i + j) / 2, l, r, lt(x)) + query((i + j) / 2 + 1, j, l, r, rt(x));
	}
	void update(int pos, int val) { update(0, n - 1, pos, val, 1);}
	int query(int l, int r) { return query(0, n - 1, l, r, 1);}
};
int main() {
#ifndef ONLINE_JUDGE
	freopen("1.txt", "r", stdin);
	freopen("2.txt", "w", stdout);
#endif
	int n, i, x, y; char c; char str[100];
	int cas = 1;
	scanf("%d", &n);
	while (n != 0) {
		vector<int> v(n);
		for (i = 0; i < n; i++) scanf("%d", &v[i]);
		STree st(v); gets(str);
		printf("Case %d:\n", cas++);
		while (gets(str) && str[0] != 'E') {
			sscanf(str, " %c %d %d", &c, &x, &y);
			if (c == 'M') {printf("%d\n", st.query(x - 1, y - 1));}
			else st.update(x - 1, y);
		}
		scanf("%d", &n);
		if (n != 0) printf("\n");
		else break;

	}

}