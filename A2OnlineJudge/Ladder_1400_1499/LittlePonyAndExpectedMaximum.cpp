#include <bits/stdc++.h>
typedef long long ll;
const int mod = 1e9 + 7;
const int MAX = 1e5 + 7;
using namespace std;
typedef vector<int> vi;
class LittlePonyAndExpectedMaximum
{
	int n, m;
public:
	void solve() {
		cin >> m >> n;
		double res = 0;
		//i*(i^n - (i-1)^n)/m^n for all values of m
		for (int i = 1; i <= m; i++) {
			res += i * (pow(double(i) / m, n) - pow(double(i - 1) / m, n));
		}
		cout << fixed << setprecision(15) << res;
	}

};
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	LittlePonyAndExpectedMaximum l; l.solve();
}
