#include <bits/stdc++.h>
const int mod = 1e9 + 7;
using namespace std;
typedef vector<int> vi;
long long f(long long a) {
	long long pw = 1, aa = 0;
	while (a) {
		if (a % 10) {
			aa = ((a % 10) * pw) + aa;
			pw *= 10;
		}
		a /= 10;
	}
	return aa;
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	long long a, b; cin >> a >> b;

	if (f(a) + f(b) == f(a + b)) cout << "YES";
	else cout << "NO";
}
