#include <bits/stdc++.h>
using namespace std;
class UFDS {
private:
	vector<int> v, rank, stsize; int numSets;
public:
	UFDS(int n) {
		v.assign(n, 0); rank.assign(n, 0); stsize.assign(n, 1); numSets = n - 1;
		for (int i = 0; i < n; i++) v[i] = i;
	}
	int findSet(int i) { return v[i] == i ? i : (v[i] = findSet(v[i]));}
	void unionSet(int i, int j) {
		int x = findSet(i), y = findSet(j);
		if (x != y) {
			numSets--;
			if (rank[x] < rank[y]) {
				stsize[y] += stsize[x]; v[x] = y;
			} else {
				stsize[x] += stsize[y];
				v[y] = x;
				if (rank[x] == rank[y]) rank[x]++;
			}
		}
	}
	int getcount() { return numSets;}
};
int main() {
#ifndef ONLINE_JUDGE
	freopen("1.txt", "r", stdin);
	freopen("2.txt", "w", stdout);
#endif
	int n, m, i, j, t = 0;
	while (scanf("%d %d", &n, &m), n || m) {
		UFDS ufds(n + 1);
		while (m--) {
			scanf("%d %d", &i, &j); ufds.unionSet(i, j);
		}
		printf("Case %d: %d\n", ++t, ufds.getcount());
	}

}