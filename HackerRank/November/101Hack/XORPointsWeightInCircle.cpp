#include <bits/stdc++.h>
typedef long long ll;
const ll mod = 1e9 + 7;
const int MAX = 1e5 + 7;
using namespace std;
typedef vector<int> vi;
ll arr[307][307];
ll r;
ll n, m;
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> r;
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			if (i - 1 >= 0) arr[i][j] += arr[i - 1][j];
			if (j - 1 >= 0) arr[i][j] += arr[i][j - 1];
			if (i - 1 >= 0 && j - 1 >= 0) arr[i][j] -= arr[i - 1][j - 1];
		}
	ll res = 0, s1 = 0, s2 = 0, s3 = 0, s4 = 0, curr;
	ll tr = r - 1;
	ll bli, blj, uli, ulj;
	for (ll i = 0; i < n; i++)
		for (ll j = 0; j < m; j++) {
			bli = i + tr < n ? i + tr : n;
			blj = j + tr < m ? j + tr : m;
			uli = i - tr >= 0 ? i - tr : 0;
			ulj = j - tr >= 0 ? j - tr : 0;
			cout << bli << " " << blj << " " << uli << " " << ulj << '\n';
			curr = arr[bli][blj];
			if (uli - 1 >= 0) curr -= arr[uli - 1][blj];
			if (ulj - 1 >= 0) curr -= arr[blj][ulj - 1];
			if (uli - 1 >= 0 && ulj - 1 >= 0) curr += arr[uli - 1][ulj - 1];

			if (uli - 1 >= 0) {
				s1 = arr[uli - 1][j];
				if (uli - 2 >= 0) s1 -= arr[uli - 2][j];
				if (j - 1 >= 0) s1 -= arr[uli - 1][j - 1];
				if (j - 1 >= 0 && uli - 2 >= 0) s1 += arr[uli - 2][j - 1];
				curr += s1;
			}

			if (ulj - 1 >= 0) {
				s2 = arr[i][ulj - 1];
				if (ulj - 2 >= 0) s2 -= arr[i][ulj - 2];
				if (i - 1 >= 0) s2 -= arr[i - 1][ulj - 1];
				if (i - 1 >= 0 && ulj - 2 >= 0) s2 += arr[i - 1][ulj - 2];
				curr += s2;
			}

			if (blj + 1 < m) {
				s3 = arr[i][blj + 1];
				if (i - 1 >= 0) s3 -= arr[i - 1][blj + 1];
				if (blj >= 0) s3 -= arr[i][blj];
				if (i - 1 >= 0 && blj >= 0) s3 += arr[i - 1][blj];
				curr += s3;
			}

			if (bli + 1 < n) {
				s4 = arr[bli + 1][j];
				if (j - 1 >= 0) s4 -= arr[bli + 1][j - 1];
				if (bli >= 0) s4 -= arr[bli][j];
				if (bli >= 0 && j - 1 >= 0) s4 += arr[bli][j - 1];
				curr += s4;
			}
			cout << curr << '\n';
			res ^= curr;
		}
	cout << res;
}
