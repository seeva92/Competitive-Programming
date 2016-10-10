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
	int n, m, x, y; cin >> n;
	set<int> f, ff;
	for (int i = 0; i < n; i++) {
		cin >> x >> m;
		f.insert(x);
		for (int j = 0; j < m; j++) {
			cin >> y;
			ff.insert(y);
		}
	}
	for (auto i : f)
		ff.erase(i);
	
	cout << int(ff.size()) << endl;
}