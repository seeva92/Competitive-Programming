#include <bits/stdc++.h>
using namespace std;
class UFDS {
private:
	vector<int> v, rank, stsize;
public:
	UFDS(int n) {
		v.assign(n, 0); rank.assign(n, 0); stsize.assign(n, 1);
		for (int i = 0; i < n; i++) v[i] = i;
	}
	int findSet(int i) { return v[i] == i ? i : (v[i] = findSet(v[i]));}
	bool isSameSet(int i, int j) { return findSet(i) == findSet(j);}
	void unionSet(int i, int j) {
		int x = findSet(i); int y = findSet(j);
		if (x != y) {
			if (rank[x] < rank[y]) {
				stsize[y] += stsize[x];
				v[x] = y;
			}
			else {
				stsize[x] += stsize[y];
				v[y] = x;
				if (rank[x] == rank[y]) rank[x]++;
			}
		}

	}

	int getsize(int i) { return stsize[findSet(i)];}
};
int main() {
#ifndef ONLINE_JUDGE
	freopen("1.txt", "r", stdin);
	freopen("2.txt", "w", stdout);
#endif
	int n, m, k, x, y, tmp, infected;
	while (scanf("%d %d", &n, &m), n || m) {
		UFDS ufds(n); infected = 0;
		for (int i = 0; i < m; i++) {
			scanf("%d", &k);
			scanf("%d", &x); k--;
			while (k--) {
				scanf("%d", &y);
				ufds.unionSet(x, y);
				x = y;
			}
		}
		printf("%d\n", ufds.getsize(0));
	}

}
// ### My Solution ###
// void compute(int i) {
// 	mv[i] = 1; infected++;
// 	for (int j = 0; j < (int)v[i].size(); j++) {
// 		for (int k = 0; !gv[v[i][j]] && k < (int)g[v[i][j]].size(); k++)
// 			if (!mv[g[v[i][j]][k]])
// 				compute(g[v[i][j]][k]);
// 		gv[v[i][j]] = 1;
// 	}
// }
// int main() {
// #ifndef ONLINE_JUDGE
// 	freopen("1.txt", "r", stdin);
// 	freopen("2.txt", "w", stdout);
// #endif
// 	int n, m, k, x;
// 	while (scanf("%d %d", &n, &m), n || m) {
// 		for (int i = 0; i < size; i++) v[i].clear();
// 		for (int i = 0; i < groups; i++) g[i].clear();
// 		mv.reset(); gv.reset(); infected = 0;
// 		for (int i = 0; i < m; i++) {
// 			scanf("%d", &k);
// 			while (k--) { scanf("%d", &x); v[x].push_back(i); g[i].push_back(x);}
// 		}
// 		compute(0);
// 		printf("%d\n", infected);
// 	}

// }