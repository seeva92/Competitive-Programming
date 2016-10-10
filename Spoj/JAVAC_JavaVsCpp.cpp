#include <bits/stdc++.h>
#define vi vector<int>
#define pi pair<int,int>
#define vii vector<pi>
#define ll long long
using namespace std;
inline bool java(string & str) {
	if (!('a' <= str[0] && str[0] <= 'z')) return false;
	for (auto it : str) {
		if (it == '_') return false;
	}
	return true;
}
inline bool cpp(string & str) {
	if (!('a' <= str[0] && str[0] <= 'z')) return false;
	if (str[int(str.size()) - 1] == '_') return false;
	for (size_t i = 0; i < str.size(); i++)
		if ('A' <= str[i] && str[i] <= 'Z') return false;
		else if (i > 0 && str[i] == '_' && str[i - 1] == '_') return false;
	return true;
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("/home/shiva/Learning/1.txt", "r", stdin);
	freopen("/home/shiva/Learning/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false); cin.tie(0);
	string str;
	while (cin >> str && !str.empty()) {
		bool l = java(str); bool r = cpp(str);
		if (l == false && r == false) cout << "Error!";
		else if (l && r) cout << str;
		else if (l) {
			for (size_t i = 0; i < str.size(); i++) {
				if ('A' <= str[i] && str[i] <= 'Z') {
					cout << '_'; cout << (char)(97 + (str[i] - 65));
				}
				else
					cout << str[i];
			}
		} else {
			for (size_t i = 0; i < str.size(); i++) {
				if (str[i] == '_') {
					cout << (char)(65 + (str[i + 1] - 97));
					i++;
				}
				else
					cout << str[i];
			}
		}
		cout<<'\n';
	}
}