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
	string s;
	int x=1;
	while (cin >> s && s[0] != '-') {
		stack<char> st;
		int count = 0;
		for (auto i : s) {
			if (i == '{') st.push('{');
			else if (!st.empty()) {
				st.pop();
			} else {
				st.push('{');
				count++;
			}
		}
		cout<<x++<<". " << count + (int(st.size()) / 2) << endl;
	}

}