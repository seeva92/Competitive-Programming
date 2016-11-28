#include <bits/stdc++.h>
typedef long long ll;
const int mod = 1e9 + 7;
const int MAX = 1e5 + 7;
using namespace std;
typedef vector<int> vi;
int n, a, b, c;
ll compute(int nk, ll sum, int cnt) {
	if ((nk % 4) == 0) {
		return sum;
	}
	if (cnt > 12) return 1e18;
	return min(min(compute(nk + 1, sum + a, cnt + 1), compute(nk + 2, sum + b, cnt + 1))
	           , compute(nk + 3, sum + c, cnt + 1));
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> a >> b >> c;
	cout << compute(n, 0, 0);
}
