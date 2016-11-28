#include <bits/stdc++.h>
const int mod = 1e9 + 7;
using namespace std;
typedef vector<int> vi;
int n, m;
vector<string> v;
int low[507][507], up[507][507];
void process() {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			if (v[i][j] == 'x') { low[i][j] = -1; up[i][j] = -1;}
			else {
				if (j - 1 >= 0 && low[i][j - 1] != -1) low[i][j] = low[i][j - 1] + 1;
				if (i - 1 >= 0 && up[i - 1][j] != -1) up[i][j] = up[i - 1][j] + 1;
			}
		}
	int res = 0;
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++) {
			vi v;
			for (int k = 0; k < m; k++) {
				if (up[j][k] >= (j - i)) v.push_back(k);
			}
			int l = 0, r = 0;
			for (r = 0; r < int(v.size()); r++) {
				int ml = v[r] - min(low[i][v[r]], low[j][v[r]]);
				while (v[l] < ml) l++;
				if (v[r] > v[l]) res = max(res, (2 * (j - i)) + (2 * (v[r] - v[l])));
			}
		}
	if (res == 0 ) cout << "impossible\n";
	else cout << res << '\n';
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	string s;
	memset(low, 0, sizeof low); memset(up, 0, sizeof up);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> s; v.push_back(s);
	}
	process();
}
