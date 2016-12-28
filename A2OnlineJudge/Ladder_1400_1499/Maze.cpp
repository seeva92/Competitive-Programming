#include <bits/stdc++.h>
typedef long long ll;
const int mod = 1e9 + 7;
const int MAX = 1e5 + 7;
using namespace std;
typedef vector<int> vi;
bool vis[507][507];
int dx[] = { -1, 0, 0, 1};
int dy[] = { 0, -1, 1, 0};
class Maze
{
	int n, m, k;
	vector<string> v;
	stack<pair<int, int>> topo;
public:
	void dfs(int i, int j) {
		if (vis[i][j]) return;
		vis[i][j] = true;
		topo.push({i, j});
		for (int l = 0; l < 4; l++) {
			int x = i + dx[l], y = j + dy[l];
			if (0 <= x && x < n && 0 <= y && y < m && v[x][y] == '.') dfs(x, y);
		}

	}
	void compute() {
		memset(vis, 0, sizeof vis);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++) {
				if (v[i][j] == '.') {
					dfs(i, j); break;
				}
			}
		while (!topo.empty() && k > 0) {
			auto i = topo.top();
			v[i.first][i.second] = 'X';
			topo.pop();
			k--;
		}
		for (int i = 0; i < n; i++) cout << v[i] << '\n';
	}
	void solve() {
		string s;
		cin >> n >> m >> k;
		for (int i = 0; i < n; i++) {
			cin >> s;
			v.push_back(s);
		}
		compute();
	}

};
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	Maze m; m.solve();
}
