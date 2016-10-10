#include <bits/stdc++.h>
#define left(x) x<<1
#define right(x) (x<<1)+1
using namespace std;
class SegmentTree {
private: vector<int> v, st; int n;
public: SegmentTree(vector<int> &vi) {
		v = vi; n = int(v.size()); st.assign(4 * n, 0); build(1, 0, n - 1);
	}
	int state(int val) {
		if (val < 0) return -1;
		if (val > 0) return 1;
		return 0;
	}
	void build(int idx, int i, int j) {
		if (i == j) { st[idx] = state(v[i]);}
		else {
			build(left(idx), i, (i + j) / 2); build(right(idx), (i + j) / 2 + 1, j);
			st[idx] = st[left(idx)] * st[right(idx)];
		}
	}
	void update(int idx, int i, int j, int pos, int val) {
		if (i > j || pos < i || pos > j) return;
		if (i == j) { st[idx] = state(val); return;}
		if (pos <= (i + j) / 2) update(left(idx), i, (i + j) / 2, pos, val);
		else update(right(idx), (i + j) / 2 + 1, j, pos, val);
		st[idx] = st[left(idx)] * st[right(idx)];
	}
	int query(int idx, int i, int j, int l, int r) {
		if (i > j || r < i || l > j) return 1;
		if (l <= i && j <= r) return st[idx];
		return query(left(idx), i, (i + j) / 2, l, r) * query(right(idx), (i + j) / 2 + 1, j, l, r);
	}
	int query(int l, int r) { return query(1, 0, n - 1, l, r);}
	void update(int pos, int val) { update(1, 0, n - 1, pos, val);}
	void display() {
		for (auto it : st)printf("%d ", it); printf("\n");
	}
};
int main() {
#ifndef ONLINE_JUDGE
	freopen("1.txt", "r", stdin);
	freopen("2.txt", "w", stdout);
#endif
	int n, k, i, j, x, y; char c;
	while (scanf("%d %d", &n, &k) != EOF) {
		vector<int> v(n); string res;
		for (i = 0; i < n; i++)scanf("%d", &v[i]); SegmentTree st(v); //st.display();
		for (i = 0; i < k; i++) {
			scanf(" %c %d %d", &c, &x, &y);
			if (c == 'C') { st.update(x - 1, y);}
			else {
				switch (st.query(x - 1, y - 1)) {
				case -1: res += '-'; break;
				case 0: res += '0'; break;
				case 1: res += '+'; break;
				}
			}
		}
		printf("%s\n", res.c_str());
	}

}