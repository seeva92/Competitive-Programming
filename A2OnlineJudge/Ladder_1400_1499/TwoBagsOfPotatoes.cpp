#include <bits/stdc++.h>
typedef long long ll;
const int mod = 1e9 + 7;
const int MAX = 1e5 + 7;
using namespace std;
typedef vector<int> vi;
class TwoBagsOfPotatoes
{
	ll y, k, n;
public:
	void solve() {
		cin >> y >> k >> n;
		bool flag = false;
		for (ll i = (y / k + 1) * k; i - y <= (n - y); i += k) {
			cout << i - y << " ";
			flag = true;
		}
		if (!flag) cout << -1;
	}
};
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	TwoBagsOfPotatoes t; t.solve();
}
