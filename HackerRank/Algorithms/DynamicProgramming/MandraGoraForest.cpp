#include <bits/stdc++.h>
const int mod = 1e9 + 7;
const int MAX = 3e5 + 7;
using namespace std;
typedef vector<int> vi;
long long T, N;
long long arr[MAX];
void computeMax() {
	sort(arr, arr + N);
	for (int i = 1; i < N; i++) arr[i] += arr[i - 1];
	long long res = arr[N - 1];
	for (int i = 1; i < N; i++)
		if (res < (arr[N - 1] - arr[i - 1]) * (i + 1))
			res = (arr[N - 1] - arr[i - 1]) * (i + 1);
	cout << res << '\n';
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
		// cout << compute(N, 1);
		computeMax();
		// 857512
	}

}
