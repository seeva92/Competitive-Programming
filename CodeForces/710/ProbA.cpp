#include <bits/stdc++.h>
const int mod = 1e9 + 7;
using namespace std;
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	string s; cin >> s;
	int col = s[0] - 'a', row = 8 - (s[1] - '0');
	int cnt = 0;
	int arr[] = { -1, 1, 0};
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++) {
			if ((0 <= arr[i] + row ) && (arr[i] + row <= 7) && (0 <= arr[j] + col) && (arr[j] + col <= 7)) cnt++;
		}
	cout << cnt - 1;
}
