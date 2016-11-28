#include <bits/stdc++.h>
const int mod = 1e9 + 7;
using namespace std;
typedef vector<int> vi;
int arr[100007], n, d;
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> d;
	for (int i = 0; i < n; i++) cin >> arr[i];
	int temp = d % n;
	for (int i = temp; i < n; i++) cout << arr[i] << " ";
	for (int i = 0; i < temp; i++) cout << arr[i] << " ";
}
