#include <bits/stdc++.h>
const int mod = 1e9 + 7;
using namespace std;
typedef vector<int> vi;
pair<int, int> arr[10007];
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	int s, n, x, y; cin >> s >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i].first >> arr[i].second;
	}
	sort(arr, arr + n); bool flag = true;
	for (int i = 0; i < n; i++) {
		if (arr[i].first < s) s += arr[i].second;
		else { flag = false; break;}
	}
	if (flag) cout << "YES\n";
	else cout << "NO\n";
}
