#include <bits/stdc++.h>
#define SIZE 16
#define left(x) (x<<1)
#define right(x) ((x<<1)+1)
using namespace std;
class SegmentTree {
private:
	vector<int> v, st, lazy; int n;
	bool state;
	void push(int i, int j, int from, int to) {
		if (state) {
			if (lazy[from] != 0) { lazy[to] = lazy[from]; st[to] = (j - i + 1) * lazy[from];}
		} else {
			if (lazy[from] != 0) { lazy[to] += lazy[from]; st[to] += (j - i + 1) * lazy[from];}
		}

	}
	bool update(int s, int e, int i, int j, int val, int idx, SegmentTree & ct) {
		if (i > j || e < i || s > j) return false;

		if (state) {
			printf("%d %d %d %d\n", i, j, st[idx], (j - i + 1)*val);
			if (s <= i && j <= e && st[idx] <= ((j - i + 1) * val)) {
				st[idx] = (j - i + 1) * val; lazy[idx] = val;
				ct.update(i, j, 1, ct);
				printf("Count %d %d\n", i, j, st[idx]); ct.display();
				return true;
			}
		} else {
			if (s <= i && j <= e) {
				st[idx] += (j - i + 1) * val; lazy[idx] += val;
				return true;
			}
		}
		if (state && i == j) return false;

		push(i, (i + j) / 2, idx, left(idx)); push((i + j) / 2 + 1, j, idx, right(idx));
		lazy[idx] = 0;
		bool lf = update(s, e, i, (i + j) / 2, val, left(idx), ct);
		bool rf = update(s, e, (i + j) / 2 + 1, j, val, right(idx), ct);

		st[idx] = st[left(idx)] + st[right(idx)];
		return lf || rf;
	}
	long query(int s, int e, int i, int j, int idx) {
		if (i > j || e < i || s > j) return 0;
		if (s <= i && j <= e ) {  return st[idx];}
		push(i, (i + j) / 2, idx, left(idx)); push((i + j) / 2 + 1, j, idx, right(idx));
		lazy[idx] = 0;
		return query(s, e, i, (i + j) / 2, left(idx)) + query(s, e, (i + j) / 2 + 1, j, right(idx));
	}
public:
	SegmentTree(int size, bool fl) {
		n = size; state = fl;
		st.assign(4 * n, 0); lazy.assign(4 * n, 0);
	}
	bool update(int s, int e, int val, SegmentTree &ct) {
		return update(s, e, 0, n, val, 1, ct);
	}
	long query(int s, int e) { return query(s, e, 0, n, 1);}
	void display() {
		int x = 0; for (auto it : st) printf("%2d ", x++); printf("\n");
		for (auto it : st) printf("%2d ", it); printf("\n");
	}
};
int main() {
#ifndef ONLINE_JUDGE
	freopen("1.txt", "r", stdin);
	freopen("2.txt", "w", stdout);
#endif
	// st.display();
	// // st.update(0, 5, 1); st.display(); printf("%ld\n", st.query(0, 5));
	// st.update(0, 7, 1); st.display(); printf("%ld\n", st.query(6, 7));
	// printf("%ld\n", st.query(4, 7));
	int t, n, l, r, h; scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		SegmentTree count(SIZE, false); SegmentTree height(SIZE, true);
		while (n--) {
			scanf("%d %d %d", &l, &r, &h);
			height.update(l + 1, r, h, count);

			// // height.update(l + 1, r, h); height.display(); printf("%ld\n", height.query(l + 1, r));
			// if (height.update(l + 1, r, h)) {
			// printf("Height\n"); height.display();
			printf("Height\n"); height.display();
			// }
		}
		// count.display();
		printf("%ld\n", count.query(0, SIZE));
	}

}