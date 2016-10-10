#include <bits/stdc++.h>
const int mod = 1e9 + 7;
using namespace std;
int arr[26];
char c;
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	memset(arr, 0, sizeof arr);
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> c; arr[c - 'a']++;
	}
	string temp = "hackert";
	int res = 1e9;
	for (auto i : temp) {
		switch (i) {
		case 'e':
		case 'r':
		case 'h':
		case 'a': res = min(res, arr[i - 'a'] / 2); break;
		case 'c':
		case 'k':
		case 't': res = min(res, arr[i - 'a']); break;
		}
	}
	cout << res << '\n';
}
