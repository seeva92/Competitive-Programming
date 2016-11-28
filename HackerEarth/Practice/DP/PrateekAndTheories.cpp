#include <bits/stdc++.h>
const int mod = 1e9 + 7;
using namespace std;
typedef vector<int> vi;
pair<int, int> arr[20020];
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t, n; cin >> t; int l, r;
	while (t--) {
		cin >> n;
		int idx  = 0;
		for (int i = 0; i < n; i++) {
			cin >> l >> r;
			arr[idx].first = l; arr[idx].second = 0;
			++idx;
			arr[idx].first = r - 1; arr[idx].second = 1;
			++idx;
		}
		sort(arr, arr + idx);
		int curr = 0;
		int res = 0;
		for (int i = 0; i < idx; i++) {
			if (arr[i].second == 0) {
				curr++;
				res = max(res, curr);
			} else {
				curr--;
			}
		}
		cout << res << '\n';
	}
}
