#include <bits/stdc++.h>
typedef long long ll;
const int mod = 1e9 + 7;
const int MAX = 1e5 + 7;
using namespace std;
typedef vector<int> vi;
int arr[MAX];
class Arrays
{
	int n, k;
	map<int, int> mp;
public:
	void solve() {
		cin >> n >> k;
		int l = 1, r = 0;
		for (int i = 1; i <= n; i++) {
			cin >> arr[i];
			if (mp.size() < k) {
				mp[arr[i]]++; r++;
			} else break;
		}
		if (mp.size() == k) {
			for (int i = l; i <= r; i++) {
				if (mp[arr[i]] > 1) {
					mp[arr[i]]--; l++;
				} else break;
			}
			cout << l << " " << r;
		}
		else cout << -1 << " " << -1;
	}

};
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	Arrays a; a.solve();
}
