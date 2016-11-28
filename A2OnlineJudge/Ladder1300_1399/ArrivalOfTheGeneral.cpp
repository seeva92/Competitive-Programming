#include <bits/stdc++.h>
const int mod = 1e9 + 7;
using namespace std;
typedef vector<int> vi;
int main() {
#ifndef ONLINE_JUDGE
	freopen("1.txt", "r", stdin);
	freopen("2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n; cin >> n;
	int *arr = new int[n];
	for (int i = 0; i < n; i++) cin >> arr[i];
	pair<int, int> mx, mn;
	mx.first = mx.second = mn.second = -1;
	mn.first = 200;
	for (int i = 0, j = n - 1; i < n && j >= 0; i++, j--) {
		if (arr[i] > mx.first) {
			mx.first = arr[i]; mx.second = i;
		}
		if (arr[j] < mn.first) {
			mn.first = arr[j]; mn.second = j;
		}
	}
	if (mx.second < mn.second)
		cout << mx.second + (n - mn.second - 1) << '\n';
	else cout << mx.second + (n - mn.second - 2) << '\n';
}
