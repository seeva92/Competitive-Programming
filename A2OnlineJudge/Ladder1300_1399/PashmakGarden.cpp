#include <bits/stdc++.h>
typedef long long ll;
const int mod = 1e9 + 7;
const int MAX = 1e5 + 7;
using namespace std;
typedef vector<int> vi;
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
	int x3, y3, x4, y4;

	if (x1 != x2 && y1 != y2) {
		x3 = x1; y3 = y2;
		x4 = x2; y4 = y1;
		if (abs(x1 - x2) == abs(y2 - y1)) cout << x3 << " " << y3 << " " << x4 << " " << y4;
		else cout << -1;
	} else if (x1 == x2) {
		cout << x1 + abs(y2 - y1) << " " << y1 << " " << x2 + abs(y2 - y1)  << " " << y2;
	} else if (y1 == y2) {
		cout << x1  << " " << y1 + abs(x2 - x1)  << " " << x2  << " " << y2 + abs(x2 - x1) ;
	} else cout << -1;
}
