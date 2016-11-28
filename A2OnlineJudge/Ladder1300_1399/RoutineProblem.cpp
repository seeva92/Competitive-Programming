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
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	int top, bot;
	if (a * d > b * c) {
		top = a * d - b * c;
		bot = a * d;
		int g = __gcd(top, bot);
		cout << top / g << "/" << bot / g;
	} else if (a * d < b * c) {
		top  = b * c - a * d;
		bot = b * c;
		int g = __gcd(top, bot);
		cout << top / g << "/" << bot / g;
	} else {
		cout << "0/1\n";
	}

}
