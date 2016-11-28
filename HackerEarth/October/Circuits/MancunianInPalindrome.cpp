#include <bits/stdc++.h>
const int mod = 1e9 + 7;
using namespace std;
typedef vector<int> vi;
int N, L, len;
string s;
int ii, jj, loop;
bool ispalin() {
	for (ii = 0, jj = len - 1; ii <= jj && s[ii] == s[jj]; ii++, jj--);
	return ii > jj;
}
bool compute() {
	len = s.size();
	if (ispalin()) return true;
	string temp1, temp2;
	for (int i = 0; i < len; i++) {
		for (int j = i + 1; j < len; j++) {
			temp1 = s;
			reverse(s.begin() + i, s.begin() + j + 1);
			if (ispalin()) return true;
			for (int k = 0; k < i; k++)
				for (int l = k + 1; l < i; l++) {
					temp2 = s;
					reverse(s.begin() + k, s.begin() + l + 1);
					if (ispalin()) return true;
					// reverse(s.begin() + k, s.begin() + l + 1);
					s = temp2;
				}
			for (int k = j + 1; k < len; k++)
				for (int l = k + 1; l < len; l++) {
					temp2 = s;
					reverse(s.begin() + k, s.begin() + l + 1);
					loop++;
					if (ispalin()) return true;
					// reverse(s.begin() + k, s.begin() + l + 1);
					s = temp2;
				}
			// reverse(s.begin() + i, s.begin() + j + 1);
			s = temp1;
		}
	}
	return false;
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> L;
	int cnt = 0;
	while (N--) {
		cin >> s;
		if (compute()) cnt++;
	}
	cout << cnt << '\n';
}
