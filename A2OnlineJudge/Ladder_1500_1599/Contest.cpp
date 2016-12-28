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
	ll a, b, c, d;
	cin >> a >> b >> c >> d;
	ll m = max((3 * a) / 10, a - ((a / 250) * c));
	ll v = max((3 * b) / 10, b - ((b / 250) * d));
	if (m == v) cout << "Tie";
	else if (m > v) cout << "Misha";
	else cout << "Vasya";
}
