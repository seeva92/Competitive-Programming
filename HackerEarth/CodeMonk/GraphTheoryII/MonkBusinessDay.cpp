#include <bits/stdc++.h>
const int mod = 1e9 + 7;
using namespace std;
int t, n, m, x, y, c;
vector<pair<int, int>> v[107];
int d[107];
bool flag = false;
void compute() {
	flag = false;
	for (int i = 0; i < 107; i++) d[i] = 1e9;
	d[1] = 0;
	for (int i = 1; i < n; i++)
		for (int j = 1; j <= n; j++)
			for (int k = 0; k < int(v[j].size()); k++) {
				auto tmp = v[j][k];
				if (d[j] != (1e9) && (d[tmp.first] > (d[j] + tmp.second))) {
					d[tmp.first] = d[j] + tmp.second;
				}
			}

	for (int j = 1; j <= n; j++)
		for (int k = 0; k < int(v[j].size()); k++) {
			auto tmp = v[j][k];
			if (d[j] != (1e9) && (d[tmp.first] > (d[j] + tmp.second))) {
				flag = true;
				break;
			}
		}
	if (flag) cout << "Yes\n";
	else cout << "No\n";
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> t;
	while (t--) {
		cin >> n >> m;
		flag = false;
		for (int i = 0; i <= n; i++) v[i].clear();
		for (int i = 1; i <= m; i++) {
			cin >> x >> y >> c;
			v[x].push_back({y, -c});
		}
		if (flag) cout << "Yes\n";
		else {
			compute();
		}
	}
}
