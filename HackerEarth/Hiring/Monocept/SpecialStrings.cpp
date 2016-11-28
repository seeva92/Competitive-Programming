#include <bits/stdc++.h>
const int mod = 1e9 + 7;
using namespace std;
typedef vector<int> vi;
string arr[17];
unordered_set<string> st;
unordered_map<string, int> mp[10];
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n; cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	for (int i = 0; i < n; i++) {
		int len = arr[i].size();
		for (int j = 0; j < len; j++) {
			for (int k = 1; k < len - j + 1; k++) {
				if (is_sorted(arr[i].begin() + j, arr[i].begin() + j + k)) {
					st.insert(arr[i].substr(j, k));
				}
			}
		}
	}
	int cnt = 0; int curr = 0;
	for (auto i : st) {
		curr = 0;
		for (int j = 0; j < n; j++) {
			if (arr[j].find(i) != string::npos) curr++;
		}
		if (curr == n) cnt++;
	}
	cout << cnt << '\n';
}