#include <bits/stdc++.h>
const int mod = 1e9 + 7;
using namespace std;
typedef vector<int> vi;
int arr[1007][1007];
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m, a, b; cin >> n >> m >> a >> b;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) cin >> arr[i][j];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			if (i - 1 >= 0) arr[i][j] += arr[i - 1][j];
			if (j - 1 >= 0) arr[i][j] += arr[i][j - 1];
			if (i - 1 >= 0 && j - 1 >= 0) arr[i][j] -= arr[i - 1][j - 1];
		}
	// for (int i = 0; i < n; i++, cout << '\n')
	// for (int j = 0; j < m; j++) cout << arr[i][j] << " ";
	// cout << '\n';
	int res = -1e9;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			if ((i + a - 1) < n && (j + b - 1) < m) {
				int total = arr[i + a - 1][j + b - 1];
				if (i - 1 >= 0) total -= arr[i - 1][j + b - 1];
				if (j - 1 >= 0) total -= arr[i + a - 1][j - 1];
				if (i - 1 >= 0 && j - 1 >= 0) total += arr[i - 1][j - 1];
				// cout << i << " " << j << " " << i + a - 1 << " " << i + b - 1 << " " << total << '\n';
				res = max(res, total);
			}
		}
	cout << res << "\n";
}
