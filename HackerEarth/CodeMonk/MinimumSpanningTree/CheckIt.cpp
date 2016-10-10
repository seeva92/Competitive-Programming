#include <bits/stdc++.h>
const int mod = 1e9 + 7;
using namespace std;
int T, N, M, X, Y;
vector<pair<int, int>> edges;
class UF {
public:
	vector<int> p, rank;
	int S;
	UF() {S = 0; p.assign(N, 0); for (int i = 0; i < N; i++) p[i] = i; rank.assign(N, 0);}
	int findSet(int i) { return p[i] == i ? i : p[i] = findSet(p[i]);}
	void unite(int i, int j) {
		int l = findSet(i), r = findSet(j);
		if (l != r) {
			S++;
			if (rank[l] < rank[r]) {
				p[l] = r;
			} else {
				p[r] = l;
				if (rank[l] == rank[r]) rank[l]++;
			}
		}
	}
};

int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> T;
	while (T--) {
		cin >> N >> M;
		edges.clear();
		while (M--) {
			cin >> X >> Y;
			edges.push_back({X - 1, Y - 1});
		}
		UF u;
		for (int i = 0; i < (N - 1); i++) {
			cin >> X;
			u.unite(edges[X - 1].first, edges[X - 1].second);
		}
		if (u.S == (N - 1)) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}
