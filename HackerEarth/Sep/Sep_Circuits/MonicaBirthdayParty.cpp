#include <bits/stdc++.h>
const int mod = 1e9 + 7;
using namespace std;
int arr[1007][1007], total[1007][1007];
int c1, c2, n;
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	memset(total, 0, sizeof total);
	cin >> n >> c1 >> c2;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> arr[i][j]; total[i][j] = total[i][j - 1] + arr[i][j];
		}
	}
	vector<pair<int, int>> v;
	for (int i = 1; i <= n; i++) v.push_back({total[i][n], i});
	sort(v.begin(), v.end());



}
