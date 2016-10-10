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
	ll a, b, c; cin >> a >> b >> c;
	ll temp = b - a;
	if (a == b) cout << "YES" << endl;
	else if (temp < 0 && c < 0 && temp % c == 0) cout << "YES" << endl;
	else if (temp > 0 && c > 0 && temp % c == 0) cout << "YES" << endl;
	else cout << "NO" << endl;

}