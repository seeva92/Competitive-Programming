#include <bits/stdc++.h>
typedef long long ll;
const int mod = 1e9 + 7;
const int MAX = 1e5 + 7;
using namespace std;
typedef vector<int> vi;
int arr[2 * MAX];
class WinterIsComing
{
public:
	void solve() {
		int n, k;
		cin >> n >> k;
		int ans = 0, ft = -1, st = -1;
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
			if (arr[i] < 0 ) {
				if (ft == -1) { ft = i; st = i;}
				else {
					st = i;
				}
				ans++;
			}
		}
		if (ans == 0) { cout << ans; return; }
		if (ans > k) { cout << -1; return;}
		k -= ans;
		ans *= 2;

		int cnt = 0;
		multiset<int> mst;
		for (int i = ft + 1; i <= st; i++)
			if (arr[i] >= 0) cnt++;
			else {
				mst.insert(cnt); cnt = 0;
			}

		for (auto i : mst) {
			if (i <= k) {
				k -= i;
				ans -= 2;
			}
		}
		int dist = n - 1 - st;
		if (dist <= k) {
			ans -= 1;
			k -= dist;
		}
		cout << ans;
	}

};
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	WinterIsComing w; w.solve();
}
