#include <bits/stdc++.h>
typedef long long ll;
const int mod = 1e9 + 7;
const int MAX = 1e5 + 7;
using namespace std;
typedef vector<int> vi;
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n; cin >> n;
	string s; cin >> s;
	if (n == 1 || n == 2) { cout << s; return 0; }
	string res = "";
	for (int i = 0; i < n - 2;) {
		if (s[i] == 'o' && s[i + 1] == 'g' && s[i + 2] == 'o') {
			s[i] = s[i + 1] = s[i + 2] = '*';
			res.append("***");
			i += 2;
		} else if (s[i] == '*' && s[i + 1] == 'g' && s[i + 2] == 'o') {
			s[i + 1] = s[i + 2] = '*';
			i += 2;
		} else {
			if (s[i] != '*')
				res.push_back(s[i]);
			i++;
		}
	}
	if (s[n - 2] != '*') res.push_back(s[n - 2]);
	if (s[n - 1] != '*') res.push_back(s[n - 1]);

	cout << res;
}
