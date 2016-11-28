#include <bits/stdc++.h>
const int mod = 1e9 + 7;
using namespace std;
typedef vector<int> vi;
int t, n;
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> t;
	while (t--) {
		cin >> n;
		bool flag = false;
		int pet[n + 5], dist[n + 5];
		for (int i = 0; i < n; i++)cin >> pet[i];
		for (int i = 0; i < n; i++)cin >> dist[i];

		int idx, result = 1e9, maxpet = 0;

		for (int i = 0; i < n; i++) {
			int res = 0;
			vector<int> v;
			int curr = (pet[i] - dist[i]);
			v.push_back(curr + dist[i]);
			res = max(res, curr + dist[i]);

			if (curr < 0) continue;
			int j;
			for (j = (i + 1) % n; j != i; j = (j + 1) % n) {
				curr += (pet[j] - dist[j]);
				v.push_back(curr + dist[j]);
				res = max(res, curr + dist[j]);
				if (curr < 0) break;
			}
			if (j == i) {
				if (res > maxpet) {
					maxpet = res;
					idx = i;
				}
			}
		}
		cout << idx << " " << maxpet << '\n';
	}

}
