#include <bits/stdc++.h>
const int mod = 1e9 + 7;
using namespace std;
typedef vector<int> vi;
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	long double n, x, y;
	cin >> n >> x >> y;
	long double temp = ceil((n * y) / 100);
	// cout << ceil(temp) << "\n";
	if ((long long)temp >= (long long)x) cout << (long long)(temp - x);
	else cout << 0;

}
