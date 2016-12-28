#include <bits/stdc++.h>
const int mod = 1e9 + 7;
using namespace std;
typedef vector<int> vi;
int n, m;
int arr[1007];
int assigned[100007];
vi g[1007];
bool bpm(int i, map<int, bool> & done) {
	for (auto j : g[i]) {
		if (!done[j]) {
			done[j] = 1;
			if (assigned[j] == -1) {
				assigned[j] = i; return true;
			} else if (bpm(assigned[j], done)) {
				assigned[j] = i; return true;
			}
		}
	}
	return false;
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	memset(assigned, -1, sizeof assigned);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		int tmp = sqrt(arr[i]);
		for (int j = 1; j <= tmp; j++) {
			if (arr[i] % j == 0) {
				if (j <= m) g[i].push_back(j);
				if ((j != (arr[i] / j)) && ((arr[i] / j) <= m)) g[i].push_back(arr[i] / j);
			}
		}
		// for (auto j : g[i]) cout << j << " ";
		// cout << '\n';
	}
	//Maximum bipartite matching
	int ans = 0;
	for (int i = 0; i < n; i++) {
		map<int, bool> done;
		ans += bpm(i, done);
	}
	cout << ans << '\n';
}
