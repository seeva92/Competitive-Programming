#include <bits/stdc++.h>
typedef long long ll;
const int mod = 1e9 + 7;
const int MAX = 1e5 + 7;
using namespace std;
typedef vector<int> vi;
class ChloeAndSequence
{
public:
	void solve() {
		ll n, k;
		cin >> n >> k;
		ll len = (1LL << (n - 1));
		ll mid = len / 2;
		ll val = n;
		while (len != k) {

			if (len < k) {
				len += mid;
			} else if (len > k) {
				len -= mid;
			}
			mid /= 2;
			val--;
		}
		cout << val;
	}

};
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	ChloeAndSequence c; c.solve();
}
