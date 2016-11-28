#include <bits/stdc++.h>
const int mod = 1e9 + 7;
using namespace std;
typedef vector<int> vi;
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T, L, X; cin >> T;
	while (T--) {
		cin >> L;
		int * low = new int[L];
		int * hi = new int[L];
		for (int i = 1; i < L; i++) cin >> low[i];
		for (int i = 1; i < L; i++) cin >> hi[i];
		long long res = 1, curr = 1;
		for (int i = 1; i < L; i++) {
			res = max(res, curr + max(low[i], hi[i]));
			curr++;
			res = max(res, curr);
		}
		res = max(res, curr);
		cout << res << '\n';

		delete [] low;
		delete [] hi;
	}
}
