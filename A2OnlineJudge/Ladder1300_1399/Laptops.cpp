#include <bits/stdc++.h>
const int mod = 1e9 + 7;
const int MAX = 1e5 + 7;
using namespace std;
typedef vector<int> vi;
pair<int, int> lap[MAX];
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n; cin >> n;
	for (int i = 0; i < n; i++) cin >> lap[i].first >> lap[i].second;
	sort(lap, lap + n);
	int q = -1e9;
	for (int i = 0; i < n; i++)
		if (q > lap[i].second) {
			cout << "Happy Alex"; return 0;
		}
		else q = max(q, lap[i].second);
	cout << "Poor Alex";
}
