#include <bits/stdc++.h>
typedef long long ll;
const int mod = 1e9 + 7;
const int MAX = 1e5 + 7;
using namespace std;
typedef vector<int> vi;
int arr[17][17]; int n, m;
vector<string> v; string s;
int dx[] = { -1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};
int ii, jj;
void f() {
	int cnt = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			if (v[i][j] == 'W') {
				for (int k = 0; k < 4; k++) {
					ii = i + dx[k]; jj = j + dy[k];
					if (ii >= 0 && ii < n && jj >= 0 && jj < m && v[ii][jj] == 'P') arr[ii][jj]++;
				}
			}
		}
	// for (int i = 0; i < n; i++, cout << '\n')
	// for (int j = 0; j < m; j++) cout << arr[i][j] << " ";
	int result = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			if (v[i][j] == 'W') {
				int idx = -1, jdx = -1, res = 1e5;
				int ii, jj;
				for (int k = 0; k < 4; k++) {
					ii = i + dx[k]; jj = j + dy[k];
					if (ii >= 0 && ii < n && jj >= 0 && jj < m && v[ii][jj] == 'P') {
						if (res > arr[ii][jj]) { res = arr[ii][jj]; idx = ii, jdx = jj;}
					}
				}
				if (res != 1e5) {
					result++;
					for (int k = 0; k < 4; k++) {
						ii = i + dx[k]; jj = j + dy[k];
						if (ii >= 0 && ii < n && jj >= 0 && jj < m && v[ii][jj] == 'P') arr[ii][jj]--;
					}
					v[idx][jdx] = '.';
					// cout << idx << " " << jdx << '\n';
					// for (int i = 0; i < n; i++, cout << '\n')
					// for (int j = 0; j < m; j++) cout << arr[i][j] << " ";
				}
			}
		}
	cout << result;
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	memset(arr, 0, sizeof arr);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> s; v.push_back(s);
	}
	f();
}
