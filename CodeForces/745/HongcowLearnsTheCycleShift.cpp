#include <bits/stdc++.h>
typedef long long ll;
const int mod = 1e9 + 7;
const int MAX = 1e5 + 7;
using namespace std;
typedef vector<int> vi;
set<string> st;
class HongcowLearnsTheCycleShift
{
	string s;
public:
	void solve() {
		cin >> s;
		int len = s.size();
		for (int i = 0; i < len; i++) {
			// cout << s << '\n';
			st.insert(s);
			s = s[len - 1] + s.substr(0, len - 1);
		}
		st.insert(s);
		cout << st.size();
	}

};
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	HongcowLearnsTheCycleShift h; h.solve();
}
