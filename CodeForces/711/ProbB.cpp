#include <bits/stdc++.h>
const int mod = 1e9 + 7;
using namespace std;
int n;
long long arr[510][510];
long long row[510], col[510], diag[2];
int zr = -1, zc = -1;
bool l, r;
set<long long> b, a;

bool compute() {
	l = r = false;
	memset(col, 0, sizeof col);
	memset(row, 0, sizeof row);
	memset(diag, 0, sizeof diag);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			row[i] += arr[i][j];
			col[i] += arr[j][i];
		}
	for (int i = 0, j = n - 1; i < n && j >= 0; i++, j--) {
		diag[1] += arr[i][j];
		if (i == zr && j == zc) { r = true;}
	}

	for (int i = 0, j = 0; i < n && j < n; i++, j++) {
		diag[0] += arr[i][j];
		if (i == zr && j == zc) { l = true;}
	}


	for (int i = 0; i < n; i++) {
		if (i == zr) a.insert(row[i]);
		else b.insert(row[i]);
	}
	for (int i = 0; i < n; i++) {
		if (i == zc) a.insert(col[i]);
		else b.insert(col[i]);
	}
	if (l && !r) b.insert(diag[1]), a.insert(diag[0]);
	else if (!l && r) b.insert(diag[0]), a.insert(diag[1]);
	else if (!l && !r) b.insert(diag[0]), b.insert(diag[1]);
	else a.insert(diag[0]), a.insert(diag[1]);

	if ((int(b.size()) == 1) && (int(b.size()) == int(a.size())) && (*(b.begin()) > *(a.begin()))) return true;

	return false;
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 0) {
				zr = i, zc = j;
			}
		}
	if (n == 1) {
		cout << 1; return 0;
	}


	if (compute()) {
		cout << *(b.begin()) - *(a.begin()) << '\n';
	}
	else cout << "-1\n";
}
