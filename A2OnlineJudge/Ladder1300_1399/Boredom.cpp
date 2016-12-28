#include <bits/stdc++.h>
typedef long long ll;
const int mod = 1e9 + 7;
const int MAX = 1e5 + 7;
using namespace std;
typedef vector<int> vi;
class Boredom
{
	ll n, x;
	vector<ll> cnt;
	vector<ll> dp;
public:
	void solve() {
		cin >> n; cnt.assign(MAX, 0); dp.assign(MAX, 0);
		for (int i = 0; i < n; i++) {
			cin >> x;
			cnt[x]++;
		}
		dp[0] = 0; dp[1] = cnt[1];
		for (int i = 2; i < MAX; i++) {
			dp[i] = max(dp[i - 1], dp[i - 2] + cnt[i] * i);
		}
		cout << dp[MAX - 1];
	}
};
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	Boredom b;
	b.solve();
}
