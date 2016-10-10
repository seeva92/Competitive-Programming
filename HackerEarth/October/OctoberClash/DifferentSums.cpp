#include <bits/stdc++.h>
const int mod = 1e9 + 7;
using namespace std;
int arr[10007];
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n; cin >> n;
	cout << n; n--;
	for (int i = 1; i <= (n / 2); i++)
		cout << " " << i * 2 << " " << (i * 2) - 1;
	if (n % 2 != 0)cout << " " << n;
}