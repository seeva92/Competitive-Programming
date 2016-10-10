#include <bits/stdc++.h>
using namespace std;
const int size = (int)1e5 + 10;
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
	int getSetSize(int i) { return stsize[findSet(i)];}
};
int main() {
#ifndef ONLINE_JUDGE
	freopen("1.txt", "r", stdin);
	freopen("2.txt", "w", stdout);
#endif
	int t, n, m, i, j;
	char f[50], s[50]; string str;
	scanf("%d", &t);
	unordered_map<string, int> mp; mp.reserve(size);
	while (t--) {
		scanf("%d", &n);
		mp.clear();
		UFDS ufds(size);
		int idx = 0;
		for (int i = 0; i < n; i++) {
			scanf("%s %s", &f, &s);
			if (mp.find(f) == mp.end()) mp[f] = idx++;
			if (mp.find(s) == mp.end()) mp[s] = idx++;
			ufds.unionSet(mp[f], mp[s]);
			printf("%d\n", ufds.getSetSize(mp[f]));
		}
	}
}