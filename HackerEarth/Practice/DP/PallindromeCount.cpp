#include <bits/stdc++.h>
typedef long long ll;
const int mod = 1e9 + 7;
const int MAX = 1e5 + 7;
using namespace std;
typedef vector<int> vi;
string s;
bool dp[57][57]; int len;
void solve() {
	cin >> s; len = s.length();
	for (int i = 0; i < len; i++) dp[i][i] = true;
	int j;
	int cnt = len;
	for (int i = 0; i < len - 1; i++) if (s[i] == s[i + 1]) { dp[i][i + 1] = true; cnt++; }
	for (int k = 2; k < len; k++) {
		for (int i = 0; i < len - k + 1; i++) {
			j = i + k - 1;
			if (dp[i + 1][j - 1] && s[i] == s[j]) {
				dp[i][j] = true;
				cnt++;
			}
		}
	}
	cout << cnt;
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
}
