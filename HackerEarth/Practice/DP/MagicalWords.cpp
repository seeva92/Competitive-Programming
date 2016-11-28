#include <bits/stdc++.h>
const int mod = 1e9 + 7;
using namespace std;
typedef vector<int> vi;
int t, len; string s;
bool dp[1007][1007];
//Longest Palindromic substring
inline void f() {
	memset(dp, 0, sizeof dp);
	long long cnt = 0;
	for (int i = 0; i < len; i++ ) { dp[i][i] = true; cnt++; }
	for (int i = 0; i < len - 1; i++) {
		if (s[i] == s[i + 1]) { dp[i][i + 1] = true; cnt += (2 * 2); }
	}
	int j;
	for (int k = 3; k <= len; k++)
		for (int i = 0; i < len - k + 1; i++) {
			j = i + k - 1;
			if (dp[i + 1][j - 1] && (s[i] == s[j])) { cnt += (k * k); dp[i][j] = true; }
		}
	cout << cnt << '\n';
}
inline void f1() {
	int l, r;
	long long cnt = 0;
	for (int i = 0; i < len; i++) {
		l = i; r = i;
		for (; l >= 0 && r < len;)
			if (s[l] == s[r]) { cnt += ((r - l + 1) * (r - l + 1)); r++; l--;}
			else break;
		l = i; r = i + 1;
		for (; l >= 0 && r < len;)
			if (s[l] == s[r]) { cnt += ((r - l + 1) * (r - l + 1)); r++; l--;}
			else break;
	}
	cout << cnt << "\n";
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> t;
	while (t--) {
		cin >> s; len = s.size();
		f1();
	}
}
