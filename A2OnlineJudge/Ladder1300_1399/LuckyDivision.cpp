#include <bits/stdc++.h>
const int mod = 1e9 + 7;
using namespace std;
typedef vector<int> vi;
vi v;
void init() {
	string tmp;
	queue<string> q; q.push("4"); q.push("7");
	while (!q.empty() && int(q.front().size()) <= 3) {
		tmp = q.front(); q.pop();
		v.push_back(stoi(tmp));
		q.push(tmp + "4"); q.push(tmp + "7");
	}
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	init();
	int n; cin >> n; bool flag = false;
	for (auto i : v) {
		if ((n >= i) && (n % i == 0)) { flag = !flag; break;}
	}
	if (flag) cout << "YES";
	else cout << "NO";
}
