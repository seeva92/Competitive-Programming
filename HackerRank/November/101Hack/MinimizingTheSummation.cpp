#include <bits/stdc++.h>
typedef long long ll;
const int mod = 1e9 + 7;
const int MAX = 1e5 + 7;
using namespace std;
typedef vector<int> vi;
int n, k;
ll arr[MAX], sqarr[MAX];
void compute() {
	sort(arr, arr + n);
	sqarr[0] = arr[0] * arr[0];
	for (int i = 1; i < n; i++) {
		sqarr[i] = sqarr[i - 1] + (arr[i] * arr[i]);
		arr[i] += arr[i - 1];
	}
	// for (int i = 0; i < n; i++) cout << arr[i] << " "; cout << '\n';
	// for (int i = 0; i < n; i++) cout << sqarr[i] << " "; cout << '\n';
	ll res = (2 * k * sqarr[k - 1]) - (2 * (arr[k - 1] * arr[k - 1]));
	// cout << res << " " << sqarr[k - 1] << " " << arr[k - 1] << '\n';
	ll tl, sqtl, temp;
	for (int i = k; i < n; i++) {
		sqtl = sqarr[i] - sqarr[i - k];
		tl = arr[i] - arr[i - k];
		temp = (2 * k * sqtl) - (2 * tl * tl);
		res = min(res, (2 * k * sqtl) - (2 * tl * tl));
		// cout << temp << " " << sqtl << " " << tl << '\n';
	}
	// cout << '\n';
	cout << res;
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;
	for (int i = 0; i < n; i++) cin >> arr[i];
	compute();

}
