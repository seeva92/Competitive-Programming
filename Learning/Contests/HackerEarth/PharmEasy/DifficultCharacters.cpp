#include <bits/stdc++.h>
#define mp make_pair
#define vi vector<int>
#define pi pair<int,int>
#define vii vector<pi>
using namespace std;
bool compare (pi i, pi j) {
	if (i.first < j.first) return true;
	else if (i.first == j.first) {
		if (i.second > j.second) return true;
	}
	return false;
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("/home/shiva/Learning/1.txt", "r", stdin);
	freopen("/home/shiva/Learning/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	int arr[26] = {0};
	string str;
	while (t--) {
		cin >> str;
		memset(arr, 0, sizeof arr);
		int len = int(str.size());
		for (int i = 0; i < len; i++) arr[str[i] - 'a']++;
		vector<pi> v;
		for (int i = 25; i >= 0; i--)
			if (!arr[i]) cout << (char)('a' + i) << " ";
			else v.push_back({arr[i], i});
		sort(v.begin(), v.end(), compare);
		for (auto it : v) cout << (char)('a' + (it.second)) << " ";
		cout << endl;
	}
}