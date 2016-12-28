#include <bits/stdc++.h>
typedef long long ll;
const int mod = 1e9 + 7;
const int MAX = 1e5 + 7;
using namespace std;
typedef vector<int> vi;
class DisplaySize
{
public:
	void solve() {

		int n;
		cin >> n;
		int len = sqrt(n);
		int diff = INT_MAX, lf, rf;
		for (int i = 1; i <= len; i++) {
			if (n % i == 0) {
				if (diff > ((n / i) - i)) {
					diff = ((n / i) - i);
					lf = i;
					rf = n / i;
				}
			}
		}
		cout << lf << " " << rf;
	}
};
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	DisplaySize d; d.solve();
}
