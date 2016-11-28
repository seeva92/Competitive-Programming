#include <bits/stdc++.h>
typedef long long ll;
const int mod = 1e9 + 7;
const int MAX = 1e5 + 7;
using namespace std;
typedef vector<int> vi;
int n, arr[2 * MAX];
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i]; sort(arr, arr + n);
	cout << arr[n - 1] - arr[0] << " ";
	ll lt = 1, rt = 1;
	for (int i = 1; i < n && arr[i] == arr[i - 1]; i++, lt++);
	for (int i = n - 2; i >= 0 && (arr[i] == arr[i + 1]); i--, rt++);
	if (arr[0] == arr[n - 1]) {
		cout << (lt * (lt - 1)) / 2;
	} else cout << lt*rt;
}
