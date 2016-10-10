#include <bits/stdc++.h>
using namespace std;
class SegmentTree {
private:
	vector<int> v, st, lzy;
	void Push(int i, int j, int from, int to) {
		lzy[to] +=  (lzy[from]);
		st[to] += (j - i + 1) * lzy[from];
	}
	void Update(int i, int j, int ss, int ee, int idx, int val) {
		if (i > j || ee < i || ss > j) return;
		if (ss <= i && j <= ee) {
			st[idx] += (j - i + 1) * val;
			lzy[idx] += val;
			return;
		}
		Push(i, (i + j) / 2, idx, idx << 1);
		Push((i + j) / 2 + 1, j, idx, (idx << 1) + 1);
		lzy[idx] = 0;

		Update(i, i + (j - i) / 2, ss, ee, idx << 1, val);
		Update(i + (j - i) / 2 + 1, j, ss, ee, (idx << 1) + 1, val);
		st[idx] = st[idx << 1] + st[(idx << 1) + 1];
	}
	int Query(int i, int j, int ss, int ee, int idx) {
		if (i > j || ee < i || ss > j) return 0;
		if (ss <= i && j <= ee) {
			return st[idx];
		}
		Push(i, (i + j) / 2, idx, idx << 1);
		Push((i + j) / 2 + 1, j, idx, (idx << 1) + 1);
		lzy[idx] = 0;

		// display();

		int l = Query(i, (i + j) / 2, ss, ee, idx << 1);
		int r = Query((i + j) / 2 + 1, j, ss, ee, (idx << 1) + 1);
		return l + r;
	}
	void BuildTree(int i, int j, int idx) {
		if (i == j) { st[idx] += v[i]; return;}
		BuildTree(i, (i + j) / 2, idx << 1);
		BuildTree((i + j) / 2 + 1, j, (idx << 1) + 1);
		st[idx] = st[(idx << 1)] + st[((idx << 1) + 1)];
	}
public:
	SegmentTree(vector<int> _v) {
		v = _v; st.assign(4 * (int)v.size(), 0); lzy.assign(4 * (int)v.size(), 0);
		BuildTree(0, int(v.size()) - 1, 1);
	}
	void Update(int ss, int ee, int val) {
		Update(0, int(v.size()) - 1, ss, ee, 1, val);
	}
	int Query(int ss, int ee) {
		Query(0, int(v.size()) - 1, ss, ee, 1);
	}
	void display() {
		printf("Actual\n");
		for (int i = 0; i < int(st.size()); i++)printf("%2d ", st[i]); printf("\n");
		printf("Lazy\n");
		for (int i = 0; i < int(lzy.size()); i++) printf("%2d ", lzy[i]); printf("\n");
	}
};
int main() {
#ifndef ONLINE_JUDGE
	freopen("1.txt", "r", stdin);
	freopen("2.txt", "w", stdout);
#endif
	int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	vector<int> v(arr, arr + (sizeof arr / sizeof arr[0]));
	SegmentTree st(v);
	st.display();
	st.Update(0, 4, 2);
	st.Update(5, 9, 2);
	printf("%d\n", st.Query(1, 1));
	printf("%d\n", st.Query(1, 2));
	printf("%d\n", st.Query(1, 3));
	printf("%d\n", st.Query(1, 4));
	printf("%d\n", st.Query(1, 5));
	printf("%d\n", st.Query(1, 6));
	printf("%d\n", st.Query(1, 7));
	printf("%d\n", st.Query(1, 8));
	printf("%d\n", st.Query(1, 9));
	printf("%d\n", st.Query(0, 9));
	st.display();

}