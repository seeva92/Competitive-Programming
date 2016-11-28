#include <bits/stdc++.h>
typedef long long ll;
const int mod = 1e9 + 7;
const int MAX = 1e5 + 7;
using namespace std;
typedef vector<int> vi;
int n, v;
int a, b;
int vis[3007];
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	memset(vis, 0, sizeof vis);
	cin >> n >> v;
	int tot = 0;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		vis[a] += b;
	}
	for (int i = 1; i <= 3001; i++) {
		int tmp = min(vis[i - 1], v);
		vis[i - 1] -= tmp;
		tot += tmp;

		if (i < 3001) {
			int tmp1 = min(vis[i], v - tmp);
			tot += tmp1;
			vis[i] -= tmp1;
		}
	}
	cout << tot;

}
