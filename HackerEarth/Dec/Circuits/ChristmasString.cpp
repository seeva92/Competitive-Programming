#include <bits/stdc++.h>
typedef long long ll;
const int mod = 1e9 + 7;
const int MAX = 1e5 + 7;
using namespace std;
typedef vector<int> vi;
string s, arr[3007];
int cnt[3007];
int n;
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> s;
	cin >> n;

	int curr = 0;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		int k = -1, j;
		for (j = 0; j < n; j++) {
			if (s[j] == '*') continue;
			if (s[j] != arr[i][j]) {
				if (k == -1) k = j;
				else break;
			}
		}
		if (k == -1) curr++;
		else {
			if (j == n) {
				cnt[k]++;
			}
		}
	}
	int res = 0;
	for (int i = 0; i < n; i++) {
		// cout << cnt[i] << " ";
		res = max(res, cnt[i]);
	}
	// cout << '\n';
	// cout << res << " " << curr << '\n';
	cout << res + curr;
}
