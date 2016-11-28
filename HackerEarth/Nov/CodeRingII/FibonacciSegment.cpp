#include <bits/stdc++.h>
typedef long long ll;
const int mod = 1e9 + 7;
const int MAX = 1e5 + 7;
using namespace std;
typedef vector<int> vi;
int arr[MAX]; int n;
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	int s = 0, e = 0;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	if (n == 1 || n == 2) { cout << n; return 0;}
	int res = 2; bool flag = false;
	for (int i = 2; i < n; i++) {
		if (arr[i] == arr[i - 1] + arr[i - 2]) {
			if (flag) {s = i - 2; flag = !flag;}
			e = i;
			res = max(res, e - s + 1);
		} else flag = true;
	}
	cout << res << '\n';
}
