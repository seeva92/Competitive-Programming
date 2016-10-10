#include <bits/stdc++.h>
const int mod = 1e9 + 7;
using namespace std;
int T, N, M, c, X, Y;
std::vector<pair<int, pair<int, int>>> v;
class UF {
public:
	vector<int> p, rank;
	UF() { p.assign(N, 0); rank.assign(N, 0); for (int i = 0; i < N; i++) p[i] = i;}
	int findSet(int i) { return p[i] == i ? i : p[i] = findSet(p[i]);}
	bool unite(int i, int j) {
		int l = findSet(i), r = findSet(j);
		if (l != r) {
			if (rank[l] < rank[r]) p[l] = r;
			else {
				p[r] = l;
				if (rank[l] == rank[r]) rank[r]++;
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
	cin >> T;
	while (T--) {
		cin >> N >> M;
		v.clear();
		for (int i = 0; i < M; ++i) {
			cin >> X >> Y >> c;
			v.push_back({c, {X - 1, Y - 1}});
		}
		sort(v.begin(), v.end(), greater<pair<int, pair<int, int>>>());
		long long res = 0LL;
		UF u;
		for (auto i : v) {
			if (u.unite(i.second.first, i.second.second)) res += i.first;
		}
		cout << res << '\n';
	}
}
