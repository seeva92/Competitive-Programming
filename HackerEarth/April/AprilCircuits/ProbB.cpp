#include <bits/stdc++.h>
#define vi vector<int>
#define pi pair<int,int>
#define vii vector<pi>
#define ll long long
using namespace std;
vector<ll> arr;
vector<ll> cpy;
int main() {
#ifndef ONLINE_JUDGE
	freopen("/home/shiva/Learning/1.txt", "r", stdin);
	freopen("/home/shiva/Learning/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false); cin.tie(0);
	int n, q;
	ll a, b;
	cin >> n >> q;
	arr.assign(n , 0);
	while (q--) {
		ll total = 0;
		cin >> a >> b;
		arr[a - 1] += b;
		cpy.assign(arr.begin(), arr.end());
		sort(cpy.begin(), cpy.end(), greater<ll>());
		for (ll i = 0, j = 1; i < n; i++) {
			if (!(i > 0 && cpy[i] == cpy[i - 1]))
				j = i + 1;
			total += j * cpy[i];

		}
		cout << total << endl;
	}


}