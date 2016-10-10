#include <bits/stdc++.h>
#define vi vector<int>
#define pi pair<int,int>
#define vii vector<pi>
#define ll unsigned long long
using namespace std;
ll H[100007], R[100007];
pair<ll, ll> G[100007];
int main() {
#ifndef ONLINE_JUDGE
	freopen("/home/shiva/Learning/1.txt", "r", stdin);
	freopen("/home/shiva/Learning/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false); cin.tie(0);
	ll N, W, L; cin >> N >> W >> L;
	ll temp;
	for (ll i = 0; i < N; i++) {
		cin >> H[i] >> R[i];
		G[i].second = i; temp = L - H[i];
		G[i].first = temp % R[i] == 0 ? (temp / R[i]) : (temp / R[i]) + 1;
	}
	sort(G, G + N);
	ll i = 0, mic = 0, ht = 0, res = 0;
	bool flag = false;
	//Binary Search less months to next high months
	while (i < N) {
		mic += R[G[i].second];
		ht += (H[G[i].second] + (R[G[i].second] * G[i].first));
		ll j;
		for (j = i + 1; (j < N) && (G[j].first == G[j - 1].first); j++) {
			mic += R[G[j].second];
			ht += (H[G[j].second] + (R[G[j].second] * G[j].first));
		}
		if (ht >= W) {
			res = G[i].first; break;
		}
		ll low = 1;
		ll high = j < N ? (G[j].first - G[i].first - 1) : (1e18);
		while (high - low > 1) {
			ll mid = low + (high - low) / 2;
			// if(mid >=((W-ht)/mic)){
			if ((ht + (mid * mic)) >= W) {
				flag = true;
				res = G[i].first + mid;
				high = mid - 1;
			} else
				low = mid + 1;
		}
		if (flag) break;
		ht += (mic * (high + 1));
		i = j;
	}
	cout << res << endl;
}