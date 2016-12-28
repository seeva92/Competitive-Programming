#include <bits/stdc++.h>
typedef long long ll;
const int mod = 1e9 + 7;
const int MAX = 1e5 + 7;
using namespace std;
typedef vector<int> vi;
pair<int, int> p[107];
bool vis[107];
class PingPong_EasyVersion
{
	int n, idx = 1;
	int id, x, y;
public:
	void solve() {
		cin >> n;
		while (n--) {
			cin >> id >> x >> y;
			if (id == 1) {
				p[idx].first = min(x, y); p[idx].second = max(x, y);
				idx++;
				continue;
			}
			bool flag = false;
			memset(vis, 0, sizeof vis);
			queue<int> q; q.push(x);
			while (!q.empty()) {
				int j = q.front(); q.pop();
				if (j == y) {
					flag = true;
					break;
				}
				if (vis[j]) continue;
				vis[j] = 1;

				for (int i = 1; i < idx; i++) {
					if (!vis[i]) {
						if (p[i].first < p[j].first && p[j].first < p[i].second)
							q.push(i);
						else if (p[i].first < p[j].second && p[j].second < p[i].second)
							q.push(i);
					}
				}
			}
			if (flag) cout << "YES\n";
			else cout << "NO\n";
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
	PingPong_EasyVersion p; p.solve();
}
