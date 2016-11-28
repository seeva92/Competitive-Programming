#include <bits/stdc++.h>
const int mod = 1e9 + 7;
using namespace std;
typedef vector<int> vi;
int compute(string s) {
	if (int(s.size()) == 1) return 0;
	long long res = 0;
	for (auto i : s)
		res += (i - 48);
	return 1 + compute(to_string(res));
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	string s; cin >> s;
	cout << compute(s);
}
