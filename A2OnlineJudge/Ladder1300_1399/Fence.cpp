#include <bits/stdc++.h>
typedef long long ll;
const int mod = 1e9 + 7;
const int MAX = 1e5 + 7;
using namespace std;
typedef vector<int> vi;
int N, K, arr[20 * MAX];
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> K;
	for (int i = 0; i < N; i++) cin >> arr[i];
	int res = 1e9, curr = 0, idx = 0;
	for (int i = 0; i < N && i < K; i++) curr += arr[i];
	res = min(res, curr);
	for (int i = K; i < N; i++) {
		curr -= arr[i - K]; curr += arr[i];
		if (res > curr) {
			res = curr;
			idx = i - K + 1;
		}
	}
	cout << idx + 1;
}
