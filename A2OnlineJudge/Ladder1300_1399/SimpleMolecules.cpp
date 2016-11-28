#include <bits/stdc++.h>
typedef long long ll;
const int mod = 1e9 + 7;
const int MAX = 1e5 + 7;
using namespace std;
typedef vector<int> vi;
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	int a, b, c;
	cin >> a >> b >> c;
	int lt, rt;
	for (int i = 0; i <= a; i++) {
		lt = i, rt = a - i;
		if (b >= lt && c >= rt && (b - lt) == (c - rt)) {
			cout << lt << " " << b - lt << " " << rt; return 0;
		}
	}
	cout << "Impossible";
}
