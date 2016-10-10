#include <bits/stdc++.h>
using namespace std;
class UFDS {
private:
	vector<int> v, rank;
public:
	UFDS(int n) {
		v.assign(n, 0); rank.assign(n, 0); for (int i = 0; i < n; i++) v[i] = i;
	}
	int findSet(int i) { return v[i] == i ? i : (v[i] = findSet(v[i]));}
	void unionSet(int i, int j) {
		int x = findSet(i); int y = findSet(j);
		if (x != y) {
			if (rank[x] < rank[y]) v[x] = y;
			else {
				v[y] = x;
				if (rank[x] == rank[y]) rank[y]++;
			}
		}
	}
	int isSameSet(int i, int j) { return findSet(i) == findSet(j);}
};
int main() {
#ifndef ONLINE_JUDGE
	freopen("1.txt", "r", stdin);
	freopen("2.txt", "w", stdout);
#endif
	int t, n, c, v1, v2;
	int s, us;
	scanf("%d", &t);
	string str;
	while (t--) {
		s = us = 0;
		scanf("%d", &n); 
		UFDS ufds(n + 1); getline(cin, str);
		while (getline(cin, str) && !str.empty()) {
			sscanf(str.c_str(), " %c %d %d", &c, &v1, &v2);
			if (c == 'c') ufds.unionSet(v1, v2);
			else if (ufds.isSameSet(v1, v2)) s++;
			else us++;
		};
		printf("%d,%d\n", s, us);
		if(t!=0) printf("\n");
	}
}