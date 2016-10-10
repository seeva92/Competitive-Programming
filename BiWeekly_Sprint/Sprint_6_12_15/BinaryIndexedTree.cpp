#include <bits/stdc++.h>
using namespace std;
class BinaryIndexedTree {
private:
	vector<int> v, bit;
	int n;
public:
	BinaryIndexedTree(vector<int> arr) {
		v = arr; n = (int)v.size(); bit.assign(n + 1, 0);
	}
	void build() {
		for (int i = 0; i < n; i++)
			for (int j = i + 1; j <= n; j += (j & -j))
				bit[j] += v[i];
	}
	long sum(int i) {
		long total = 0;
		for (; i <= n && i > 0; i -= (i & - i)) total += bit[i];
		return total;
	}
	long sum(int i, int j) {
		return sum(j + 1) - sum(i);
	}
	void update(int i, int val) {
		if (i >= 0 && i < n) {
			v[i] += (val - v[i]);
			for (int j = i + 1; j <= n; j += (j & -j))
				bit[j] += v[i];
		}
	}
	void display() { for (auto it : bit) printf("%d ", it);}
};
int main() {
#ifndef ONLINE_JUDGE
	freopen("1.txt", "r", stdin);
	freopen("2.txt", "w", stdout);
#endif
	int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	vector<int> v (arr, arr + sizeof arr / sizeof arr[0]);
	BinaryIndexedTree bit(v); bit.build();
	bit.display();
	cout << bit.sum(1, 3) << endl; cout << bit.sum(0, 3) << endl;
	cout << bit.sum(0, 9) << endl;
	cout << bit.sum(0, 0) << endl;

}