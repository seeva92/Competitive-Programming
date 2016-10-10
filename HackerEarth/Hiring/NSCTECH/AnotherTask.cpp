#include <bits/stdc++.h>
const int mod = 1e9 + 7;
using namespace std;
long long N, arr[1000007], Q;
long long B, C;
long long total[1000007];

void compute() {
	long long res = 1e13;
	long long val;
	int l = 1, r = N;
	while (l <= r) {
		int mid = l + (r - l) / 2;
		long long temp = total[N] * B - total[mid] * C;
		if (abs(temp) < res) {
			res = abs(temp);
			val = arr[mid];
		}
		if (temp < 0) {
			r = mid - 1;
		} else {
			l = mid + 1;
		}
	}
	cout << val << '\n';
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	memset(total, 0, sizeof total);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
		total[i] = total[i - 1] + arr[i];
	}
	cin >> Q;
	for (int i = 1; i <= Q; i++) {
		cin >> B >> C;
		compute();
	}

}
