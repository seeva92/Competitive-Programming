#include <bits/stdc++.h>
const int mod = 1e9 + 7;
using namespace std;
typedef vector<int> vi;
bool dp[15]; int n; string s;
void compute() {
	if (s[0] == '1') dp[1] = true;
	for (int i = 2; i <= int(s.size()); i++) {
		if (dp[i - 1]) dp[i] = (s[i - 1] == '1');
		if (i - 1 >= 1 && dp[i - 1])
			dp[i] |= (s.substr(i - 2, 2) == "14");
		if (i - 2 >= 1 && dp[i - 2])
			dp[i] |= (s.substr(i - 3, 3) == "144");
		if (!dp[i]) break;
	}
	if (dp[int(s.size())]) cout << "YES";
	else cout << "NO";
}
void comp() {
	int i, inc = 0;
	for (i = 0; i < int(s.size());) {
		inc = 0;
		if (s.substr(i, 1) == "1") inc = 1;;
		if (s.substr(i, 2) == "14")inc = 2;
		if (s.substr(i, 3) == "144") inc = 3;
		if (inc == 0) break;
		else i = i + inc;
	}
	if (i == int(s.size())) cout << "YES";
	else cout << "NO";
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	memset(dp, 0, sizeof dp);
	cin >> n;
	s = to_string(n); //cout << s << '\n';
	comp();
}
