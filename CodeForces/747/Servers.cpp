#include <bits/stdc++.h>
typedef long long ll;
const int mod = 1e9 + 7;
const int MAX = 1e5 + 7;
using namespace std;
typedef vector<int> vi;
int server[107];
class Servers
{
	int n, q, t, k, d;
public:
	void solve() {
		memset(server, 0, sizeof server);
		cin >> n >> q;
		for (int i = 0; i < q; i++) {
			cin >> t >> k >> d;
			int cnt = 0;
			for (int j = 1; j <= n && cnt < k; j++) {
				if (server[j] < t) cnt++;
			}
			if (cnt == k) {
				int sum = 0;
				for (int j = 1; j <= n && cnt > 0; j++) {
					if (server[j] < t) {
						server[j] = t + d - 1;
						cnt--;
						sum += j;
					}
				}
				cout << sum << '\n';
			} else {
				cout << -1 << '\n';
			}
		}
	}

};
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	Servers s; s.solve();
}
