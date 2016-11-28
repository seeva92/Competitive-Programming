#include <bits/stdc++.h>
const int mod = 1e9 + 7;
using namespace std;
typedef vector<int> vi;
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	string s; cin >> s;
	for (int i = 0; i < int(s.size());) {
		size_t temp = s.find("WUB", i);
		if (temp != string::npos) {
			if (int(temp) != i) cout << s.substr(i, int(temp) - i) << " ";
			i = temp + 3;
		} else {
			int x = s.substr(i).size();
			cout << s.substr(i) << " ";
			i = i + x;
		}
	}
}
