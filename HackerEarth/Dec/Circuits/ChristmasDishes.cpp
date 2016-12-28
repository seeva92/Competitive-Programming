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
	int n, k;
	cin >> n >> k;
	string s;
	for (int i = 0; i < n; i++) s.push_back('a');
	if (n == 2) {
		if (k == n) cout << s;
		else {
			s[(n - 1) / 2] = 'b';
			cout << s;
		}
	} else {
		if (k == n) cout << s;
		else cout << "No";
	}
}
