#include <bits/stdc++.h>
const long long mod = 1e5;
using namespace std;
typedef vector<long long> vi;
long long arr[1007];
int vis[100007];
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	long long H, E; cin >> H >> E;
	long long N; cin >> N;
	for (long long i = 0; i < N; i++)cin >> arr[i];
	memset(vis, -1, sizeof vis);
	queue<long long> q; q.push(H); vis[H] = 0;
	while (!q.empty()) {
		long long x = q.front(); q.pop();
		if (x == E) break;
		for (long long i = 0; i < N; i++) {
			long long temp = (x * arr[i]) % mod;
			if (vis[temp] == -1) {
				vis[temp] = vis[x] + 1;
				q.push(temp);
			}
		}
	}
	cout << vis[E] << '\n';
}
