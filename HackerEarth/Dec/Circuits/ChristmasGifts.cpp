#include <bits/stdc++.h>
typedef long long ll;
const int mod = 1e9 + 7;
const int MAX = 1e5 + 7;
using namespace std;
typedef vector<int> vi;
vector<int> g[MAX];
int color[MAX];
int n, m, u, v;
queue<int> l;
void pwhite(int i) {
	color[i] = 1;
	for (auto j : g[i]) {
		if (color[j] == -1 ) {
			color[j] = 0;
			l.push(j);
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
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	memset(color, -1, sizeof color);
	pwhite(1);
	while (!l.empty()) {
		int i = l.front(); l.pop();
		for (auto j : g[i]) {
			if (color[j] == -1) {
				pwhite(j);
			}
		}
	}
	for (int i = 1; i <= n; i++) cout << color[i] << " ";
}
