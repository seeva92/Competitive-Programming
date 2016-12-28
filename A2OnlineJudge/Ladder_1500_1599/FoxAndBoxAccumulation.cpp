#include <bits/stdc++.h>
typedef long long ll;
const int mod = 1e9 + 7;
const int MAX = 1e5 + 7;
using namespace std;
typedef vector<int> vi;
int arr[107], cnt[107], peak[107];
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n; cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	sort(arr, arr + n, greater<int>());
	int res = 0;
	for (int k = 1; k < 107; k++) {
		memset(cnt, -1, sizeof cnt);
		int i, j;
		for (i = 0, j = 0; i < n; i++, j = (j + 1) % k) {
			if (cnt[j] == -1) {
				cnt[j] = arr[i];
			} else if (cnt[j] > 0) {
				cnt[j] = min(cnt[j] - 1, arr[i]);
			} else break;
		}
		if (i == n) {
			res = k; break;
		}
	}
	cout << res;
}
