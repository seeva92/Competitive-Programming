#include <bits/stdc++.h>
const int mod = 1e9 + 7;
using namespace std;
vector<int> v[1007];
bool vis[1007];
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, d; cin >> n >> d;
	int x, y;
	for (int i = 1; i <= d; i++) {
		cin >> x >> y;
		v[x].push_back(y);
	}

	//bfs
	int total = int(1e5), cnt = 0;
	for (int i = 1; i <= n; i++) {
		// cout << i << " " << v[i].size() << "\n";
		memset(vis, 0, sizeof vis);
		queue<int> q; q.push(i); cnt = 1; vis[i] = 1;
		while (!q.empty()) {
			int t = q.front(); q.pop();
			for (auto it : v[t]) {
				if (!vis[it]) {
					vis[it] = 1;
					cnt++;
					q.push(it);
				}
			}
		}
		// if (cnt == 1) continue;
		total = min(total, cnt);
	}
	cout << (total > 0 ? total : 1) << '\n';
}
