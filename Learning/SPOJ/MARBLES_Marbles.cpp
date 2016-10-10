#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;
int main() {
// #ifndef ONLINE_JUDGE
// 	freopen("/home/shiva/Learning/1.txt", "r", stdin);
// 	freopen("/home/shiva/Learning/2.txt", "w", stdout);
// #endif
	ios::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int n, k; cin >> n >> k; n--, k--;
		long long res = 1;
		k = min(k, n - k);
		for (int i = 0; i < k; i++) res = res * (n - i) / (i + 1);
		cout << res << endl;
	}

}