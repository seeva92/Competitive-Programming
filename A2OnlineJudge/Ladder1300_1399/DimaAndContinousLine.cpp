#include <bits/stdc++.h>
typedef long long ll;
const int mod = 1e9 + 7;
const int MAX = 1e5 + 7;
using namespace std;
typedef vector<int> vi;
int arr[3007], N;
pair<int, int> p[3007];
class DimaAndContinousLine {
public:
	void solve() {
		cin >> N;
		for (int i = 0; i < N; i++) cin >> arr[i];
		int l, r, ll, rr;
		for (int i = 0; i < N - 2; i++) {
			l = min(arr[i], arr[i + 1]); r = max(arr[i], arr[i + 1]);
			for (int j = i + 1; j < N - 1; j++) {
				ll = min(arr[j], arr[j + 1]); rr = max(arr[j], arr[j + 1]);
				if (l < ll && ll < r && r < rr) {cout << "yes"; return; }
				else if (ll < l && l < rr && rr < r) { cout << "yes"; return;}
			}
		}

		cout << "no";
	}
};
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	DimaAndContinousLine d; d.solve();
}
