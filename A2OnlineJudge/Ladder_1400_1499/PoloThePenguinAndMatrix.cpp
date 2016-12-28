#include <bits/stdc++.h>
typedef long long ll;
const int mod = 1e9 + 7;
const int MAX = 1e5 + 7;
using namespace std;
typedef vector<int> vi;
int arr[10007];
class PoloThePenguinAndMatrix
{
	int n, m, d;
public:
	void solve() {
		cin >> n >> m >> d;
		int len = n * m;
		for (int i = 0; i < len; i++) cin >> arr[i];
		for (int i = 0; i < len; i++) {
			if (( arr[i] - arr[0]) % d) {
				cout << -1; return;
			}
		}
		sort(arr, arr + len);
		int med = (len % 2) == 0 ? arr[(len / 2) - 1] : arr[(len / 2)];
		ll total = 0;
		for (int i = 0; i < len; i++) {
			total += abs(arr[i] - med);
		}
		cout << total / d;
	}

};
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	PoloThePenguinAndMatrix p; p.solve();
}
