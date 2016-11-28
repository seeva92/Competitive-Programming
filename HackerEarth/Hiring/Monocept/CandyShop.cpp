#include <bits/stdc++.h>
const int mod = 1e9 + 7;
using namespace std;
typedef vector<int> vi;
int cnt[1000007] = {1};
void init() {
	int arr[10] = {0}; int j, temp;
	for (int i = 1; i <= 1000000; i++) {
		j = 0; temp = i;

		while (i) {
			arr[j++] = i % 10;
			i /= 10;
		}
		i = temp;
		int k, l;
		for (k = 0, l = j - 1; (k <= l) && (arr[k] == arr[l]); k++, l--);
		cnt[i] = cnt[i - 1] + (k > l);
		// cout << i << " " << (k > l) << '\n';
	}
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	init();
	int T; cin >> T;
	int L, R;
	while (T--) {
		cin >> L >> R;
		cout << cnt[R] - cnt[L - 1] << '\n';
	}
}
