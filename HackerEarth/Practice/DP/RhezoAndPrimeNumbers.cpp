#include <bits/stdc++.h>
const int mod = 1e9 + 7;
using namespace std;
typedef vector<int> vi;
const int MAX = 5007;
bitset<MAX> bs;
vi primes;
int N; int arr[MAX];
int dp[5007];
void init() {
	bs.set(); bs[0] = bs[1] = 0;
	int len = sqrt(MAX);
	for (int i = 2; i <= len; i++)
		if (bs[i]) {
			for (int j = i * i; j < MAX; j += i) bs[j] = 0;
		}
	for (int i = 2; i < MAX; i++) if (bs[i]) primes.push_back(i);
}
inline int getsum(int i, int r) {
	if (i - r < 0) return arr[i];
	return arr[i] - arr[i - r];
}
void compute() {
	if (bs[N]) { cout << arr[N - 1]; return; }
	memset(dp, 0, sizeof dp);
	dp[1] = 0;
	dp[2] = max(dp[1], getsum(1, 2));
	int len = primes.size(), res;
	for (int i = 3; i <= N; i++) {
		res = dp[i - 1];
		for (int j = 0; j < len && primes[j] <= i; j++ ) {
			int curr = getsum(i - 1, primes[j]);
			if (i - primes[j] - 1 >= 1) curr += dp[i - primes[j] - 1];
			if (res < curr) res = curr;
		}

		dp[i] = res;
	}
	cout << dp[N];
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("1.txt", "r", stdin);
	freopen("2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	init();
	cin >> N;
	for (int i = 0; i < N; i++) cin >> arr[i];
	for (int i = 1; i < N; i++) arr[i] += arr[i - 1];
	if (N == 1) cout << 0;
	else compute();
}
