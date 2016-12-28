#include <bits/stdc++.h>
typedef long long ll;
const int mod = 1e9 + 7;
const int MAX = 1e5 + 7;
using namespace std;
typedef vector<int> vi;
ll arr[MAX], cnt[4 * MAX];
class ArpaObviousProbAndMehrdadTerribleSoln
{
	ll n, x;
public:
	void solve() {
		memset(cnt, 0, sizeof cnt);
		cin >> n >> x;
		ll res = 0;
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
			res += cnt[arr[i] ^ x];
			cnt[arr[i]]++;
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
	ArpaObviousProbAndMehrdadTerribleSoln a; a.solve();
}
