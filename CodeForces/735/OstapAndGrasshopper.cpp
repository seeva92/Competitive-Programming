#include <bits/stdc++.h>
typedef long long ll;
const int mod = 1e9 + 7;
const int MAX = 1e5 + 7;
using namespace std;
typedef vector<int> vi;
class OstapAndGrasshopper
{
	int n, k;
public:
	void solve() {
		string s; cin >> n >> k;
		cin >> s;
		int idx = s.find('G');
		bool flag = false;
		for (int i = idx + k; i < n; i += k) {
			if (s[i] == '#') break;
			else if (s[i] == 'T') { flag = true; break;}
		}
		for (int i = idx - k; i >= 0; i -= k) {
			if (s[i] == '#') break;
			else if (s[i] == 'T') { flag = true; break;}
		}
		if (flag) cout << "YES";
		else cout << "NO";
	}

};
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	OstapAndGrasshopper o; o.solve();
}
