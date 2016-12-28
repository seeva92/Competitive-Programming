#include <bits/stdc++.h>
typedef long long ll;
const int mod = 1e9 + 7;
const int MAX = 1e5 + 7;
using namespace std;
typedef vector<int> vi;
ll arr[5 * MAX], cnt[5 * MAX];
class NumberOfWays
{
	int n;
public:
	void compute() {
		memset(cnt, 0, sizeof cnt);
		ll sum = 0;
		for (int i = 0; i < n; i++) sum += arr[i];
		if (sum % 3 != 0) { cout << "0"; return;}
		else {
			sum /= 3;
			ll curr = 0;
			for (int i = n - 1; i >= 0; i--) {
				curr += arr[i];
				if (curr == sum) cnt[i] = 1;
				if (i + 1 < n) cnt[i] += cnt[i + 1];
			}
			curr = 0;
			ll res = 0;
			for (int i = 0; i < n - 2; i++) {
				curr += arr[i];
				if (curr == sum) {
					res += cnt[i + 2];
				}
			}
			cout << res;
		}

	}
	void solve() {
		cin >> n;
		ll x;
		for (int i = 0; i < n; i++) cin >> arr[i];
		compute();
	}

};
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	NumberOfWays n;
	n.solve();
}
