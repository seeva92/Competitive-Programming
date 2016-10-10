#include <bits/stdc++.h>
const int mod = 1e9 + 7;
using namespace std;
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	string s, pass;

	set<string> v[107];
	for (int i = 1; i <= n; i++) {
		cin >> s;
		v[int(s.size())].insert(s);
	}
	cin >> pass;
	int best = 0, worst = 0;
	for (int i = 1; i < int(pass.size()); i++) {
		if (int(v[i].size()) == 0) continue;
		else {
			best += int(v[i].size());
			worst = best;
		}
	}
	//Actual password
	best += ((best / k) * 5); best += 1;
	worst += int(v[int(pass.size())].size()) - 1; worst += ((worst / k) * 5); worst += 1;
	cout << best << " " << worst << '\n';
}
