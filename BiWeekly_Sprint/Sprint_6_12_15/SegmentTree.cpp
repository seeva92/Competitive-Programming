#include <bits/stdc++.h>
using namespace std;
class SegmentTree {
private:
	vector<int> v, st;
	void build(int idx, int i, int j) {
		if (i == j)
			st[idx] = v[i];
		else {
			build(idx << 1, i, i + (j - i) / 2); build((idx << 1) + 1, (i + (j - i) / 2) + 1, j);
			st[idx] = st[idx << 1] + st[(idx << 1) + 1];
		}
	}
	long sum(int l, int r, int i, int j, int idx) {
		if (l > j || r < i) return 0;
		if (l <= i && j <= r)
			return st[idx];
		return sum(l, r, i, i + (j - i) / 2, idx << 1) + sum(l, r, i + (j - i) / 2 + 1, j, (idx << 1) + 1);
	}
public:
	SegmentTree(vector<int> & arr) {
		v = arr; st.assign(4 * (int)arr.size(), 0);
		build(1, 0, v.size() - 1);
	}

	void display() {
		for (auto it : st) printf("%d ", it);
	}
	long sum(int l, int r) {
		return sum(l, r, 0, v.size() - 1, 1);
	}
};
int main() {
#ifndef ONLINE_JUDGE
	freopen("1.txt", "r", stdin);
	// freopen("2.txt", "w", stdout);
#endif
	int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	vector<int> v (arr, arr + sizeof arr / sizeof arr[0]);
	SegmentTree st(v);
	st.display();
	cout << st.sum(1, 3) << endl; cout << st.sum(0, 3) << endl;
	cout << st.sum(0, 9) << endl;
	cout << st.sum(0, 0) << endl;
}