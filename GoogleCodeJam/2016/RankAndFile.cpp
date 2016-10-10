#include <bits/stdc++.h>
#define vi vector<int>
#define pi pair<int,int>
#define vii vector<pi>
#define ll long long
using namespace std;
int t, n;
int mem[2600];
int main() {
#ifndef ONLINE_JUDGE
	freopen("/home/shiva/Learning/1.txt", "r", stdin);
	freopen("/home/shiva/Learning/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> t;
	for (int x = 1; x <= t; x++) {
		cin >> n;
		int nn = 2 * n - 1;
		memset(mem, 0, sizeof mem);
		int val;
		for (int i = 1; i <= nn; i++)
			for (int j = 0; j < n; j++) {
				cin >> val;
				mem[val]++;
			}
		cout << "Case #" << x << ": ";
		for (int i = 0; i <= 2500; i++) {
			if (mem[i] & 1) {
				cout << i << " ";
			}
		}
		cout << '\n';
	}
}


