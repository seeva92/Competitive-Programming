#include <bits/stdc++.h>
typedef long long ll;
const int mod = 1e9 + 7;
const int MAX = 1e5 + 7;
using namespace std;
typedef vector<int> vi;
ll arr[507];
class TennisChampionship
{
public:
	void solve() {
		arr[0] = 1; arr[1] = 2;
		for (int i = 2; i <= 500; i++) arr[i] = arr[i - 1] + arr[i - 2];

		ll n;
		cin >> n;
		int res = 0;
		for (int i = 0; i <= 500; i++) {
			if (n >= arr[i]) {
				res = i;
			} else break;
		}
		cout << res << '\n';
	}
};
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	TennisChampionship t;
	t.solve();

}
