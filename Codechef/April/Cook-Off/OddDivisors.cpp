#include <bits/stdc++.h>
#define vi vector<int>
#define pi pair<int,int>
#define vii vector<pi>
#define ll long long
using namespace std;
ll divi[100007];
void compute() {
	divi[1] = 1; divi[2] = 1 + divi[1];
	for (ll i = 3; i <= 100000; i++) {
		ll size = sqrt(i);
		ll total = 0;
		for (ll j = 1; j <= size; j++) {
			if (i % j == 0) {
				if (j & 1 == 1) total += j;
				if (((i / j) != j) && ((i / j) & 1 == 1)) total += (i / j);
			}
		}
		divi[i] = total + divi[i - 1];
	}
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("/home/shiva/Learning/1.txt", "r", stdin);
	freopen("/home/shiva/Learning/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false); cin.tie(0);
	compute();
	ll t, l, r;
	cin >> t;
	while (t--) {
		cin >> l >> r;
		cout << divi[r] - divi[l - 1] << endl;
	}

}