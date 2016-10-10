#include <bits/stdc++.h>
const int mod = 1e9 + 7;
using namespace std;
int t, n, m, a, b, c;
vector<pair<int, int>> v[5];
map<pair<int, int>, int> mp;
class UF
{
public:
	vector<int> p, rank;
	UF() { p.assign(n, 0); rank.assign(n, 0); for (int i = 0; i < n; i++) p[i] = i;}
	int findSet(int i) { return p[i] == i ? i : p[i] = findSet(p[i]);}
	bool unite(int i, int j) {
		int l = findSet(i), r = findSet(j);
		if (l != r) {
			if (rank[l] < rank[r]) p[l] = r;
			else {
				p[r] = l;
				if (rank[l] == rank[r]) rank[l]++;
			}
			return true;
		}
		return false;
	}
};
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < 5; i++) v[i].clear();
	for (int i = 1; i <= m; i++) {
		cin >> a >> b >> c;
		v[c].push_back({a - 1, b - 1});
	}
	UF male, female;
	//Male
	int mc = 0, fc = 0;
	for (int i = 3; i >= 1; i -= 2) {
		for (auto j : v[i]) {
			if (male.unite(j.first, j.second)) {

				mc++; mp[ {j.first, j.second}]++;
			}
		}
	}
	//Female
	for (int i = 3; i >= 2; i--) {
		for (auto j : v[i]) {

			if (female.unite(j.first, j.second)) {fc++; mp[ {j.first, j.second}]++; }
		}
	}

	if (mc == (n - 1) && fc == (n - 1)) {
		int res = 0;
		for (int i = 1; i <= 3; i++) {
			for (auto j : v[i]) {
				if (mp.count({j.first, j.second})) continue;
				else res++;
			}
		}
		cout << res << '\n';
	} else cout << -1 << '\n';
}

