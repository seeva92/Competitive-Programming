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
	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		if (n == 10 || n == 12) cout << "1\n";
		else if (n < 10 || n < 12) cout << "-1\n";
		else {
			int cnt = 1; int tw = 12, tn = 10;
			int res = n % 12 == 0 ? n / 12 : 1e9;
			int temp = (n % 10 == 0 ? n / 10 : 1e9);
			res = min(res, temp);
			for (int i = 1; i * tw <= n; i++)
				if ((n - (i * tw)) % tn == 0)
					res = min(res, i + ((n - (i * tw)) / tn));
			for (int i = 1; i * tn <= n; i++)
				if ((n - (i * tn)) % tw == 0)
					res = min(res, i + ((n - (i * tn)) / tw));
			if (res == 1e9) cout << "-1\n";
			else cout << res << '\n';
		}
	}

}
