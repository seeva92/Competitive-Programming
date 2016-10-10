#include <bits/stdc++.h>
const int mod = 1e9 + 7;
using namespace std;
int t, n, x;
vector<int> v;
map<pair<int, int>, int> mp;
int compute(int i, int j) {
	if (i > j) return 1e8;
	if (v[i] * x >= v[j]) return 0;
	if (mp.count({i, j}) > 0) return mp[ {i, j}];
	int l = 1 + compute(i + 1, j);
	int r = 1 + compute(i, j - 1);
	return mp[ {i, j}] = min(l, r);
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	// ios::sync_with_stdio(false);
	// cin.tie(0);
	int a = 1, b = 0, c = *(&a);
	*((a + 1 == 1) ? &b : &a) = a ? ++b : ++c;
	printf("%d, %d, %d\n", a, b, c);

	int val;
	cin >> t;
	while (t--) {
		v.clear();
		mp.clear();
		cin >> n >> x;
		for (int i = 0; i < n; i++) {
			cin >> val;
			v.push_back(val);
		}
		sort(v.begin(), v.end());
		if (n <= 1010)
			cout << compute(0, n - 1) << '\n';
		else {
			int l = 0, r = 0, lr = 0;
			for (int i = n - 1; i >= 0; i--) {
				if (v[0]* x >= v[i]) break;
				r++;
			}
			for (int i = 0; i < n; i++) {
				if (v[i]* x >= v[n - 1]) break;
				l++;
			}

			for (int i = 0, j = n - 1; i <= j; i++, j--) {
				if (v[i]*x >= v[j]) break;
				lr += 2;
			}

			cout << min(lr, min(l, r)) << '\n';
		}


	}
}