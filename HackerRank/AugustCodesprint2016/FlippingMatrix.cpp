#include <bits/stdc++.h>
const int mod = 1e9 + 7;
using namespace std;
typedef long long ll;
int q, n, arr[260][260];
ll sum;
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> q;
	while (q--) {
		cin >> n;
		sum = 0LL;
		for (int i = 0; i < (n << 1); i++)
			for (int j = 0; j < (n << 1); j++) cin >> arr[i][j];

		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++) {
				sum += 1LL * max(max(arr[i][(n << 1) - j - 1], arr[(n << 1) - i - 1][j])
				                 , max(arr[i][j], arr[(n << 1) - i - 1][(n << 1) - j - 1]));
			}
		cout << sum << '\n';
	}
}
