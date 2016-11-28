#include <bits/stdc++.h>
typedef long long ll;
const int mod = 1e9 + 7;
const int MAX = 1e5 + 7;
using namespace std;
typedef vector<int> vi;
int arr[MAX], ans[MAX];
pair<int, int> pos[MAX];
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m; cin >> n >> m;
	for (int i = 1; i <= n; i++)cin >> arr[i];
	for (int i = 0; i < m; i++) {
		cin >> pos[i].first; pos[i].second = i;
	}
	sort(pos, pos + m, greater<pair<int, int>>());
	int prev = n;
	set<int> st;
	for (int i = 0; i < m; i++) {
		// cout << pos[i].first << "\n";
		for (int j = pos[i].first; j <= prev; j++) {
			st.insert(arr[j]);
		}
		prev = pos[i].first;
		ans[pos[i].second] = int(st.size());
	}
	for (int i = 0; i < m; i++) cout << ans[i] << "\n";
}
