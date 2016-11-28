#include <bits/stdc++.h>
typedef long long ll;
const int mod = 1e9 + 7;
const int MAX = 1e5 + 7;
using namespace std;
typedef vector<int> vi;
ll n, m, k, x, s, ss[2 * MAX], sc[2 * MAX];
pair<ll, ll> fp[2 * MAX];
void compute() {
	sort(fp, fp + m);
	ll res = n * x;
	for (int i = 0; i < m; i++) {
		if (fp[i].second <= s) {
			res = min(res, n * fp[i].first);
			int j = upper_bound(sc, sc + k, s - fp[i].second) - sc;
			j--;
			if (j >= 0 && j < k && sc[j] <= (s - fp[i].second)) {
				ll temp = n - ss[j];
				res = min(res, temp * fp[i].first);
			}
		}
	}
	for (int i = 0; i < k; i++)
		if (sc[i] <= s) {
			res = min(res, (n - ss[i]) * x);
		}

	cout << res << '\n';
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> k >> x >> s;
	for (int i = 0; i < m; i++) cin >> fp[i].first;
	for (int i = 0; i < m; i++) cin >> fp[i].second;
	for (int i = 0; i < k; i++) cin >> ss[i];
	for (int i = 0; i < k; i++) cin >> sc[i];
	compute();
}
