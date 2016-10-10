#include <bits/stdc++.h>
const int mod = 1e9 + 7;
using namespace std;
int q; string a, b;
bool compute() {
	map<char, int> d;
	for (auto i : b) d[i]++;
	string upd;
	for (auto i : a) {
		if (('A' <= i && i <= 'Z') && (d.count(i) == 0)) return false;
		if (d.count(toupper(i))) upd += i;
	}
	int idx = 0;
	string res = "";
	set<int> st;
	for (auto i : b) {
		size_t u = upd.find(i, idx);
		size_t l = upd.find(tolower(i), idx);
		if (u != string::npos) {
			idx = int(u) + 1;
			res += upd[idx - 1];
		} else if (l != string::npos) {
			idx = int(l) + 1;
			res += upd[idx - 1];
		} else return false;
		st.insert(idx - 1);
	}

	//check erasable
	for (int i = 0; i < int(upd.size()); i++) {
		if (st.find(i) != st.end()) continue;
		else if ('a' <= upd[i] && upd[i] <= 'z') continue;
		else return false;
	}
	return true;
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> q;
	while (q--) {
		cin >> a >> b;
		if (compute()) cout << "YES\n";
		else cout << "NO\n";
	}
}
