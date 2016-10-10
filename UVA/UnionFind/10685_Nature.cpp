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
		for (int i = 0; i < n1; i++) {
			s = findSet(i);
			if (x < stsize[s]) x = stsize[s];
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
	char f[50], s[50]; string str;
	while (scanf("%d %d", &n, &m), n || m) {
		unordered_map<string, int> mp;
		UFDS ufds(n);
		for (int i = 0; i < n; i++) {
			scanf("%s", &f); mp[string(f)] = i;
		} getline(cin, str);
		for (int i = 0; i < m; i++) {
			getline(cin, str); sscanf(str.c_str(), "%s %s", f, s);
			ufds.unionSet(mp[f], mp[s]);
		}
		printf("%d\n", ufds.maxSizeSet());
	}


}