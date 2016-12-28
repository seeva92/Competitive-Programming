#include <bits/stdc++.h>
typedef long long ll;
const int mod = 1e9 + 7;
const int MAX = 1e6 + 7;
using namespace std;
typedef vector<int> vi;
int arr[507][507];
int primes[MAX];
bitset<MAX> bs;
class PrimeMatrix
{
	int n, m;
	int pIdx = 0;
public:
	void sieve() {
		bs.set(); bs[0] = bs[1] = 0;
		int len = sqrt(MAX);
		for (int i = 2; i <= len; i++ ) {
			if (bs[i]) {
				for (int j = i * i; j < MAX; j += i) bs[j] = 0;
			}
		}
		for (int i = 0; i < MAX; i++) if (bs[i]) primes[pIdx++] = i;
	}
	void solve() {
		cin >> n >> m;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++) cin >> arr[i][j];

		sieve();
		ll res = 1e18;
		for (int i = 0; i < n; i++) {
			ll curr = 0;
			for (int j = 0; j < m; j++) {
				curr += (primes[lower_bound(primes, primes + pIdx, arr[i][j]) - primes] - arr[i][j]);
			}
			res = min(res, curr);
		}

		for (int i = 0; i < m; i++) {
			ll curr = 0;
			for (int j = 0; j < n; j++) {
				curr += (primes[lower_bound(primes, primes + pIdx, arr[j][i]) - primes] - arr[j][i]);
			}
			res = min(res, curr);
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
	PrimeMatrix p; p.solve();
}
