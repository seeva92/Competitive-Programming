#include <bits/stdc++.h>
const int mod = 1e9 + 7;
using namespace std;
unsigned long long gcd(unsigned long long a, unsigned long long b) { return b == 0 ? a : gcd(b, a % b);}
unsigned long long lcm(unsigned long long a, unsigned long long b) { return (a * b) / gcd(a, b);}
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n; cin >> n;
	long double curr = 2;
	long double x, y;
	for (long double i = 1; i <= n; i++) {
		x = lcm(i + 1, i);
		y = x * x;
		cout << (unsigned long long)((y - curr) / i) << '\n';
		curr = x;
	}
}
