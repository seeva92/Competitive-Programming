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
int t, a, b;
int gcd(int x, int y) {
	while (y) {
		int temp = x;
		x = y;
		y = temp % y;
	}
	return x;
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> t;
	while (t--) {
		cin >> a >> b;
		for (int x = gcd(a, b); x != 1; x = gcd(a, b)) {
			a /= x;
			b /= x;
		}
		cout << b << " " << a << endl;
	}

}
