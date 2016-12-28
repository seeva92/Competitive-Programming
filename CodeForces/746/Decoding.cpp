#include <bits/stdc++.h>
typedef long long ll;
const int mod = 1e9 + 7;
const int MAX = 1e5 + 7;
using namespace std;
typedef vector<int> vi;
class Decoding
{
public:
	void solve() {
		int n; cin >> n;
		string s; cin >> s;
		deque<char> d;
		bool flag = false;
		bool parity = (s.size() % 2) == 0;
		for (auto i : s) {
			if (parity) {
				if (!flag) {
					d.push_front(i);

				} else {
					d.push_back(i);
				}
			} else {
				if (!flag) {
					d.push_back(i);
				} else {
					d.push_front(i);
				}
			}
			flag = !flag;
		}
		for (auto i : d) cout << i;
	}

};
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	Decoding d; d.solve();
}
