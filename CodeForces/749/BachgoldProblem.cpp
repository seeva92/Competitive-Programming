#include <bits/stdc++.h>
typedef long long ll;
const int mod = 1e9 + 7;
const int MAX = 1e5 + 7;
using namespace std;
typedef vector<int> vi;
class BachgoldProblem
{
public:
	void solve() {
		int n; cin >> n;
		if (n % 2 == 0) {
			cout << n / 2 << '\n';
			for (int i = 0; i < (n / 2); i++) cout << 2 << " ";
		} else {
			int temp = (n / 2) - 1;
			cout << temp + 1 << '\n';
			for (int i = 0; i < temp; i++) {
				cout << 2 << " ";
			}
			cout << 3;
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
	BachgoldProblem b; b.solve();
}
