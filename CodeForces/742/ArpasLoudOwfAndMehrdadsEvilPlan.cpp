#include <bits/stdc++.h>
typedef long long ll;
const int mod = 1e9 + 7;
const int MAX = 1e5 + 7;
using namespace std;
typedef vector<int> vi;
int arr[107], vis[107];
class ArpasLoudOwfAndMehrdadsEvilPlan
{
	int n;
public:
	void solve() {
		cin >> n;
		memset(vis, 0, sizeof vis);
		for (int i = 1; i <= n; i++) cin >> arr[i];

		int res = 1;
		for (int i = 1; i <= n; i++) {
			if (vis[i]) continue;
			int len = 0, p = i;
			do {
				vis[p] = 1;
				p = arr[p];
				len++;
			} while (p != i && len < 200);

			if (len > n) { cout << -1; return;}
			res = res * (len / __gcd(res, len));
		}
		if (res % 2 == 0)cout << res / 2;
		else cout << res;

	}
};
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	ArpasLoudOwfAndMehrdadsEvilPlan a; a.solve();
}
