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
	string s;
	cin >> s;
	string sub = "hello";
	bool flag = true;
	int idx = 0;
	for (auto i : sub) {
		// cout << idx << "\n";
		if (s.find(i, idx) == string::npos) {
			flag = false; break;
		}
		idx = s.find(i, idx) + 1;

	}
	if (flag) cout << "YES";
	else cout << "NO";
}
