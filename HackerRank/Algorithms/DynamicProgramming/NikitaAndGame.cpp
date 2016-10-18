#include <bits/stdc++.h>
const int mod = 1e9 + 7;
using namespace std;
typedef vector<int> vi;
int T, N;
vector<long long> arr((1 << 14) + 17), total((1 << 14) + 17, 0);
int f(int i, int j, long long red) {
	int tmp = j;
	while (i <= j) {
		int mid = (i + j) / 2;
		if (total[mid] - red == total[tmp] - total[mid]) return mid;
		else if (total[mid] - red > total[tmp] - total[mid]) j = mid - 1;
		else i = mid + 1;
	}
	return -1;
}
int compute(int i, int j, long long red) {
	if (i == j || i > j) return 0;
	int pos = f(i, j, red);
	if (pos == -1) return 0;

	return 1 + max(compute(i, pos, red), compute(pos + 1, j, total[pos]));
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> T;
	while (T--) {
		cin >> N;
		for (int i = 0; i < N; i++) cin >> arr[i];
		for (int i = 0; i < N; i++) {
			if (i == 0) total[i] = arr[i];
			else total[i] = total[i - 1] + arr[i];
		}
		if (total[N - 1] == 0) cout << N - 1 << '\n';
		else cout << compute(0, N - 1, 0) << '\n';
	}
}
