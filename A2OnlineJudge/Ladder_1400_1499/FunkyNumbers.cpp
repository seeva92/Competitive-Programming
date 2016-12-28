#include <bits/stdc++.h>
typedef long long ll;
const int mod = 1e9 + 7;
const int MAX = 1e6 + 7;
using namespace std;
typedef vector<int> vi;
ll arr[MAX], idx = 0;
class FunkyNumbers
{
	ll n;
public:
	void init(ll curr) {
		for (ll i = 1; (i * (i + 1)) / 2 <= n; i++) {
			arr[idx++] = (i * (i + 1)) / 2;
			// cout << arr[idx - 1] << '\n';
		}
	}
	bool compute(ll curr) {
		int l = 0, r = idx - 1;
		while (l < r) {
			if ((arr[l] + arr[r]) == n) return true;
			if ((arr[l] + arr[r]) < n) {
				l++;
			} else r--;
		}
		for (int i = 0; i < idx; i++)
			if ((arr[i] + arr[i]) == n) return true;
		return false;
	}
	void solve() {
		cin >> n;
		init(n);
		if (compute(n)) cout << "YES";
		else cout << "NO";
	}

};
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);

	FunkyNumbers f; f.solve();
}
