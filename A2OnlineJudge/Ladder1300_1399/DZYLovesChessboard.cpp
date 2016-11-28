#include <bits/stdc++.h>
typedef long long ll;
const int mod = 1e9 + 7;
const int MAX = 1e5 + 7;
using namespace std;
typedef vector<int> vi;
int n, m; string s;
vector<string> v;
int dx[] = { -1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
inline bool isvalid(int i, int j, int c) {
	for (int k = 0; k < 4; k++) {
		if (i + dx[k] >= 0 && i + dx[k] < n && j + dy[k] >= 0 && j + dy[k] < m) {
			if (v[i + dx[k]][j + dy[k]] == c) return false;
		}
	}
	return true;
}

bool compute(int i, int j, char c) {
	if (!isvalid(i, j, c)) return false;
	char temp = v[i][j];
	v[i][j] = c;
	for (int k = 0; k < 4; k++) {
		if (i + dx[k] >= 0 && i + dx[k] < n && j + dy[k] >= 0 && j + dy[k] < m) {
			if (v[i + dx[k]][j + dy[k]] == '.') {
				bool flag = compute(i + dx[k], j + dy[k], 'W') || compute(i + dx[k], j + dy[k], 'B');
				if (!flag) {
					v[i][j] = temp;
					return false;
				}
			}

		}
	}
	return true;
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> s; v.push_back(s);
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			if (v[i][j] == '.')
				compute(i, j, 'B') ||  compute(i, j, 'W');
		}

	for (auto i : v) cout << i << '\n';
}
