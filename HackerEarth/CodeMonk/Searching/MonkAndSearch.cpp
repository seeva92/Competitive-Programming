#include <bits/stdc++.h>
const int mod = 1e9 + 7;
using namespace std;
typedef vector<int> vi;
int arr[100007];
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N; cin >> N;
	for (int i = 0; i < N; i++) cin >> arr[i];
	sort(arr, arr + N);
	int Q, i, x, tmp; cin >> Q;

	while (Q--) {
		cin >> i >> x;
		if (i) {
			tmp = upper_bound(arr, arr + N, x) - arr;
		} else {
			tmp = lower_bound(arr, arr + N, x) - arr;
		}
		cout << N - tmp << '\n';
	}
}
