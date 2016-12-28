#include <bits/stdc++.h>
typedef long long ll;
const int mod = 1e9 + 7;
const int MAX = 5e5 + 7;
using namespace std;
typedef vector<int> vi;
int arr[MAX];
class CountingKangaroosIsFun
{
	int n;
	int cnt;
public:
	void solve() {
		cin >> n;
		cnt = n;
		for (int i = 0; i < n; i++) cin >> arr[i];
		sort(arr, arr + n);
		int p = n / 2;

		for (int i = 0; i < n / 2 && p < n; i++) {
			while (p < n) {
				if (arr[i] * 2 <= arr[p]) {
					cnt--; p++; break;
				} else {
					p++;
				}
			}
		}
		cout << cnt;
	}

};
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	CountingKangaroosIsFun c; c.solve();
}
