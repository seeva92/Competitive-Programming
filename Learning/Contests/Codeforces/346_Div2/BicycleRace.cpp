#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;
int main() {
#ifndef ONLINE_JUDGE
	freopen("/home/shiva/Learning/1.txt", "r", stdin);
	freopen("/home/shiva/Learning/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false); cin.tie(0);
	int n; cin >> n;
	pair<int, int> arr[n + 1];
	for (int i = 0; i <= n; i++) cin >> arr[i].first >> arr[i].second;
	int dir[n + 1];
	for (int i = 0; i < n; i++) {
		if (arr[i].first == arr[i + 1].first) {
			if (arr[i].second < arr[i + 1].second) dir[i] = 0;
			else dir[i] = 2;
		} else if (arr[i].first < arr[i + 1].first) dir[i] = 3;
		else dir[i] = 1;
	} dir[n] = dir[0];
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if ((dir[i] + 1) % 4 == dir[i + 1]) ans++;
	}
	cout << ans << endl;
}