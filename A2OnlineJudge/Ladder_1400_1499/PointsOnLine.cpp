#include <bits/stdc++.h>
typedef long long ll;
const int mod = 1e9 + 7;
const int MAX = 1e5 + 7;
using namespace std;
typedef vector<int> vi;
ll arr[MAX], rge[MAX];
class PointsOnLine
{
	int n; ll d;
public:
	void solve() {
		cin >> n >> d;
		for (int i = 0; i < n; i++) cin >> arr[i];
		for (int i = 0; i < n; i++) {
			rge[i] = (upper_bound(arr, arr + n, arr[i] + d) - arr) - 1;
		}
		// for (int i = 0; i < n; i++) cout << rge[i] << " "; cout << '\n';
		ll res = 0;
		ll diff;
		for (int i = 0; i < n - 2; i++) {
			diff = rge[i] - i;
			if (diff != 0) {
				res += (diff * (diff - 1)) / 2;
			}
		}
		cout << res;

	}
};
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	PointsOnLine p; p.solve();
}
