#include <bits/stdc++.h>
using namespace std;

class Seg2d {
private:
	struct Node {
		int x, y, val; Node(int xi, int yi, int v) {x = xi, y = yi, val = v;}
	};
	vector<Node> min_st, max_st; int n; vector<vector<int>> v;
public:
	Seg2d(vector<vector<int>> &vi) {
		v = vi; n = int(vi.size()); min_st.assign(16 * n * n, Node(0, 0, INT_MAX));
		max_st.assign(16 * n * n, Node(0, 0, INT_MIN));
		build(0, 0, n - 1, n - 1, 1);
	}
	void build(int i, int j, int ii, int jj, int idx) {
		if (i > ii || j > jj) return;
		if (i == ii && j == jj) {
			min_st[idx] = Node(i, j, v[i][j]);
			max_st[idx] = Node(i, j, v[i][j]); return;
		}
		build(i, j, (i + ii) / 2, (j + jj) / 2, 4 * idx - 2);
		build((i + ii) / 2 + 1, j, ii, (j + jj) / 2, 4 * idx - 1);
		build(i, (j + jj) / 2 + 1, (i + ii) / 2, jj, 4 * idx);
		build((i + ii) / 2 + 1, (j + jj) / 2 + 1, ii, jj, 4 * idx + 1);
		min_st[idx].val = min(min(min_st[4 * idx - 2].val, min_st[4 * idx - 1].val), min(min_st[4 * idx].val, min_st[4 * idx + 1].val));
		max_st[idx].val = max(max(max_st[4 * idx - 2].val, max_st[4 * idx - 1].val), max(max_st[4 * idx].val, max_st[4 * idx + 1].val));
	}
	int query(int i, int j, int ii, int jj, int x1, int y1, int x2, int y2, int idx, bool flag) {
		if (x1 > ii || x2 < i || y1 > jj || y2 < j || i > ii || j > jj) return flag ? INT_MAX : INT_MIN;
		if (x1 <= i && y1 <= j && ii <= x2 && jj <= y2) return flag ? min_st[idx].val : max_st[idx].val;

		int l1 = query(i, j, (i + ii) / 2, (j + jj) / 2, x1, y1, x2, y2, 4 * idx - 2, flag);
		int l2 = query((i + ii) / 2 + 1, j, ii, (j + jj) / 2, x1, y1, x2, y2, 4 * idx - 1, flag);
		int r1 = query(i, (j + jj) / 2 + 1, (i + ii) / 2, jj, x1, y1, x2, y2, 4 * idx, flag);
		int r2 = query((i + ii) / 2 + 1, (j + jj) / 2 + 1, ii, jj, x1, y1, x2, y2, 4 * idx + 1, flag);
		return flag ? min(min(l1, l2), min(r1, r2)) : max(max(l1, l2), max(r1, r2));
	}
	void update(int i, int j, int ii, int jj, int x1, int y1, int val, int idx) {
		if (i > ii || j > jj || x1 > ii || x1 < i || y1 > jj || y1 < j) return;
		if (i == x1 && ii == x1 && j == y1 && jj == y1) { min_st[idx].val = val; max_st[idx].val = val; return;}
		update(i, j, (i + ii) / 2, (j + jj) / 2, x1, y1, val, 4 * idx - 2);
		update((i + ii) / 2 + 1, j, ii, (j + jj) / 2, x1, y1, val, 4 * idx - 1);
		update(i, (j + jj) / 2 + 1, (i + ii) / 2, jj, x1, y1, val, 4 * idx);
		update((i + ii) / 2 + 1, (j + jj) / 2 + 1, ii, jj, x1, y1, val, 4 * idx + 1);
		min_st[idx].val = min(min(min_st[4 * idx - 2].val, min_st[4 * idx - 1].val), min(min_st[4 * idx].val, min_st[4 * idx + 1].val));
		max_st[idx].val = max(max(max_st[4 * idx - 2].val, max_st[4 * idx - 1].val), max(max_st[4 * idx].val, max_st[4 * idx + 1].val));
	}
	int query(int x1, int y1, int x2, int y2, bool flag) {
		return query(0, 0, n - 1, n - 1, x1, y1, x2, y2, 1, flag);
	}
	void update(int x1, int y1, int val) {
		update(0, 0, n - 1, n - 1, x1, y1, val, 1);
	}
	void display() {
		for (auto it : min_st) { printf("%d \n", it.val);}
	}
};

int main() {
#ifndef ONLINE_JUDGE
	freopen("1.txt", "r", stdin);
	freopen("2.txt", "w", stdout);
#endif
	int n, i, j, x1, y1, x2, y2, q; scanf("%d", &n); char c;
	vector<vector<int>> v(n, vector<int>(n));
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			scanf("%d", &v[i][j]);
	scanf("%d", &q); Seg2d st(v);
	for (i = 0; i < q; i++) {
		scanf(" %c %d %d %d", &c, &x1, &y1, &x2);
		if (c == 'q') {
			scanf("%d", &y2); printf("%d %d\n", st.query(x1 - 1, y1 - 1, x2 - 1, y2 - 1, false), st.query(x1 - 1, y1 - 1, x2 - 1, y2 - 1, true));
		} else st.update(x1 - 1, y1 - 1, x2);

	}

	// // st.update(0, 0, 3);
	// // st.update(1, 1, 10);
	// printf("%d\n", st.query(0, 0, 1, 1, true)); printf("%d\n", st.query(0, 0, 1, 1, false));
	// printf("%d\n", st.query(1, 1, 2, 2, true) ); printf("%d\n", st.query(1, 1, 2, 2, false) );
	// printf("%d\n", st.query(1, 1, 2, 2, true) ); printf("%d\n", st.query(1, 1, 2, 2, false) );
	// printf("%d\n", st.query(3, 3, 4, 4, true) ); printf("%d\n", st.query(3, 3, 4, 4, false) );

}