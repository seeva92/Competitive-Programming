#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <cstring>
#include <climits>
using namespace std;
int main() {
// #ifndef ONLINE_JUDGE
// 	freopen("/home/shiva/Learning/1.txt", "r", stdin);
// 	freopen("/home/shiva/Learning/2.txt", "w", stdout);
// #endif
	ios::sync_with_stdio(false); cin.tie(0);
	int n; cin >> n;
	int arr[n + 1]; arr[0] = INT_MIN;
	int res[n + 1];
	for (int i = 1; i <= n; i++) cin >> arr[i]; sort(arr, arr + (n + 1));
	// for (int i = 1; i <= n; i++) cout << arr[i] << " ";
	for (int i = 1, j = n, k = 1; i <= j && k <= n; i++, j--) {
		res[k++] = arr[i];
		if (k <= n) res[k++] = arr[j];
	}
	bool flag = true;
	for (int i = 2; i <= n; i++) {
		if (i % 2 == 0) {
			if (res[i] < res[i - 1]) { flag = false; break;}
		} else {
			if (res[i] > res[i - 1]) { flag = false; break;}
		}
	}
	if (flag) {
		for (int i = 1; i <= n; i++) cout << res[i] << " ";
		cout << endl;
	} else {
		cout << "Impossible" << endl;
	}

}