#include <bits/stdc++.h>
const int mod = 1e9 + 7;
using namespace std;
typedef vector<int> vi;
int arr[100];
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m; cin >> n >> m;
	for (int i = 0; i < m; i++) cin >> arr[i];
	sort(arr, arr + m);
	// for (int i = 0; i < m; i++) cout << arr[i] << " "; cout << '\n';
	int res = 1e9;
	for (int i = 0; i < (m - n + 1); i++) {
		res = min(res, abs(arr[i] - arr[i + n - 1]));
	}
	cout << res << '\n';
}
