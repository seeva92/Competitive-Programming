#include <bits/stdc++.h>
const int mod = 1e9 + 7;
using namespace std;
long long n, m, k, r, c1, c2;
vector<pair<long long, pair<long long, long long>>> tracks;
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> k;
	while (k--) {
		cin >> r >> c1 >> c2;
		tracks.push_back({r, {c1, c2}});
	}
	sort(tracks.begin(), tracks.end());
	long long res = n * m;
	long long pRow = -1, l, r; l = r = 0;
	for (auto i : tracks) {
		if (pRow != i.first) {
			pRow = i.first;
			l = i.second.first; r = i.second.second;
			res -= (r - l + 1);
		} else {
			if (l <= i.second.first && i.second.first <= r) {
				if (i.second.second > r) {
					res -= (i.second.second - (r + 1) + 1);
					r = i.second.second;
				}
			} else {
				l = i.second.first; r = i.second.second;
				res -= (r - l + 1);
			}
		}
	}
	cout << res << '\n';
}
