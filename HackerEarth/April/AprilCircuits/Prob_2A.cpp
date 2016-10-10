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
	ll t, n, m;
	cin >> t;
	while (t--) {
		cin >> n >> m;
		int arr[n];
		for (int i = 0; i < n; i++) arr[i] = i + 1;
		unordered_map<int, unordered_map<int, int>> mp;
		ll a, b, temp, ta, tb;
		ll total = 0;
		do {
			ll curr = 1;
			for (int i = 0; i < n; i++) {
				for (int j = i + 1; j < n; j++) {
					a = abs(i - j), b = abs(arr[i] - arr[j]);
					ta = a, tb = b;
					if (mp[ta][tb]) curr *= mp[ta][tb];
					else {
						while (b) {
							temp = a % b;
							a = b;
							b = temp;
						}
						curr *= a;
						mp[ta][tb] = a;
						mp[tb][ta] = a;
					}

				}
			}
			total = (total + curr) % m;
		} while (next_permutation(arr, arr + n));
		cout << total << endl;
	}

}