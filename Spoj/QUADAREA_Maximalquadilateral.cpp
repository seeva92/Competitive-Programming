#include <bits/stdc++.h>
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
	int t; cin >> t;
	while (t--) {
		double a, b, c, d;
		cin >> a >> b >> c >> d;
		double s = (a + b + c + d) / (double)(2.0);
		cout << fixed << setprecision(2) << sqrt(((s - a) * (s - b) * (s - c) * (s - d))) << endl;
	}

}