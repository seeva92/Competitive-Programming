#include <bits/stdc++.h>
const int mod = 1e9 + 7;
using namespace std;
typedef vector<int> vi;
int arr[3007];
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n; cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i]; sort(arr, arr + n);
	int curr = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] - curr != 1) break;
		else curr = arr[curr];
	}
	cout << curr + 1;
}
