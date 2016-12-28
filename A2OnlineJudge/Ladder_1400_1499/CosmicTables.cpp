#include <bits/stdc++.h>
typedef long long ll;
const int mod = 1e9 + 7;
const int MAX = 1e5 + 7;
using namespace std;
typedef vector<int> vi;
int arr[1007][1007], row[1007], col[1007];
class CosmicTables
{
	int n, m, k, r, c;
	char s;
public:
	void solve() {
		cin >> n >> m >> k;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++) cin >> arr[i][j];
		for (int i = 1; i <= n; i++) row[i] = i;
		for (int j = 1; j <= m; j++) col[j] = j;
		for (int i = 1; i <= k; i++) {
			cin >> s >> r >> c;
			if (s == 'c') swap(col[r], col[c]);
			else if (s == 'r') swap(row[r], row[c]);
			else cout << arr[row[r]][col[c]] << '\n';
		}
	}

};
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	CosmicTables c; c.solve();
}
