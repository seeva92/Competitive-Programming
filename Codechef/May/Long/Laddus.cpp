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
	ll t, n, r; string str;
	cin >> t;
	while (t--) {
		ll total = 0;
		cin >> n >> str;
		ll divi = (str == "INDIAN" ? 200 : 400);
		while (n--) {
			cin >> str;
			if (str == "CONTEST_WON") {
				cin >> r;
				total += 300 + (r > 20 ? 0 : 20 - r);
			} else if (str == "TOP_CONTRIBUTOR") {
				total += 300;
			} else if (str == "BUG_FOUND") {
				cin >> r;
				total += r;
			} else {
				total += 50;
			}
		}
		cout << (total / divi) << endl;;
	}
}