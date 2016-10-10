#include <bits/stdc++.h>
using namespace std;
struct edge {int i, j; edge(int ii, int jj) {i = ii; j = jj;}};
char arr[185][185]; int dis[185][185];
int n, m;
void bfs(int i, int j) {
	queue<edge> q; q.push(edge(i, j));
	int distance;
	while (!q.empty()) {
		edge e = q.front(); q.pop();
		distance = abs(i - e.i) + abs(j - e.j);
		if (arr[e.i][e.j] != '1' && distance < dis[e.i][e.j]) dis[e.i][e.j] = distance;
		if (e.i - 1 > 0 && arr[e.i - 1][e.j] != '1' && (dis[e.i][e.j] + 1 < dis[e.i - 1][e.j])) {
			q.push(edge(e.i - 1, e.j)); dis[e.i - 1][e.j] = dis[e.i][e.j] + 1;
		}
		if (e.i + 1 <= n && arr[e.i + 1][e.j] != '1' && (dis[e.i][e.j] + 1 < dis[e.i + 1][j])) {
			q.push(edge(e.i + 1, e.j)); dis[e.i + 1][e.j] = dis[e.i][e.j] + 1;
		}
		if (e.j - 1 > 0 && arr[e.i][e.j - 1] != '1' && (dis[e.i][e.j] + 1 < dis[e.i][e.j - 1])) {
			q.push(edge(e.i, e.j - 1)); dis[e.i][e.j - 1] = dis[e.i][e.j] + 1;
		}
		if (e.j + 1 <= m && arr[e.i][e.j + 1] != '1' && (dis[e.i][e.j] + 1 < dis[e.i][e.j + 1])) {
			q.push(edge(e.i, e.j + 1)); dis[e.i][e.j + 1] = dis[e.i][e.j] + 1;
		}
	}
}
int main() {
// #ifndef ONLINE_JUDGE
// 	freopen("/home/shiva/Learning/1.txt", "r", stdin);
// 	freopen("/home/shiva/Learning/2.txt", "w", stdout);
// #endif
	ios::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int i, j; cin >> n >> m;
		fill(&arr[0][0], &arr[185][0], '0');
		fill(&dis[0][0], &dis[185][0], INT_MAX);


		vector<pair<int, int>> white;
		for (i = 1; i <= n; i++)
			for (j = 1; j <= m; j++) {
				cin >> arr[i][j];
				if (arr[i][j] == '1') {white.push_back(make_pair(i, j)); dis[i][j] = 0;}
			}
		//Brute Force
		// for (i = 1; i <= n; i++)
		// 	for (j = 1; j <= m; j++) {
		// 		if (arr[i][j] == '1') { dis[i][j] = 0; continue;}
		// 		register int l, r;
		// 		for (auto it : white) {
		// 			l = abs(i - it.first); r = abs(j - it.second);
		// 			if (l + r < dis[i][j]) dis[i][j] = l + r;
		// 		}
		// 	}
		for (auto it : white) {
			bfs(it.first, it.second);
		}
		for (i = 1; i <= n; i++, cout << '\n')
			for (j = 1; j <= m; j++)
				cout << dis[i][j] << " ";
	}

}