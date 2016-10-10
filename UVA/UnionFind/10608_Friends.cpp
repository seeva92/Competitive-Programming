#include <bits/stdc++.h>
using namespace std;
class UFDS {
private:
	vector<int> v, rank, stsize;
	int n1;
public:
	UFDS(int n) {
		n1 = n;
		v.assign(n, 0); rank.assign(n, 0); stsize.assign(n, 1);
		for (int i = 0; i < n; i++) v[i] = i;
	}
	int findSet(int i) { return v[i] == i ? i : (v[i] = findSet(v[i]));}
	void unionSet(int i, int j) {
		int x = findSet(i); int y = findSet(j);
		if (x != y) {
			if (rank[x] < rank[y]) {
				stsize[y] += stsize[x];
				v[x] = y;
			}
			else {
				stsize[x] += stsize[y];
				v[y] = x; if (rank[x] == rank[y]) rank[x]++;
			}
		}
	}
	int maxSizeSet() {
		int x = 0, s = 0;
		for (int i = 1; i < n1; i++) {
			s = findSet(i);
			if (stsize[s] != 1 && x < stsize[s]) x = stsize[s];
		}
		return x;
	}
};
int main() {
#ifndef ONLINE_JUDGE
	freopen("1.txt", "r", stdin);
	freopen("2.txt", "w", stdout);
#endif
	int t, n, m, i, j;
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &n, &m);
		UFDS ufds(n + 1);
		while (m--) {
			scanf("%d %d", &i, &j);
			ufds.unionSet(i, j);
		}
		printf("%d\n", ufds.maxSizeSet());
	}

}