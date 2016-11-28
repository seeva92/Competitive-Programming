#include <bits/stdc++.h>
typedef long long ll;
const int mod = 1e9 + 7;
const int MAX = 1e5 + 7;
using namespace std;
typedef vector<int> vi;
int n, m, c, x;
bool lan[107][107], conn[107][107];
bool vis[107];
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	bool flag = false;
	memset(vis, 0, sizeof vis);
	memset(lan, 0, sizeof lan); memset(conn, 0, sizeof vis);
	for (int i = 0; i < n; i++) {
		cin >> c;
		for (int j = 0; j < c; j++) {
			flag = true;
			cin >> x; lan[i][x - 1] = true;
		}
	}
	for (int i = 0; i < n; i++) conn[i][i] = true;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			for (int k = 0; k < m; k++) if (lan[i][k] && lan[j][k]) conn[i][j] = true;

	for (int k = 0; k < n; k++)
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; ++j)
				conn[i][j] |= conn[i][k] && conn[k][j];

	int res = flag ? -1 : 0;

	for (int i = 0; i < n; i++)if (!vis[i]) {
			for (int j = 0; j < n; j++) if (conn[i][j]) vis[j] = true;
			res++;
		}
	cout << res;
}
