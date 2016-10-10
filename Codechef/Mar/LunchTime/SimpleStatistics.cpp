#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <cstring>
#include <climits>
#include <iomanip>
using namespace std;
int main() {
// #ifndef ONLINE_JUDGE
// 	freopen("/home/shiva/Learning/1.txt", "r", stdin);
// 	freopen("/home/shiva/Learning/2.txt", "w", stdout);
// #endif
	ios::sync_with_stdio(false); cin.tie(0);
	cout << fixed << setprecision(6);

	int t, n, k; cin >> t;
	while (t--) {
		cin >> n >> k;
		int arr[n + 1]; arr[0] = INT_MIN;
		for (int i = 1; i <= n; i++) cin >> arr[i]; sort(arr, arr + (n + 1));
		double total = 0.0f;
		for (int i = k + 1; i <= (n - k); i++) total += arr[i];
		if ((n - 2 * k) > 0)
			cout << (total / (n - 2 * k)) << endl;
		else
			cout << total << endl;
	}

}