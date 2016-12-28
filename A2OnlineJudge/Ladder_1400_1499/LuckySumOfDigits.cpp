#include <bits/stdc++.h>
typedef long long ll;
const int mod = 1e9 + 7;
const int MAX = 1e5 + 7;
using namespace std;
typedef vector<int> vi;
class LuckySumOfDigits
{
public:

	void solve() {
		int n; cin >> n;
		int i;
		bool flag = false;
		for (i = n / 7; i >= 0; i--) {
			if (n - (i * 7) == 0) { flag = true; break;}
			else if ((n - (i * 7)) % 4 == 0) { flag = true; break; }
		}
		if (flag) {
			if (n - (i * 7) == 0) {
				for (int j = 0; j < i; j++) cout << 7;
			} else if ((n - (i * 7)) % 4 == 0) {
				for (int j = (n - (i * 7)) / 4; j >= 1; j--) cout << 4;
				for (int j = i; j >= 1; j--) cout << 7;
			}
		}
		else cout << -1;
	}
};
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	LuckySumOfDigits l; l.solve();
}
