#include <bits/stdc++.h>
const int mod = 1e9 + 7;
using namespace std;
typedef vector<int> vi;
int main() {
#ifndef ONLINE_JUDGE
	freopen("1.txt", "r", stdin);
	freopen("2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	int arr[6][6];
	int ii, jj;
	for (int i = 1; i <= 5; i++)
		for (int j = 1; j <= 5; j++) {
			cin >> arr[i][j];
			if (arr[i][j]) {
				ii = i, jj = j;
			}
		}
	cout << abs(3 - ii) + abs(3 - jj) << '\n';
}
