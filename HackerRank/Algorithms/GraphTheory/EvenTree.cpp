#include <bits/stdc++.h>
const int mod = 1e9 + 7;
using namespace std;
typedef vector<int> vi;
int n, m, u, v;
vi g[107];
int arr[107] = {0}, vis[107] = {0};
int dfs(int i) {
	if (vis[i]) return 0;
	vis[i] = 1;
	for (auto j : g[i]) {
		if (!vis[j])
			arr[i] += 1 + dfs(j);
	}
	return arr[i];
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
	arr[1] = dfs(1);
	int res = 0;
	for (int i = 1; i <= n; i++) cout << arr[i] << " "; cout << endl;
	for (int i = 2; i <= n; i++)
		if (arr[i] % 2 != 0) res++;
	cout << res << '\n';
}
