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
	list<int> dq;
	list<int>::iterator it = dq.begin();
	int idx = 1;
	for (auto i : s) {
		it = dq.insert(it, idx++);
		if (i == 'r') it = next(it);
	}
	for (auto i : dq) cout << i << " " ;

}
