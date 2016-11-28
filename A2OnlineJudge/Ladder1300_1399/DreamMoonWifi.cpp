#include <bits/stdc++.h>
typedef long long ll;
const int mod = 1e9 + 7;
const int MAX = 1e5 + 7;
using namespace std;
typedef vector<int> vi;
string a, b;
int blen, place = 0, tote = 0, cure = 0;
void f(int p, int c) {
	if (p == blen) {
		if (c == place) { tote++; cure++;}
		else tote++;
		return;
	}
	if (b[p] == '+') f(p + 1, c + 1);
	else if (b[p] == '-') f(p + 1, c - 1);
	else {
		f(p + 1, c + 1);
		f(p + 1, c - 1);
	}
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> a >> b; blen = b.size();
	for (auto i : a)
		if (i == '+') place++;
		else place--;
	f(0, 0); //cout << tote << " " << cure << '\n';
	if (tote) cout << fixed << setprecision(15) << (double)cure / (double)tote;
	else cout << fixed << setprecision(15) << (double)0;
}
