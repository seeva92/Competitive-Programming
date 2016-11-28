#include <bits/stdc++.h>
typedef long long ll;
const int mod = 1e9 + 7;
const int MAX = 1e5 + 7;
using namespace std;
ll arr[MAX] = {0}, srt[MAX] = {0};
typedef vector<int> vi;
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n; cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i]; srt[i] = arr[i];
		arr[i] += arr[i - 1];
	}
	sort(srt + 1, srt + n + 1);
	for (int i = 1; i <= n; i++) srt[i] += srt[i - 1];
	int m; cin >> m; int l, r, c;
	for (int i = 0; i < m; i++) {
		cin >> c >> l >> r;
		if (c == 1) cout << arr[r] - arr[l - 1] << '\n';
		else cout << srt[r] - srt[l - 1] << '\n';
	}
}
