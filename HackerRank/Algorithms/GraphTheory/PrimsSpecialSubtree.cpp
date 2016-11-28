#include <bits/stdc++.h>
const int mod = 1e9 + 7;
using namespace std;
typedef vector<int> vi;
int N, M, u, v, w, S;
vector<pair<int, pair<int, int>>> edges;
class UFDS {
public:
	vi p, rank;
	int n;
	UFDS(int _n) {
		n = _n; p.assign(n, 0); rank.assign(n, 0);
		for (int i = 0; i < n; i++) p[i] = i;
	}
	inline int findSet(int i) { return p[i] == i ? i : p[i] = findSet(p[i]);}
	bool unio(int i, int j) {
		int x = findSet(i), y = findSet(j);
		if (x != y) {
			if (rank[x] < rank[y]) {
				p[x] = y;
			} else {
				p[y] = x;
				if (rank[x] == rank[y]) rank[x]++;
			}
			return true;
		}
		return false;
	}
} ;
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M;
	UFDS uf(N);
	for (int i = 0; i < M; i++) {
		cin >> u >> v >> w;
		edges.push_back({w, {u, v}});
	}
	cin >> S;
	sort(edges.begin(), edges.end());
	int total = 0;
	for (auto e : edges)
		if (uf.unio(e.second.first - 1, e.second.second - 1))
			total += e.first;
	cout << total << '\n';
}
