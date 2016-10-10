#include <bits/stdc++.h>
#define vi vector<int>
#define pi pair<int,int>
#define vii vector<pi>
#define ll long long
using namespace std;
ll arr[100007];
int main() {
#ifndef ONLINE_JUDGE
	freopen("/home/shiva/Learning/1.txt", "r", stdin);
	freopen("/home/shiva/Learning/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false); cin.tie(0);
	ll n, k;
	cin >> n >> k;
	for (ll i = 1; i <= n; i++) cin >> arr[i];
	if (k == 1) cout << arr[k] << endl;
	else {
		ll prev = 1;
		ll i;
		for (i = 2; i <= n; i++) {
			if (prev + i < k) {
				prev += i;
			}
			else break;
		}
		if (k - prev > 0)
			cout << arr[k - prev] << endl;
		else
			cout << arr[i] << endl;
	}


}