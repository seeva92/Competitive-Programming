#include <bits/stdc++.h>
const int INF = 1e9 + 7;
using namespace std;
typedef vector<int> vi;
int N, M, K, T, X, u, v, w;
int arr[1007] = {0};
vector<pair<int, int>> g[1007];
int dist[1007][1024] = {0};
set<pair<int, pair<int, int>>> q;
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++) {
		cin >> T;
		for (int j = 1; j <= T; j++) {
			cin >> X;
			arr[i] |= (1 << (X - 1));
		}
	}
	for (int i = 0; i < M; i++) {
		cin >> u >> v >> w;
		g[u].push_back({v, w});
		g[v].push_back({u, w});
	}
	for (int i = 0; i <= N; i++)
		for (int j = 0; j < 1024; j++) dist[i][j] = INF;
	//dijkstra
	dist[1][arr[1]] = 0; q.insert({0, {1, arr[1]}});
	while (!q.empty()) {
		auto tmp = *q.begin(); q.erase(q.begin());
		int d = tmp.first, ui = tmp.second.first, msk = tmp.second.second;
		for (auto j : g[ui]) {
			int vi = j.first, cmsk = arr[j.first], cd = j.second;
			if (dist[vi][msk | cmsk] > (d + cd) ) {
				q.erase({dist[vi][msk | cmsk], {vi, msk | cmsk}});
				dist[vi][msk | cmsk] = d + cd;
				//{Distance, {vi, UpdatedMask}
				q.insert({dist[vi][msk | cmsk], {vi, msk | cmsk}});
			}
		}
	}

	int res = INF;
	for (int i = 0; i < (1 << K); i++)
		for (int j = 0; j < (1 << K); j++)
			if ((i | j) == ((1 << K) - 1))
				res = min(res, max(dist[N][i], dist[N][j]));

	cout << res << '\n';
}
