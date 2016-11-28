#include <bits/stdc++.h>
typedef long long ll;
const int mod = 1e9 + 7;
const int MAX = 1e5 + 7;
using namespace std;
typedef vector<int> vi;
int n, m;
class Coach
{
	vector<int> v[50], g[50], ones, twos, threes;
	int gIdx = 0;
	bool vis[50];
	int x, y;
public:
	void dfs(int i) {
		g[gIdx].push_back(i);
		vis[i] = true;
		for (auto j : v[i])
			if (!vis[j]) dfs(j);
	}
	bool valid() {
		for (int i = 0; i < gIdx; i++) {
			if (g[i].size() > 3) { return false;}
		}
		for (int i = 0; i < gIdx; i++)
			if (g[i].size() == 2) twos.push_back(i);
			else if (g[i].size() == 1) ones.push_back(i);
			else threes.push_back(i);
		if (ones.size() < twos.size()) return false;
		if ((ones.size() - twos.size()) % 3 != 0) return false;
		return true;
	}
	void solve() {
		memset(vis, 0, sizeof vis);
		cin >> n >> m;
		for (int i = 0; i < m; i++) {
			cin >> x >> y;
			v[x].push_back(y); v[y].push_back(x);
		}
		for (int i = 1; i <= n; i++) {
			if (!vis[i]) {
				dfs(i);
				gIdx++;
			}
		}
		if (valid()) {
			for (auto i : threes) {
				for (auto j : g[i]) cout << j << " "; cout << '\n';
			}
			for (auto i : twos) {
				for (auto j : g[i]) cout << j << " ";
				cout << g[ones.back()].back() << '\n'; ones.pop_back();
			}
			while (ones.size() > 0) {
				for (int i = 0; i < 3 && ones.size() > 0; i++) {
					cout << g[ones.back()].back() << " "; ones.pop_back();
				}
				cout << '\n';
			}
		} else cout << -1;
	}

};
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	Coach c; c.solve();

}
