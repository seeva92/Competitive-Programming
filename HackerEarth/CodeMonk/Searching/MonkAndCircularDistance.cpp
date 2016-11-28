#include <bits/stdc++.h>
const int mod = 1e9 + 7;
using namespace std;
typedef long long ll;
typedef vector<int> vi;
ll N, x, y;
long double arr[100007], eps = 1e-19;

bool cmp(long double a, long double b) {
	return a < (b + eps);
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> x >> y;
		arr[i] = sqrt((x * x) + (y * y));
	}
	sort(arr, arr + N, cmp);
	// for (int i = 0; i < N; i++) cout << arr[i] << " " ;
	int q; cin >> q;
	long double r;
	while (q--) {
		cin >> r;
		cout << (upper_bound(arr, arr + N, r, cmp) - arr) << '\n';
	}
}
