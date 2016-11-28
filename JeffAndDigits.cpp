#include <bits/stdc++.h>
const int mod = 1e9 + 7;
using namespace std;
typedef vector<int> vi;
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	int arr[7] = {0};
	int n; cin >> n; int x;
	for (int i = 0; i < n; i++) {
		cin >> x; arr[x]++;
	}
	if (arr[5] / 9 > 0 && arr[0] > 0) {
		int cnt = arr[5] - arr[5] % 9;
		for (int i = 0; i < cnt; i++) cout << "5";
		for (int i = 0; i < arr[0]; i++) cout << "0";
	} else cout << "0";

}
