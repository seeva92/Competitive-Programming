#include <bits/stdc++.h>
typedef long long ll;
const int mod = 1e9 + 7;
const int MAX = 1e5 + 7;
using namespace std;
typedef vector<int> vi;
int arr[107];
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	int tot = 0;
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
		tot += arr[i];
	}
	sort(arr, arr + n, greater<int>());
	int cnt = 0;
	int curr = 0;
	for (int i = 0; i < n; i++) {
		curr += arr[i];
		if (curr > (tot - curr)) {
			cnt++;
			break;
		}
		else cnt++;
	}
	cout << cnt;
}
