#include <bits/stdc++.h>
using namespace std;
class UFDS {
private:
	vector<int> v, rank, money;
public:
	UFDS(int n, vector<int> m) {
		v.assign(n, 0); rank.assign(n, 0); money.assign(m.begin(), m.end());
		for (int i = 0; i < n; i++) v[i] = i;
	}

	int findSet(int i) { return v[i] == i ? i : (v[i] = findSet(v[i]));}
	int findMoney(int i) { return money[findSet(i)];}
	void unionSet(int i, int j) {
		int x = findSet(i), y = findSet(j);
		if (x != y) {
			if (rank[x] < rank[y]) { money[y] += money[x]; v[x] = y; }
			else {
				money[x] += money[y];
				v[y] = x;
				if (rank[x] == rank[y]) rank[x]++;
			}

		}
	}
};
int main() {
#ifndef ONLINE_JUDGE
	freopen("1.txt", "r", stdin);
	freopen("2.txt", "w", stdout);
#endif
	int t, n, m, ii, jj, x, i;
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &n, &m);
		vector<int> v;
		for (i = 0; i < n; i++) { scanf("%d", &x); v.push_back(x);}
		UFDS ufds(n, v);
		for (i = 0; i < m; i++) { scanf("%d %d", &ii, &jj); ufds.unionSet(ii, jj);}
		for (i = 0; i < n; i++) if (ufds.findMoney(i) != 0) break;
		if (i != n) printf("IMPOSSIBLE\n");
		else printf("POSSIBLE\n");

	}
}