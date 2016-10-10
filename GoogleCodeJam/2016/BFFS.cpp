#include <bits/stdc++.h>
#define vi vector<int>
#define pi pair<int,int>
#define vii vector<pi>
#define ll long long
using namespace std;
int t, n;
int arr[1007];
int visited[1007];
int closed_on = -1;
int closed_at = -1;
int val = 0;
void dfs(int i, int d) {
	cout << i << " " << d << endl;
	if (visited[i]) {
		closed_on = i;
		closed_at = d;
		return;
	}
	visited[i] = 1;
	dfs(arr[i], d + 1);
	if ((i == closed_on) && ((closed_at - d) > val)) {
		val = closed_at - d;
		cout << "Val " << val << endl;
	}
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("/home/shiva/Learning/1.txt", "r", stdin);
	freopen("/home/shiva/Learning/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> t;
	for (int x = 1; x <= 3; x++) {
		cin >> n;
		for (int i = 1; i <= n; i++) cin >> arr[i];
		for (int i = 1; i <= n; i++) {
			closed_on = -1, closed_at = -1;
			memset(visited, 0, sizeof visited);
			dfs(i, 1);
		}
		cout << val << endl;
		val = 0;
	}
}