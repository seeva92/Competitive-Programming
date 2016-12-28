#include <bits/stdc++.h>
typedef long long ll;
const int mod = 1e9 + 7;
const int MAX = 1e5 + 7;
using namespace std;
typedef vector<int> vi;
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m, k;
	cin >> n >> m >> k;
	bool flag = (k % 2) == 0;
	for (int i = 1; i <= n; i++) {
		if (k <= (i * 2 * m)) {
			int len = (i * 2 * m);
			int j = ((i - 1) * 2 * m);
			j = flag ? j + 2 : j + 1;
			for (int desk = 1; j <= len; j += 2, desk++) {
				if (j == k) {
					cout << i << " " << desk << " ";
					if (flag) cout << "R";
					else cout << "L";
					return 0;
				}
			}
		}
	}
}
