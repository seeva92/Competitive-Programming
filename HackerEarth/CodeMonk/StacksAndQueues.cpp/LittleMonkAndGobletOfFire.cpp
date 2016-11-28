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
	queue<int> school, q[5];
	set<int> st;
	int Q; cin >> Q;
	char c; int x, y;
	while (Q--) {
		cin >> c;
		if (c == 'E') {
			cin >> x >> y;
			if (st.find(x) == st.end()) {
				school.push(x); st.insert(x);
			}
			q[x].push(y);
		} else {
			int s;
			while (!school.empty()) {
				s = school.front();
				if (!q[s].empty()) {
					cout << s << " " << q[s].front() << '\n';
					q[s].pop();
					if (q[s].empty()) {
						school.pop(); st.erase(s);
					}
					break;
				}
				st.erase(s); school.pop();
			}

		}
	}
}
