#include <bits/stdc++.h>
#define vi vector<int>
#define pi pair<int,int>
#define vii vector<pi>
#define ll long long
using namespace std;
set<string> st;
string str;

void compute(int n) {
	if (n - 1 > 4) {
		st.insert(str.substr(n - 1, 2));
		compute(n - 2);
	}
	if (n - 2 > 4) {
		st.insert(str.substr(n - 2, 3));
		compute(n - 3);
	}
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("/home/shiva/Learning/1.txt", "r", stdin);
	freopen("/home/shiva/Learning/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> str;
	if (str.size() <= 5) cout << 0 << endl;
	else {
		compute(int(str.size()) - 1);
		cout << int(st.size()) << endl;
		for (auto it : st) cout << it << endl;
	}

}