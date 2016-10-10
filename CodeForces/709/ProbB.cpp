#include <bits/stdc++.h>
const int mod = 1e9 + 7;
using namespace std;
#define MAX 100007
int arr[MAX], L[MAX], R[MAX];
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, a;
	memset(L, 0, sizeof L); memset(R, 0, sizeof R);
	cin >> n >> a;
	for (int i = 0; i < n; i++) cin >> arr[i];
	if (n == 1) { cout << 0; return 0;}
	sort(arr, arr + n);
	long long ans  = 1e28;
	ans = min(ans, 1LL * abs(arr[0] - a) + arr[n - 2] - arr[0]);
	ans = min(ans, 1LL * abs(arr[n - 1] - a) + arr[n - 1] - arr[1]);
	ans = min(ans, 1LL * abs(arr[1] - a) + arr[n - 1] - arr[1]);
	ans = min(ans, 1LL * abs(arr[n - 2] - a) + arr[n - 2] - arr[0]);
	cout << ans;


}
