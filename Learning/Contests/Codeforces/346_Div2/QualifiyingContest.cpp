#include <bits/stdc++.h>
using namespace std;
int main() {
#ifndef ONLINE_JUDGE
	freopen("/home/shiva/Learning/1.txt", "r", stdin);
	freopen("/home/shiva/Learning/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false); cin.tie(0);
	int n, m; cin >> n >> m;
	vector<pair<int, string>> v[m + 1];
	string str; int team, score;
	for (int i = 0; i < n; i++) {
		cin >> str >> team >> score;
		v[team].push_back(make_pair(score, str));
	}
	for (int i = 1; i <= m; i++) sort(v[i].begin(), v[i].end(), greater<pair<int, string>>());
	for (int i = 1; i <= m; i++) {
		if (v[i].size() > 2 && v[i][1].first == v[i][2].first)
			cout << "?" << endl;
		else
			cout << v[i][0].second << " " << v[i][1].second << endl;
	}
}