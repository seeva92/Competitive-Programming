#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;
int arr[100010];
int cnt[100010];
int main() {
// #ifndef ONLINE_JUDGE
// 	freopen("/home/shiva/Learning/1.txt", "r", stdin);
// 	freopen("/home/shiva/Learning/2.txt", "w", stdout);
// #endif
	ios::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while (t--) {
		memset(arr, 0, sizeof arr); memset(cnt, 0, sizeof cnt);
		int n; cin >> n;
		for (int i = 0; i < n; i++) cin >> arr[i];
		cnt[n - 1] = 1;
		for (int i = n - 2; i >= 0; i--)
			if (arr[i + 1] > 0 && arr[i] < 0) cnt[i] = cnt[i + 1] + 1;
			else if (arr[i + 1] < 0 && arr[i] > 0) cnt[i] = cnt[i + 1] + 1;
			else cnt[i] = 1;
		for (int i = 0; i < n; i++)
			cout << cnt[i] << " ";
		cout << '\n';
	}

}