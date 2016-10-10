#include <bits/stdc++.h>
#define vi vector<int>
#define all(v) v.begin(),v.end()
#define pii pair<int,int>
#define vii vector<pii>
#define mp make_pair
struct line {
	int l, r;
	bool operator < (const line &a) const {
		if (l < a.l) return true;
		else if (l == a.l) return abs(r - l) < abs(a.r - a.l);
		return false;
	}

};
using namespace std;
int main() {
#ifndef ONLINE_JUDGE
	freopen("E:/Shiva backup/Shiva/Learning/Learning/UVA/1.txt", "r", stdin);
	freopen("E:/Shiva backup/Shiva/Learning/Learning/UVA/2.txt", "w", stdout);
#endif
	int t, m, li, ri;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &m);
		vector<line> v;
		while (scanf("%d %d", &li, &ri) && (li || ri)) {
			line ln; ln.l = li; ln.r = ri;
			v.push_back(ln);
		}
		sort(all(v));
		// for (auto it : v) printf("%d %d\n", it.l, it.r );
		bool flag = false;
		int i = 0;
		vector<line> res;
		for (int l = 0, r = m; l < m;) {
			line *ptr = NULL;
			for (; i < int(v.size()) && v[i].l <= l; i++) {
				if (ptr == NULL) ptr = &v[i];
				else if (v[i].r >= (*ptr).r) ptr = &v[i];
			}
			if (ptr == NULL) { flag = true; break;}
			else {
				res.push_back(*ptr);
				l = (*ptr).r;
			}
		}
		if (flag) printf("0\n");
		else {
			printf("%d\n", int(res.size()));
			for (auto it : res) printf("%d %d\n", it.l, it.r);
		}
		if(t!=0) printf("\n");
	}

}