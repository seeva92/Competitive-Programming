#include <bits/stdc++.h>
#define vi vector<int>
#define pi pair<int,int>
#define vii vector<pi>
#define ll long long
using namespace std;
inline int compute(int n) {
	int total = n, size = sqrt(n);
	for (int i = 2; i <= size; i++) {
		if (n % i == 0) {
			while (n % i == 0) {
				n /= i;
			}
			total -= total / i;
		}
	}
	if (n > 1) total -= total / n;
	return total;
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("/home/shiva/Learning/1.txt", "r", stdin);
	freopen("/home/shiva/Learning/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false); cin.tie(0);
	int t, n; cin >> t;
	while (t--) {
		cin >> n;
		cout << compute(n) << endl;
	}

}