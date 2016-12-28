#include <bits/stdc++.h>
typedef long long ll;
const int mod = 1e9 + 7;
const int MAX = 1e5 + 7;
using namespace std;
typedef vector<int> vi;
int arr[MAX];
class PhyscisPractical
{
	int n;
public:
	void solve() {
		cin >> n;
		for (int i = 0; i < n; i++) cin >> arr[i]; sort(arr, arr + n);
		int l = 0, r = n - 1;
		int cnt = 0;

		int ll, rr;
		do {
			if (arr[l] * 2 >= arr[r]) break;
			int rr = r + 1 - (upper_bound(arr + l + 1, arr + r + 1, 2 * arr[l]) - arr);
			int ll = (lower_bound(arr + l, arr + r, (arr[r] + 1) / 2) - arr) - l;
			if (ll <= rr) {
				l++;
			} else {
				r--;
			}
			cnt++;
		} while (l < r);
		cout << cnt;
	}

};
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	PhyscisPractical p; p.solve();
}
