#include <bits/stdc++.h>
typedef long long ll;
const int mod = 1e9 + 7;
const int MAX = 1e5 + 7;
using namespace std;
typedef vector<int> vi;
int N, M, x, y;
int arr[1007];
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	memset(arr, 0, sizeof arr);
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> x >> y;
		arr[x] = y; arr[y] = x;
	}
	int i;
	for (i = 1; i <= N && arr[i] != 0; i++);
	cout << N - 1 << '\n';
	for (int j = 1; j <= N; j++) {
		if (i == j) continue;
		cout << i << " " << j << '\n';
	}
}
