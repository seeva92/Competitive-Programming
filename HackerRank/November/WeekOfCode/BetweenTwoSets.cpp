#include <bits/stdc++.h>
const int mod = 1e9 + 7;
using namespace std;
typedef vector<int> vi;
int A[107], B[107], n, m;
bool check(int val) {
	for (int i = 0; i < n; i++)
		if (val % A[i] != 0) return false;
	for (int i = 0; i < m; i++)
		if (B[i] % val != 0) return false;
	return true;
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("1.txt", "r", stdin);
	freopen("2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; ++i) cin >> A[i]; sort(A, A + n);
	for (int i = 0; i < m; ++i) cin >> B[i]; sort(B, B + n);
	int l = A[n - 1], r = B[0];
	int c = 0;
	for (int i = 1; i <= 100; ++i) {
		if (check(i)) c++;
	}
	cout << c << '\n';
}
