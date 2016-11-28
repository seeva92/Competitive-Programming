#include <bits/stdc++.h>
typedef long long ll;
const int mod = 1e9 + 7;
const int MAX = 1e5 + 7;
using namespace std;
typedef vector<int> vi;

ll compute(int r, int b, int g) {
	ll tot = 0;
	if (r >= 3) tot = max(tot, r / 3 + compute(r % 3, b, g));
	if (b >= 3) tot = max(tot, b / 3 + compute(r, b % 3, g));
	if (g >= 3) tot = max(tot, g / 3 + compute(r, b, g % 3));
	if (r > 0 && b > 0 && g > 0) {
		int temp = min(r, min(b, g));
		tot = max(tot, temp + compute(r - temp, b - temp, g - temp));
	}
	return tot;
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	int r, b, g;
	cin >> r >> b >> g;
	cout << compute(r, b, g);
}
