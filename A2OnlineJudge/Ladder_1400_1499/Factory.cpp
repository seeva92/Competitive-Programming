#include <bits/stdc++.h>
typedef long long ll;
const int mod = 1e9 + 7;
const int MAX = 1e5 + 7;
using namespace std;
typedef vector<int> vi;
class Factory
{
public:
	void solve() {
		ll a, m;
		cin >> a >> m;
		int len = 0;
		do {
			if (a % m == 0) break;
			a = a + (a % m);
			len++;
		} while (len < MAX);
		if (a % m == 0) cout << "Yes";
		else cout << "No";
	}

};
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	Factory f; f.solve();
}
