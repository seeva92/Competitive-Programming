#include <bits/stdc++.h>
typedef long long ll;
const int mod = 1e9 + 7;
const int MAX = 1e5 + 7;
using namespace std;
typedef vector<int> vi;
int arr[26];
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	for (int i = 0; i < 26; i++) arr[i] = -1;
	string f, s; cin >> f >> s;
	int len = f.size();
	for (int i = 0; i < len; i++) {
		// if (f[i] == s[i]) continue;

		if ((arr[f[i] - 'a'] == -1) || arr[f[i] - 'a'] == (s[i] - 'a')) {
			arr[f[i] - 'a'] = s[i] - 'a';
		} else {
			cout << -1; return 0;
		}

		if ((arr[s[i] - 'a'] == -1) || (arr[s[i] - 'a'] == (f[i] - 'a'))) {
			arr[s[i] - 'a'] = f[i] - 'a';
		} else {
			cout << -1; return 0;
		}
	}
	vector<pair<char, char>> v;
	for (int i = 0; i < 26; i++) {
		if (arr[i] == -1 || arr[i] == i) continue;
		if (i < arr[i]) {
			v.push_back({(char)(i + 'a'), (char)(arr[i] + 'a')});
		}
	}
	cout << v.size() << '\n';
	for (auto i : v) cout << i.first << " " << i.second << '\n';
}
