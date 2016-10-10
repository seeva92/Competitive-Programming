#include <bits/stdc++.h>
const int mod = 1e9 + 7;
using namespace std;
int tp, bt;
int n, m, u, v, edges = 0, vertices = 0;
set<int> g[100007];
bool vis[100007];
vector<pair<int, int>> curr;
bool process = false;
double res = -1e9;
int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a % b);
}
void calc() {
	if (vertices != 0 && ((1.0f * edges)  / (1.0f * vertices)) > 1.0f) {
		process = true; return;
	} else {

		if (vertices != 0 && (res < ((1.0f * edges) / (1.0f * vertices)))) {
			res = (1.0f * edges) / (1.0f * vertices);

			tp = edges / __gcd(edges, vertices);
			bt = vertices / __gcd(edges, vertices);
		}
	}
}
inline void dfs(int i) {
	vis[i] = true;
	curr.push_back({g[i].size(), i});
	edges += g[i].size();
	for (auto j : g[i])
		if (!vis[j]) dfs(j);
}
void compute() {
	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			dfs(i);

			edges /= 2;
			vertices = int(curr.size());
			// cout << i << " " << edges << " " << vertices << '\n';
			//Calculate
			calc();
			if (process) return;

			sort(curr.begin(), curr.end());
			for (auto e : curr) {
				edges -= g[e.second].size();
				vertices--;
				//Removing edges;
				for (auto k : g[e.second]) g[k].erase(g[k].find(e.second));
				calc();
				if (process) return;
			}
			edges = 0, vertices = 0;
			curr.clear();
		}
	}
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	memset(vis, 0, sizeof vis);
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		cin >> u >> v; g[u].insert(v);
		g[v].insert(u);
	}

	compute();
	if (process) {
		cout << ">1" << '\n';
	} else {
		cout << tp << "/" << bt << '\n';
	}
}
