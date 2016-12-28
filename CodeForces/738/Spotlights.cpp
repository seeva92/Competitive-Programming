#include <bits/stdc++.h>
typedef long long ll;
const int mod = 1e9 + 7;
const int MAX = 1e5 + 7;
using namespace std;
typedef vector<int> vi;
int arr[1007][1007];
vector<int> row[1007];
vector<int> col[1007];

int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			if (arr[i][j]) {
				row[i].push_back(j);
				col[j].push_back(i);
			}
		}

	int cnt = 0;
	int dx[] = { -1, 1, 0, 0};
	int dy[] = {0, 0, -1, 1};
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			if (arr[i][j]) continue;
			auto left = upper_bound(row[i].begin(), row[i].end(), -1);
			if (left != row[i].end() && *left < j) {
				cnt++;
			}
			auto right = upper_bound(row[i].begin(), row[i].end(), j);
			if (right != row[i].end()) {
				cnt++;
			}
			auto up = upper_bound(col[j].begin(), col[j].end(), -1);

			if ((up != col[j].end()) && (*up < i)) {
				cnt++;
			}
			auto down = upper_bound(col[j].begin(), col[j].end(), i);
			if (down != col[j].end()) {
				cnt++;
			}
		}

	cout << cnt;
}
