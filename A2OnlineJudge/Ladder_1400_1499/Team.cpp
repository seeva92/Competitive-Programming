#include <bits/stdc++.h>
typedef long long ll;
const int mod = 1e9 + 7;
const int MAX = 1e5 + 7;
using namespace std;
typedef vector<int> vi;
class Team
{
	int n, m;
public:
	void solve() {
		cin >> n >> m;

		if ((n - 1 == m) || n == m) {
			int z = n , o = m;
			while (z || o) {
				if (z != 0) { cout << '0'; z--;}
				if (o != 0) { cout <<  '1'; o--;}
			}
		} else if ((n - 1) <= m && m <= (2 * (n + 1))) {
			vector<string> zeroes;
			string s = "0";
			for (int i = 0; i < n; i++) {
				zeroes.push_back(s);
			}

			int i = 0; int j = 0;
			for (i = 0; i < m; i++) {
				if (zeroes[j].size() == 3) break;
				zeroes[j].push_back('1');
				j = (j + 1) % n;
			}
			for (; i < m; i++) cout << '1';
			for (auto k : zeroes) cout << k;
		} else cout << -1;
	}

};
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	Team t; t.solve();
}
