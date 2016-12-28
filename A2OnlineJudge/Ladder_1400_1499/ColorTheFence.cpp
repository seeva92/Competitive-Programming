#include <bits/stdc++.h>
typedef long long ll;
const int mod = 1e9 + 7;
const int MAX = 1e5 + 7;
using namespace std;
typedef vector<int> vi;
int arr[10];
int res[10 * MAX];
class ColorTheFence
{
public:
	void solve() {
		int n, v; cin >> v;
		int p = INT_MAX, pIdx;
		for (int i = 1; i <= 9; i++) {
			cin >> arr[i];
			if (p > arr[i]) {
				p = arr[i];
				pIdx = i;
			} else if (p == arr[i] && pIdx < i) {
				pIdx = i;
			}
		}
		int c = v / p;
		if (c == 0) { cout << -1; return;}
		for (int i = 0; i < c; i++) res[i] = pIdx;
		//Optimise
		int rem = v % p;
		for (int i = 0; i < c; i++) {
			for (int j = res[i] + 1; j <= 9; j++) {
				if ((rem + arr[res[i]]) >= arr[j]) {
					rem = rem + arr[res[i]] - arr[j];
					res[i] = j;
				}
			}
			cout << res[i];
		}

	}
};
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	ColorTheFence c; c.solve();
}
