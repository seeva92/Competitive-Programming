#include <bits/stdc++.h>
typedef long long ll;
const int mod = 1e9 + 7;
const int MAX = 1e5 + 7;
using namespace std;
typedef vector<int> vi;
ll arr[2007][2007];
ll diag1[2 * 2007], diag2[2 * 2007];
int n;
struct soln {
	ll val, i, j;
};
soln sols[2];
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			cin >> arr[i][j];
			diag1[i + j] += arr[i][j];
			diag2[i - j + n] += arr[i][j];
		}
	sols[0].val = sols[1].val = -1;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			if (sols[(i + j) & 1].val < diag1[i + j] + diag2[i - j + n] - arr[i][j]) {
				sols[(i + j) & 1].val = diag1[i + j] + diag2[i - j + n] - arr[i][j];
				sols[(i + j) & 1].i = i;
				sols[(i + j) & 1].j = j;
			}
		}
	cout << sols[0].val + sols[1].val << '\n';
	cout << sols[0].i << " " << sols[0].j << " " << sols[1].i << " " << sols[1].j;
}
