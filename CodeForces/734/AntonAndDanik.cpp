#include <bits/stdc++.h>
typedef long long ll;
const int mod = 1e9 + 7;
const int MAX = 1e5 + 7;
using namespace std;
typedef vector<int> vi;
string s;
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n; cin >> n >> s;
	int a = 0, d = 0;
	for (auto i : s) {
		if (i == 'A') a++;
		else d++;
	}
	if (a > d)cout << "Anton";
	else if (a < d) cout << "Danik";
	else cout << "Friendship";
}

