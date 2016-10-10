#include <bits/stdc++.h>
const int mod = 1e9 + 7;
using namespace std;
typedef long long ll;
int arr[100007];
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	ll n, b, k;
	while (t--) {
		cin >> n >> k >> b;

		if (b > k) { cout << "-1\n"; continue;}
		ll prev = 0;
		ll i;
		for (i = 1; i < b; i++) {
			n -= i;
			arr[prev] = i;
			++prev;
		}
		cout << i << " " << n << " " << k << '\n';
		if ((n > 0) && (arr[prev - 1] < n) && (prev <= n && n <= k)) {
			arr[prev] = n;
			++prev;
			for (int i = 0; i < prev; i++) cout << arr[i] << " ";
		} else {
			cout << "-1";
		}
		cout << '\n';
	}
}
