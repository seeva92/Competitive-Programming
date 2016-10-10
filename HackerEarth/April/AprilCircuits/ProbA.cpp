#include <bits/stdc++.h>
#define vi vector<int>
#define pi pair<int,int>
#define vii vector<pi>
#define ll long long
using namespace std;
int main() {
#ifndef ONLINE_JUDGE
	freopen("/home/shiva/Learning/1.txt", "r", stdin);
	freopen("/home/shiva/Learning/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false); cin.tie(0);
	int t; string s;
	cin >> t;
	string vowel = "aeiouy";
	while (t--) {
		cin >> s;
		int consec = 0;
		int vc = 0, cc = 0;
		for (int i = 0; i < int(s.size()) && consec < 3; i++) {
			if (vowel.find(s[i]) == string::npos) {consec++; cc++;}
			else {consec = 0; vc++;}
		}
		if (cc > vc || consec == 3) cout << "hard" << endl;
		else cout << "easy" << endl;


	}

}