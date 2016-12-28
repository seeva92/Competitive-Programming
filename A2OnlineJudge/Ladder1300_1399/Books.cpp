#include <bits/stdc++.h>
typedef long long ll;
const int mod = 1e9 + 7;
const int MAX = 1e5 + 7;
using namespace std;
typedef vector<int> vi;
ll arr[MAX];
class Books
{
	int n, t;
public:
	inline int compute(int i) {
		ll prev = i > 0 ? arr[i - 1] : 0;
		int l = i, r = n - 1;
		int res = -1e9;
		while (l <= r) {
			int mid = (l + r) / 2;
			if (arr[mid] - prev <= t) {
				res = mid;
				l = mid + 1;
			} else r = mid - 1;
		}
		if (res != -1e9) return res - i + 1;
		return res;
	}
	void solve() {
		cin >> n >> t;
		for (int i = 0; i < n; i++) cin >> arr[i];
		for (int i = 1; i < n; i++) arr[i] += arr[i - 1];
		int res = 0;
		for (int i = 0; i < n; i++) {
			res = max(res, compute(i));
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
	Books b; b.solve();
}
