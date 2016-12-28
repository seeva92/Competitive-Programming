#include <bits/stdc++.h>
typedef long long ll;
const int mod = 1e9 + 7;
const int MAX = 1e5 + 7;
using namespace std;
typedef vector<int> vi;
class VladikAndFights
{
public:
	void solve() {
		int n, a, b; cin >> n >> a >> b;
		a--; b--;
		string s; cin >> s;
		if (s[a] == s[b]) { cout << 0;}
		else {
			cout << 1;
		}
	}

};
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	VladikAndFights v; v.solve();
}
