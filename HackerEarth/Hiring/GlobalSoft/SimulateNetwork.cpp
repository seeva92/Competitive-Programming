#include <bits/stdc++.h>
const long long mod = 1e9 + 7;
using namespace std;
typedef vector<long long> vi;
long long N, M, A, B, L, Q, C;
vector<pair<long long, pair<long long, long long>>> edges;
long long parent[100007], rnk[100007];
long long lat[100007], minspan[100007];
void init() {
	for (long long i = 0; i < 100007; i++) {
		parent[i] = i; rnk[i] = 0;
	}
}
inline long long findSet(long long i) { return parent[i] == i ? i : (parent[i] = findSet(parent[i]));}
inline bool unionfind(long long i, long long j) {
	long long x = findSet(i), y = findSet(j);
	if (x != y) {
		if (rnk[x] < rnk[y]) parent[x] = y;
		else {
			parent[y] = x;
			if (rnk[x] == rnk[y]) rnk[x]++;
		}
		return true;
	}
	return false;
}
void compute() {
	sort(edges.begin(), edges.end());
	sort(lat, lat + Q);
	int i = 0;
	for (auto e : edges) {
		if (unionfind(e.second.first, e.second.second)) {
			minspan[i++] = e.first;
		}
	}
	long long res = 0;
	reverse(minspan, minspan + i);
	int qi = 0;
	for (int j = 0; j < i; j++) {
		if (qi < Q && lat[qi] < minspan[j]) {
			res += lat[qi++];
		} else res += minspan[j];
	}
	cout << res << '\n';
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	init();
	cin >> N >> M;
	for (long long i = 0; i < M; i++) {
		cin >> A >> B >> L;
		edges.push_back({L, {A, B}});
	}
	cin >> Q;
	for (long long i = 0; i < Q; i++)cin >> lat[i];
	compute();
}
