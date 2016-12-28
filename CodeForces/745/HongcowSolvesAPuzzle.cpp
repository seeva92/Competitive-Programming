#include <bits/stdc++.h>
typedef long long ll;
const int mod = 1e9 + 7;
const int MAX = 1e5 + 7;
using namespace std;
typedef vector<int> vi;

class HongcowSolvesAPuzzle
{
	int n, m;
	char c;
	int cnt = 0;
public:
	void solve() {
		cin >> n >> m;
		int minr = n + 1, maxr = -1, minc = m + 1, maxc = -1;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++) {
				cin >> c;
				if (c == 'X') {
					minr = min(minr, i);
					maxr = max(maxr, i);
					minc = min(minc, j);
					maxc = max(maxc, j);
					cnt++;
				}
			}
		int temp = (maxr - minr + 1) * (maxc - minc + 1);
		// cout << temp;
		if (temp == cnt) cout << "YES";
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
	HongcowSolvesAPuzzle h; h.solve();
}
