#include <bits/stdc++.h>
#define left(x) x<<1
#define right(x) (x<<1)+1
#define SIZE 100010
#define CNT_SIZE 200050
using namespace std;
class SegTree {
private: vector<int> vi, st; int n; int count[CNT_SIZE], start[CNT_SIZE];
public: SegTree(vector<int> &v) {
		vi = v; n = (int)v.size();
		st.assign(4 * n, 0);
		memset(count, 0, sizeof count); memset(start, 0, sizeof start);
		for (int i = 0; i < n; i++) {
			count[vi[i]]++;
			if (count[vi[i]] == 1) start[v[i]] = i;
		}
		Build(0, n - 1, 1);
	}
	void Build(int i, int j, int idx) {
		if (i == j) { st[idx] = count[vi[i]];}
		else {
			Build(i, (i + j) / 2, left(idx)); Build((i + j) / 2 + 1, j, right(idx));
			st[idx] = max(st[left(idx)], st[right(idx)]);
		}
	}
	int Query(int i, int j, int s, int e, int idx) {
		if (i > j || e < i || s > j) return INT_MIN;
		if (s <= i && j <= e) return st[idx];
		return max(Query(i, (i + j) / 2, s, e, left(idx)), Query((i + j) / 2 + 1, j, s, e, right(idx)));
	}
	void Compute(int i, int j) {
		if (vi[i] == vi[j]) { printf("%d\n", j - i + 1); return;}
		int x, y; x = count[vi[i]] - i + start[vi[i]];
		y = j - start[vi[j]] + 1; x = max(x, y);
		int ii = start[vi[i]] + count[vi[i]], jj = start[vi[j]] - 1;
		if (ii <= jj) printf("%d\n", max(x, Query(0, n - 1, ii, jj, 1)));
		else printf("%d\n", x);
	}
};

int main() {
#ifndef ONLINE_JUDGE
	freopen("1.txt", "r", stdin);
	freopen("2.txt", "w", stdout);
#endif
	int n, q, x, y;
	while (scanf("%d", &n), n != 0) {
		scanf("%d", &q);
		vector<int> v(n);
		for (int i = 0; i < n; i++) { scanf("%d", &v[i]); v[i] += SIZE;}
		SegTree st(v);
		for (int i = 0; i < q; i++) {
			scanf("%d %d", &x, &y); st.Compute(x - 1, y - 1);
		}

		// printf("%d\n", (int)v.size() );
	}

}