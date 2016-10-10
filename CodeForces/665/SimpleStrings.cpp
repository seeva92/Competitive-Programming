#include <bits/stdc++.h>
#define vi vector<int>
#define pi pair<int,int>
#define vii vector<pi>
#define ll long long
using namespace std;
string alpha = "abcdefghijklmnopqrstuvwxyz";
inline char getalpha(char l, char r) {
	for (auto it : alpha)
		if (it != l && it != r) return it;
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("/home/shiva/Learning/1.txt", "r", stdin);
	freopen("/home/shiva/Learning/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false); cin.tie(0);
	string s;
	cin >> s; int len = int(s.size());
	int st = -1, et = -1;
	for (int i = 0; i < len; i++) {
		if (i + 1 < len && s[i] == s[i + 1]) {
			if (st == -1) st = i;
			et = i + 1;
		} else if (st != -1 && et != -1) {
			for (int j = st + 1; j <= et; j += 2) {
				if (j + 1 < len) {
					s[j] = getalpha(s[j], s[j + 1]);
				} else {
					s[j] = getalpha(s[j], s[j]);
				}

			}
			st = et = -1;
		}
	}
	cout << s << endl;


}