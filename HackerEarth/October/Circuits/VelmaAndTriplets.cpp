#include <bits/stdc++.h>
const int mod = 1e9 + 7;
using namespace std;
typedef vector<int> vi;
long long N, arr[400007];

int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	long long tot = 0;
	for (int i = 0; i < N; i++) cin >> arr[i];
	for (int i = 0; i < N; i++)
		for (int j = i + 1; j < N; j++)
			for (int k = j + 1; k < N; k++) {
				tot += ((arr[i] + arr[j] + arr[k]) / (arr[i] * arr[j] * arr[k]));
			}
	cout << tot << '\n';
}
