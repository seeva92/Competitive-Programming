#include <bits/stdc++.h>
const int mod = 1e9 + 7;
using namespace std;
typedef vector<int> vi;
int T, N, K;
long long arr[10007];
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> T;
	while (T--) {
		cin >> N >> K;
		for (int i = 0; i < N; i++) cin >> arr[i];
		long long res = 1e9, resIdx = -1;
		long long curr = 0;
		for (int i = 0; i < N && i < K; i++) {
			curr ^= arr[i];
		}
		if (res >= curr) { res = curr; resIdx = 0;}
		for (int i = K; i < N; i++) {
			curr ^= arr[i - K];
			curr ^= arr[i];
			if (res >= curr) { res = curr; resIdx = i - K + 1;}
		}
		cout << resIdx + 1 << '\n';
	}
}
