#include <bits/stdc++.h>
const int mod = 1e9 + 7;
using namespace std;
typedef vector<int> vi;
int arr[1007];
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n; cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	sort(arr, arr + n);
	int zidx = lower_bound(arr, arr + n, 0) - arr;
	int nc = zidx;
	int pc = n - zidx - 1;
	if (pc > 0) {
		cout << 1 << " " << arr[0] << '\n';
		int tmp = upper_bound(arr, arr + n, 0) - arr;
		cout << 1 << " " << arr[tmp] << '\n';
		cout << n - 2 << " ";
		for (int i = 0; i < n; i++) if (i == 0 || i == tmp) continue;
			else cout << arr[i] << " "; cout << '\n';
	} else {
		if ((nc - 2 >= 2) && ((nc - 2) % 2 == 0)) {
			cout << nc - 3 << " "; for (int i = 0; i < zidx - 3; i++) cout << arr[i] << " "; cout << '\n';
			cout << 2 << " "; for (int i = zidx - 2; i < zidx; i++) cout << arr[i] << " "; cout << '\n';
			cout << n - zidx + 1 << " " << arr[nc - 3] << " "; for (int i = zidx; i < n; i++) cout << arr[i] << " "; cout << '\n';
		} else {
			cout << nc - 2 << " "; for (int i = 0; i < zidx - 2; i++) cout << arr[i] << " "; cout << '\n';
			cout << 2 << " "; for (int i = zidx - 2; i < zidx; i++) cout << arr[i] << " "; cout << '\n';
			cout << n - zidx << " ";
			for (int i = zidx; i < n; i++) cout << arr[i] << " "; cout << '\n';
		}


	}
}
