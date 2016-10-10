#include <bits/stdc++.h>
const int mod = 1e9 + 7;
using namespace std;
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n; cin >> n;
	int cn = 0, cm = 0; bool opened = false;
	int word = 0;
	char c;

	for (int i = 1; i <= n; i++) {
		cin >> c;
		if (c == '_') {
			if (word) {
				if (opened) cm++;
				else cn = max(cn, word);
			}
			word = 0;
			continue;
		}
		if (c == '(') {
			if (word) cn = max(cn, word);
			word = 0;
			opened = true; continue;
		}
		if (c == ')') {
			if (word) cm++;
			word = 0;
			opened = false; continue;
		}
		word++;
	}
	if (word) cn = max(cn, word);
	cout << cn << " " << cm << '\n';
}
