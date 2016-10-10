#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <iostream>
#define vi vector<int>
#define all(v) v.begin(), v.end()
#define pii pair<int, int>
#define mp make_pair
#define ll long long
const int mod = 1e9 + 7;
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t, n, x;
	cin >> t;
	while (t--) {
		cin >> n;
		int total = 0;
		bool flag = true, full = false;
		for (int i = 0; i < n; i++) {
			cin >> x;
			if (x <= 2) flag = false;
			if (x == 5) full = true;
			if (flag) {
				total += x;
			}
		}
		if (flag && full) {
			if ((total / n) >= 4)
				cout << "Yes\n";
			else
				cout << "No\n";
		} else
			cout << "No\n";
	}
}
