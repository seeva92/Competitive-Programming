#include <bits/stdc++.h>
typedef long long ll;
const int mod = 1e9 + 7;
const int MAX = 1e5 + 7;
using namespace std;
typedef vector<int> vi;
int arr[MAX];
class LittlePonyAndSortByShift
{
	int n;
	int incpos, decpos;
public:
	bool inc() {
		bool flip = false;
		for (int i = 1; i < n; i++) {
			if (!flip) {
				if (arr[i] >= arr[i - 1]) continue;
				else {
					incpos = i;
					flip = !flip;
				}
			} else {
				if (arr[i] >= arr[i - 1]) continue;
				return false;
			}
		}
		return flip;
	}
	void solve() {
		cin >> n;
		for (int i = 0; i < n; i++) cin >> arr[i];
		if (is_sorted(arr, arr + n)) { cout << 0; return; }
		bool in = inc();
		if (!in) { cout << -1; return;}
		if (in && arr[n - 1] <= arr[0] && arr[incpos] <= arr[0]) {
			cout << n - incpos;
		} else cout << -1;
	}

};
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	LittlePonyAndSortByShift l; l.solve();
}
