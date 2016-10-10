#include <bits/stdc++.h>
#define mp make_pair
#define vi vector<int>
#define pi pair<int,int>
#define vii vector<pi>
using namespace std;
int main() {
#ifndef ONLINE_JUDGE
	freopen("/home/shiva/Learning/1.txt", "r", stdin);
	freopen("/home/shiva/Learning/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false); cin.tie(0);
	int t, len, r, b, g; string s;
	cin >> t;
	while (t--) {
		cin >> len >> s;
		r = b = g = 0;
		for (int i = 0; i < len; i++)
			if (s[i] == 'R') r++;
			else if (s[i] == 'B') b++;
			else g++;
		cout << (len - max(r, max(b, g)))<<endl;
	}

}