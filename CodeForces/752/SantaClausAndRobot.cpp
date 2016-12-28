#include <bits/stdc++.h>
typedef long long ll;
const int mod = 1e9 + 7;
const int MAX = 1e5 + 7;
using namespace std;
typedef vector<int> vi;
set<pair<ll, ll>> st;
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	string s;
	cin >> n >> s;
	int ans = 0;
	for (int i = 0; i < n;) {
		int j, cl = 0, cr = 0, cu = 0, cd = 0;
		for (j = i; j < n; j++) {
			switch (s[j]) {
			case 'L': cl++; break;
			case 'R': cr++; break;
			case 'U': cu++; break;
			case 'D': cd++; break;
			}
			if ((cl && cr) || (cu && cd)) break;
		}
		i = j;
		ans++;
	}
	cout << ans;
}
