#include <bits/stdc++.h>
typedef long long ll;
const int mod = 1e9 + 7;
const int MAX = 7e5 + 7;
const int MMAX = 1e7 + 1e3;
using namespace std;
typedef vector<int> vi;
bitset <MMAX> bs;
int arr[MAX], pIdx = 0;
int t, a, b;
void sieve() {
	bs.set(); bs[0] = bs[1] = 0;
	int len = sqrt(MMAX);
	int i;
	for (i = 2; i <= len; i++)
		if (bs[i]) {
			for (int j = i * i; j < MMAX; j += i) bs[j] = 0;
			arr[pIdx++] = i;

		}
	for (; i < MMAX; i++) if (bs[i]) arr[pIdx++] = i;
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	sieve();
	cin >> t;
	while (t--) {
		cin >> a >> b;
		// assert(2 <= a && a <= 1e7);
		// assert(2 <= b && b <= 1e7);
		bool flag = true;
		int j = arr[upper_bound(arr, arr + pIdx, b) - arr];
		for (int i = b + 1; i < j && flag; i++ ) {
			int len = sqrt(i);
			for (int k = 2; k <= len; k++) {
				if (i % k == 0) {
					if (a <= k && k <= b) { flag = false; break;}
					if (a <= (i / k) && (i / k) <= b) { flag = false; break;}
				}
			}
			if (flag) {
				cout << i << '\n'; flag = false;
			} else flag = true;
		}
		if (flag) cout << j << '\n';
	}
}
