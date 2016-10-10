#include <bits/stdc++.h>
const int mod = 1e9 + 7;
using namespace std;
int n, m, k;
int G[60][60];
bool flag = true;
int a = 0;

void solve(int i, int j, int f, int r) {
	++a; G[i][j] = r;
	if (i == n || i == 1 || j == m || j == 1) flag = false;;
	if (i - 1 >= 1 && G[i - 1][j] == f) solve(i - 1, j, f, r);
	if (i + 1 <= n && G[i + 1][j] == f) solve(i + 1, j, f, r);
	if (j - 1 >= 1 && G[i][j - 1] == f) solve(i, j - 1, f, r);
	if (j + 1 <= m && G[i][j + 1] == f) solve(i, j + 1, f, r);
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> k;
	char c;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {
			cin >> c;
			if (c == '*') G[i][j] = 1;
			else G[i][j] = 0;
		}

	vector < pair<int, pair<int, int>>> comp;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {
			if (G[i][j] == 0) {
				flag = true; a = 0;
				solve(i, j, 0, 2);
				if (flag) {
					comp.push_back({a, {i, j}});
				}
			}
		}
	// cout << "count " << comp.size() << '\n';
	sort(comp.begin(), comp.end(), greater < pair<int, pair<int, int>>>());
	a = 0;
	for (int i = k; i < int(comp.size()); i++) {
		solve(comp[i].second.first, comp[i].second.second, 2, 0);
	}
	cout << a << "\n";
	for (int i = 1; i <= n; i++, cout << '\n')
		for (int j = 1; j <= m; j++)
		{
			if (G[i][j] == 2) cout << '.';
			else cout << '*';
		}

}
