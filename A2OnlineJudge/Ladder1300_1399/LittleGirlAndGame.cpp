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
	memset(arr, 0, sizeof arr);
	string s; cin >> s;
	for (auto i : s) arr[i - 'a']++;
	int odd = 0;
	for (int i = 0; i < 26; i++) if (arr[i] & 1) odd++;

	if (odd == 0 || (odd & 1)) cout << "First";
	else cout << "Second";
}
