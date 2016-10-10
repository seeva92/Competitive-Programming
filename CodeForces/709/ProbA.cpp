#include <bits/stdc++.h>
const int mod = 1e9 + 7;
using namespace std;
int arr[300007];
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	long long n, b, d; cin >> n >> b >> d;
	long long x, sum = 0;
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		cin >> x;
		if (x > b) continue;
		sum += x ;
		if (sum > d) { cnt++; sum = 0;}
	}
	cout << cnt;
}
