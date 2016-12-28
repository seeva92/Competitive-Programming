#include <bits/stdc++.h>
typedef long long ll;
const int mod = 1e9 + 7;
const int MAX = 1e5 + 7;
using namespace std;
typedef vector<int> vi;
bool dp[60][60];
class ThePalindrome
{
public:
	int find(string s) {
		reverse(s.begin(), s.end());
		memset(dp, 0, sizeof dp);
		int len = s.size();
		for (int i = 0; i <= len; i++) dp[i][i] = true;
		for (int i = 0; i < len - 1; i++) if (s[i] == s[i + 1]) dp[i][i + 1] = true;


		for (int i = 3; i <= len; i++) {
			for (int j = 0; j < len - i + 1; j++) {
				int k = j + i - 1;
				if (dp[j + 1][k - 1] == true && (s[j] == s[k])) dp[j][k] = true;
			}
		}
		int idx = -1;
		for (int i = 0; i < len; i++) if (dp[0][i]) idx = i;
		idx++;
		return len + (len - idx);
	}

};
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	ThePalindrome t;
	cout << t.find("abdfhdyrbdbsdfghjkllkjhgfds");
}
