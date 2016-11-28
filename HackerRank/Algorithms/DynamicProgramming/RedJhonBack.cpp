#include <bits/stdc++.h>
const int mod = 1e9 + 7;
using namespace std;
typedef vector<int> vi;
long long arr[50] = {0};
const long long MAX = 6000007;
bitset<MAX> bs;
vector<long long> primes;
void init() {
	bs.set(); bs[0] = bs[1] = 0;
	// long long len = sqrt(MAX);
	for (long long i = 2; i < MAX; i++)
		if (bs[i]) {
			for (long long j = i * i; j < MAX; j += i)
				bs[j] = 0;
			primes.push_back(i);
		}
	// for (auto i : primes)
	// cout << i << "\n";

}
int getCount(long long n) {
	return upper_bound(primes.begin(), primes.end(), n) - primes.begin();
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	init();
	arr[0] = arr[1] = arr[2] = arr[3] = 1;
	for (int i = 4; i < 51; i++) {
		arr[i] = arr[i - 1] + arr[i - 4];
	}
	// for (int i = 1; i < 51; i++) cout << arr[i] << " "; cout << '\n';
	int t, n;
	// for (int i = 1; i <= 20; i++)
	// cout << getCount(i) << " ";
	cin >> t;
	while (t--) {
		cin >> n;
		if (n == 1) cout << "0\n";
		else cout << getCount(arr[n]) << '\n';

	}
}
