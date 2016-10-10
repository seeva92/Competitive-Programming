#include <bits/stdc++.h>
const int mod = 1e9 + 7;
using namespace std;
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	double s, v;
	double PI = acos(-1);
	cin >> t;
	while (t--) {
		cin >> s >> v;

		double D = s / (1.0 - cos(120.0 * (PI / 180.0)));

		cout << fixed << setprecision(9) << (D / v) << '\n';
	}
}
