#include <bits/stdc++.h>
using namespace std;
const int MAX = 100007;
int arr[MAX][26];
int main() {
#ifndef ONLINE_JUDGE
	freopen("/home/shiva/Learning/1.txt", "r", stdin);
	freopen("/home/shiva/Learning/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false); cin.tie(0);
	string s, q; int x;
	cin >> s >> x;
	int len = s.size();
	for (int i = 0; i < 26; i++) arr[len][i] = len;
	for (int i = len - 1; i >= 0; i--) {
		for (int j = 0; j < 26; j++) arr[i][j] = arr[i + 1][j];
		arr[i][s[i] - 'a'] = i;
	}
	while (x--) {
		cin >> q;
		int len1 = q.size(); bool flag = true; int pos = 0;
		for (int i = 0; i < len1 && flag; i++) {
			if (arr[pos][q[i] - 'a'] >= len) flag = false;
			else pos = arr[pos][q[i] - 'a'] + 1;
		}
		if (flag) cout << "Yes\n";
		else cout << "No\n";
	}




	//My Approach Time - nlogn Space - (distinct chars)*(len(s))
	// unordered_map<char, set<int>> mp;
	// for (int i = 0; i < len; i++) {
	// 	mp[s[i]].insert(i);
	// }
	// unordered_map < char, set<int>>::iterator it;
	// set<int>::iterator stit;
	// bool flag = true;
	// while (x--) {
	// 	cin >> q;
	// 	len = q.size();
	// 	flag = true;
	// 	for (int i = 0, prev = -1; i < len; i++) {
	// 		it = mp.find(q[i]);
	// 		if (it == mp.end()) { flag = false; break;}

	// 		stit = (it->second).lower_bound(prev);
	// 		if (stit == (it->second).end()) { flag = false; break;}
	// 		prev = *(stit);
	// 	}
	// 	if (flag) cout << "Yes";
	// 	else cout << "No";
	// 	cout << '\n';
	// }


}