#include <bits/stdc++.h>
typedef long long ll;
const int mod = 1e9 + 7;
const int MAX = 1e5 + 7;
using namespace std;
typedef vector<int> vi;
int arr[507];
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	memset(arr, 0, sizeof arr);
	int n, k; cin >> n >> k;
	for (int i = 0; i < n; i++) cin >> arr[i];
	int cnt = 0;
	for (int i = 1; i < n; i++) {
		if (arr[i] + arr[i - 1] < k) {
			cnt += k - arr[i] - arr[i - 1];
			arr[i] += k - arr[i] - arr[i - 1];
		}
	}
	cout << cnt << '\n';
	for (int i = 0; i < n; i++) cout << arr[i] << " ";
}
