#include <bits/stdc++.h>
const int mod = 1e9 + 7;
#define MAX 100007
using namespace std;

vector<int> v[MAX];
bool vis[MAX];
long long arr[MAX];
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	int n, m, x, y;
	while (t--) {
		cin >> n >> m;

		for (int i = 1; i <= n; i++) v[i].clear();
		memset(vis, 0, sizeof vis);

		for (int i = 1; i <= m; i++) {
			cin >> x >> y;
			v[x].push_back(y); v[y].push_back(x);
		}

		for (int i = 1; i <= n; i++) cin >> arr[i];

		//dfs

		long long total = 0, res = 0;
		for (int i = 1; i <= n; i++) {
			if (vis[i]) continue;
			total = 0;
			stack<int> s; s.push(i);
			while (!s.empty()) {
				int t = s.top(); s.pop();
				if (!vis[t]) {
					total += arr[t]; vis[t] = true;
				}
				for (auto it : v[t]) {
					if (!vis[it]) {
						s.push(it);
					}
				}
			}
			res = max(res, total);
		}
		cout << res << '\n';
	}
}
