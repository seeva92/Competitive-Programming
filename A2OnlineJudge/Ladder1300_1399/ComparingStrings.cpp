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
	string a, b;
	cin >> a >> b;
	if (a.size() != b.size()) cout << "NO";
	else {
		int len = a.size();
		int c = 0;
		int f = -1, s = -1;
		for (int i = 0; i < len && c <= 2; i++) {
			if (a[i] != b[i]) {
				if (f == -1) f = i;
				else if (s == -1) s = i;
				c++;
			}
		}
		// cout << c << " " << f << " " << s;
		if (c == 2 && (a[s] == b[f]) && (a[f] == b[s])) cout << "YES";
		else cout << "NO";
	}
}
