#include <bits/stdc++.h>
typedef long long ll;
const int mod = 1e9 + 7;
const int MAX = 1e5 + 7;
using namespace std;
typedef vector<int> vi;
int arr[107];
vector<pair<int, int>> X[1007], Y[1007];
vector<pair<int, int>> edges;
class IceSkating
{
public:
	void dfs(int i, bool flag) {
		if (flag) {
			for (auto j : X[i]) {
				if (!arr[j.second]) {
					arr[j.second] = 1;
					dfs(j.first, false);
				}
			}
		} else {
			for (auto j : Y[i]) {
				if (!arr[j.second]) {
					arr[j.second] = 1;
					dfs(j.first, true);
				}
			}
		}

	}
	void solve() {
		int n, x, y; cin >> n;
		memset(arr, 0, sizeof arr);
		for (int i = 0; i < n; i++) {
			cin >> x >> y;
			X[x].push_back({y, i});
			Y[y].push_back({x, i});
			edges.push_back({x, y});
		}
		int c = 0;
		for (int i = 0; i < n; i++) {
			if (!arr[i]) {
				dfs(edges[i].first, true);
				dfs(edges[i].second, false);
				c++;
			}
		}
		cout << c - 1;
	}
};
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	IceSkating i; i.solve();
}
