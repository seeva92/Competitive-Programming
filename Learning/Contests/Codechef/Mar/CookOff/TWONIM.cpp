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
		int n; cin >> n; int x; int res = 0;
		for (int i = 0; i < n; i++) {
			cin >> x; res ^= x;
		}
		if (res == 0 || n % 2 == 0) cout << "First" << endl;
		else cout << "Second" << endl;
	}
}