#include <bits/stdc++.h>
#define mp make_pair
#define vi vector<int>
#define pi pair<int,int>
#define vii vector<pi>
const long long mod = 1000000000000000007;
using namespace std;
int main() {
#ifndef ONLINE_JUDGE
	freopen("/home/shiva/Learning/1.txt", "r", stdin);
	freopen("/home/shiva/Learning/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false); cin.tie(0);
	int t; long long b, e;
	cin >> t;
	while (t--) {
		cin >> b >> e;
		long long result = 1;
		while (e) {
			if (e & 1) result = (result * b) % mod;
			b = (b * b) % mod;
			e >>= 1;
		}
		cout << result << endl;
	}

}