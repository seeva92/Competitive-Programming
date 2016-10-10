#include <bits/stdc++.h>
const int mod = 1e9 + 7;
using namespace std;
int t, n, m, p, c;
int arr[107][107];
int cook[7];
void compute() {
	while (1) {
		int empty = 0, kmin = 1e9;
		for (int k = 1; k <= 6; k++) {
			if (cook[k] == 0) empty++;
			else kmin = min(kmin, cook[k]);
		}
		if (empty == 0) p += (4 * kmin);
		else if (empty == 1) p += (2 * kmin);
		else if (empty == 2) p += (1 * kmin);
		else break;
		for (int k = 1; k <= 6; k++) if (cook[k] > 0) cook[k] -= kmin;
	}
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
		memset(arr, 0, sizeof arr);
		cin >> n;

		vector<pair<int, int>> ps; ps.clear();
		for (int i = 0; i < n; i++) {
			p = 0; cin >> m; p += m;
			memset(cook, 0, sizeof cook);
			for (int j = 0; j < m; j++) {
				cin >> c; cook[c]++;
			}
			compute();
			ps.push_back({p, i});
		}
		sort(ps.begin(), ps.end());
		if (n == 1) cout << "chef\n";
		else if (ps[n - 1].first == ps[n - 2].first) cout << "tie\n";
		else if (ps[n - 1].second == 0) cout << "chef\n";
		else cout << ps[n - 1].second + 1 << '\n';
	}
}
