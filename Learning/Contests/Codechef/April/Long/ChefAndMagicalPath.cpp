#include <bits/stdc++.h>
#define mp make_pair
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
	ll t, n, m;
	cin >> t;
	while (t--) {
		cin >> n >> m;
		if ((n == 1 and m == 2) or (m == 1 and n == 2)) cout << "Yes" << endl;
		else if (n == 1 or m == 1) cout << "No" << endl;
		else if (n % 2 == 0 or m % 2 == 0) cout << "Yes" << endl;
		else cout << "No" << endl;
	}

}