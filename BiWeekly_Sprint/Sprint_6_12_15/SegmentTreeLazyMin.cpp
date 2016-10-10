#include <bits/stdc++.h>
using namespace std;
class SegmentTree {
private:
	vector<int> v, st, lzy;
	void Push(int from, int to) {
		lzy[to] += lzy[from];
		st[to] += lzy[from];
	}
	void Update(int i, int j, int ss, int ee, int idx, int val) {
		if (ee < i || ss > j) return;
		if (ss <= i && j <= ee) {
			st[idx] += val;
			lzy[idx] += val;
			return;
		}
		Push(idx, idx << 1); Push(idx, (idx << 1) + 1);
		lzy[idx] = 0;

		Update(i, i + (j - i) / 2, ss, ee, idx << 1, val);
		Update(i + (j - i) / 2 + 1, j, ss, ee, (idx << 1) + 1, val);
		st[idx] = min(st[idx << 1], st[(idx << 1) + 1]);
	}
	int Query(int i, int j, int ss, int ee, int idx) {
		if (ee < i || ss > j) return INT_MAX;
		if (ss <= i && j <= ee) {
			return st[idx];
		}
		Push(idx, idx << 1); Push(idx, (idx << 1) + 1);
		lzy[idx] = 0;
		int l = Query(i, i + (j - i) / 2, ss, ee, idx << 1);
		int r = Query(i + ((j - i) / 2) + 1, j, ss, ee, (idx << 1) + 1);
		return min(l, r);
	}
	void BuildTree(int i, int j, int idx) {
		if (i == j) { st[idx] += v[i]; return;}
		BuildTree(i, (i + j) / 2, idx << 1);
		BuildTree((i + j) / 2 + 1, j, (idx << 1) + 1);
		st[idx] = min(st[(idx << 1)], st[((idx << 1) + 1)]);
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
		for (int i = 0; i < int(st.size()); i++)printf("%d ", st[i]); printf("\n");
		printf("Lazy\n");
		for (int i = 0; i < int(lzy.size()); i++) printf("%d ", lzy[i]); printf("\n");
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
	st.Update(0, 4, 9); //st.display(); printf("%d\n", st.Query(0, 9));
	st.Update(5, 9, 9); //\st.display(); printf("%d\n", st.Query(0, 9));
	printf("%d\n", st.Query(0, 1));
	printf("%d\n", st.Query(1, 2));
	printf("%d\n", st.Query(2, 3));
	printf("%d\n", st.Query(3, 4));
	printf("%d\n", st.Query(4, 5));
	printf("%d\n", st.Query(5, 6));
	printf("%d\n", st.Query(6, 9));
	st.display();
	// st.Update(2, 3, 0); st.display();
	// st.Update(3, 4, 0); st.display();
	// st.Update(4, 5, 0); st.display();

}