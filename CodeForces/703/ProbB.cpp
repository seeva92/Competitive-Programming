#include <bits/stdc++.h>
const int mod = 1e9 + 7;
using namespace std;
long long arr[100007];
bool flag[100007];
long long total = 0, captotal = 0;
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	memset(flag, 0, sizeof flag);
	int n, k; cin >> n >> k;
	long long res = 0LL;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		total += arr[i];
	}
	int x;
	for (int i = 0; i < k; i++)	{
		cin >> x; flag[x - 1] = 1;
		total -= arr[x - 1];
		captotal += arr[x - 1];
	}

	for (int i = 0; i < n; i++) {
		if (flag[i]) {
			res += (total * arr[i]);
			captotal -= arr[i];
			res += (captotal * arr[i]);
		} else if (flag[(i + 1) % n]) {
			continue;
		} else {
			res += (arr[i] * arr[(i + 1) % n]);
		}
	}
	cout << res << '\n';

}
