#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <cstring>
#include <unordered_map>
using namespace std;
int main() {
#ifndef ONLINE_JUDGE
	freopen("/home/shiva/Learning/1.txt", "r", stdin);
	freopen("/home/shiva/Learning/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false); cin.tie(0);
	unordered_map<int, bool> mp;
	int n, m, x;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {cin >> x; mp[x] = 1;};
	vector<int> res;
	for (int i = 1; m > 0; i++) {
		if (mp[i] == 0) {
			if (m - i >= 0) {
				res.push_back(i); m -= i;
			}
			else {
				break;
			}
		}
	}
	cout << res.size() << endl;
	for (auto it : res) cout << it << " ";
}