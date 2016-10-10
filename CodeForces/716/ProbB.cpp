#include <bits/stdc++.h>
const int mod = 1e9 + 7;
using namespace std;
int arr[26];
bool good() {
	for (int i = 0; i < 26; i++)
		if (arr[i] != 1) return false;
	return true;
}
int firstempty() {
	for (int i = 0; i < 26; i++)
		if (arr[i] == 0) return i;
	return -1;
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	memset(arr, 0, sizeof arr);
	string s; cin >> s;

	if (s.size() < 26) { cout << -1; return 0;}
	bool res = false;
	int curr = -1;

	for (int i = 0; i < int(s.size()); i++) {
		curr = -1;
		memset(arr, 0, sizeof arr);
		vector<pair<int, int>> temp;
		for (int j = i; j < (i + 26) && j < int(s.size()); j++) {
			if (s[j] != '?') arr[s[j] - 'A']++;
		}
		for (int j = i; j < (i + 26) && j < int(s.size()); j++) {
			if (s[j] == '?') {
				int fe = firstempty();
				arr[fe]++;
				if (j == i) {
					curr = fe;
				}
				temp.push_back({fe, j});
			}
		}
		if (good()) {
			res = true;
			for (auto j : temp)
				s[j.second] = 'A' + j.first;
			i = i + 25;
		}
		else {
			if (curr != -1) s[i] = 'A' + curr;
		}
	}
	if (res) cout << s << '\n';
	else cout << "-1\n";
}