#include <bits/stdc++.h>
typedef long long ll;
const int mod = 1e9 + 7;
const int MAX = 1e5 + 7;
using namespace std;
typedef vector<int> vi;
int arr[MAX];
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, k; cin >> n >> k;
	int tot = 0;
	for (int i = 0; i < n; i++) {
		cin >> arr[i]; tot += arr[i];
	}
	// cout << tot << '\n';
	int prev = -1;
	for (int i = 0; i < n && arr[i] < 0; i++) {
		if (k > 0) {
			arr[i] = -arr[i];
			tot += 2 * arr[i];
			k--;
			prev = i;

		}
	}
	// cout << tot << '\n';
	if (k % 2 == 0) cout << tot;
	else if (prev != -1) {
		if (prev + 1 < n) {
			if (arr[prev + 1] == 0) cout << tot;
			else cout << max(tot - (2 * arr[prev]), tot - (2 * arr[prev + 1]));
		} else cout << tot - 2 * arr[prev];
	}
	else {
		// cout << arr[0] << " sdfa";
		cout << tot - 2 * arr[0];
	}
}
