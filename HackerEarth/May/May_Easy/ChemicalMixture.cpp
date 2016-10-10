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
	ll t, m, n1, n2;
	vector<ll> v1, v2;
	cin >> t;
	while (t--) {
		cin >> m >> n1 >> n2;
		v1.assign(n1, 0); v2.assign(n2, 0);
		for (int i = 0; i < n1; i++) cin >> v1[i];
		for (int i = 0; i < n2; i++) cin >> v2[i];
		sort(v1.begin(), v1.end(), greater<ll>());

		ll best = -1;
		bool flag = false;
		deque<ll> res;
		for (int i = 0; i < (1 << n2); i++) {
			ll total = 0, curr = 0;
			for (int j = 0; j < n2; j++) {
				if (i & (1 << j)) {
					total += v2[j];
				}
			}
			curr = m - total;
			deque<ll> cres;
			for (int k = 0; k < n1; k++) {
				if (total + v1[k] <= m) {
					total += v1[k];
					cres.push_front(v1[k]);
				}
			}

			if (total == m) {
				if (curr > best) {
					best = curr;
					res = cres;
				}
				flag = true;
			}
		}

		if (flag) {
			cout << "YES" << endl;
			for (auto it : res) cout << it << " ";
			cout << endl;
		} else cout << "NO" << endl;

	}

}