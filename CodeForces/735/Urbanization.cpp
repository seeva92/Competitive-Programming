#include <bits/stdc++.h>
typedef long long ll;
const int mod = 1e9 + 7;
const int MAX = 1e5 + 7;
using namespace std;
typedef vector<int> vi;
int arr[MAX];
class Urbanization
{
	int n, n1, n2;
public:
	void solve() {
		cin >> n >> n1 >> n2;
		for (int i = 0; i < n; i++) cin >> arr[i];
		sort(arr, arr + n, greater<int>());
		int l = min(n1, n2);
		ll lt = 0;
		for (int i = 0; i < l; i++) lt = 1LL * arr[i] + lt;
		int r = max(n1, n2);
		ll rt = 0;
		for (int i = l; i < (l + r); i++) rt = 1LL * arr[i] + rt;

		double res = ((double)lt / (double)l) + ((double)rt / (double)r);
		cout << fixed << setprecision(10) << res;
	}

};
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);

	Urbanization u; u.solve();
}
