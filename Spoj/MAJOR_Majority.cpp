#include <bits/stdc++.h>
#define vi vector<int>
#define pi pair<int,int>
#define vii vector<pi>
#define ll long long
using namespace std;
int main() {
#ifndef ONLINE_JUDGE
	freopen("/home/shiva/Learning/1.txt", "r", stdin);
	freopen("/home/shiva/Learning/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t; int x;
	while (t--) {
		int n; cin >> n;
		int pos[2005] = {0};
		for (int i = 0; i < n; i++) {
			cin >> x;
			pos[x + 1000]++;
		}
		int val = 0, vali = -1;
		for (int i = 0; i < 2005; i++)
			if (pos[i] >= val) {
				val = pos[i];
				vali = i;
			}
		if (val > n / 2) {
			cout << "YES " << vali - 1000 << endl;
		} else cout << "NO\n";
	}
}