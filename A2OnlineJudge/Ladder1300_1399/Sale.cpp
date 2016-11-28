#include <bits/stdc++.h>
const int mod = 1e9 + 7;
using namespace std;
typedef vector<int> vi;
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m; cin >> n >> m; int x;
	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i = 0; i < n; i++) {
		cin >> x;
		if (x < 0) pq.push(x);
	}
	int total = 0;
	while (m > 0 && !pq.empty()) {
		total += ((-1) * pq.top());
		m--;
		pq.pop();
	}
	cout << total << '\n';
}
