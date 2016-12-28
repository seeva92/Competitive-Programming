#include <bits/stdc++.h>
typedef long long ll;
const int mod = 1e9 + 7;
const int MAX = 1e5 + 7;
using namespace std;
typedef vector<int> vi;
int cnt[1007];
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	memset(cnt, 0, sizeof cnt);
	int n; cin >> n;
	int x;
	for (int i = 0; i < n; i++) {
		cin >> x;
		cnt[x]++;
	}
	for (int i = 1; i <= 1000; i++) {
		if (cnt[i] > ((n + 1) / 2)) {
			cout << "NO"; return 0;
		}
	}
	cout << "YES";
}
