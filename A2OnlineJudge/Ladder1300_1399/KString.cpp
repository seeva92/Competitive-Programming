#include <bits/stdc++.h>
const int mod = 1e9 + 7;
using namespace std;
typedef vector<int> vi;
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	int k; string s; cin >> k >> s;
	if (int(s.size()) < k || int(s.size()) % k != 0) { cout << -1; return 0; }
	int cnt[26] = {0};
	for (auto i : s) cnt[i - 'a']++;
	bool flag = true;
	int blk = 0;
	for (int i = 0; i < 26; i++) {
		if ((cnt[i] == 0) || (cnt[i] >= k && cnt[i] % k == 0)) {
			blk += (cnt[i] / k);
			continue;
		}
		flag = false; break;
	}
	vector<char> v(int(s.size()), '-');
	if (!flag) cout << -1;
	else {
		// cout << "WOw";
		int j = 0;
		for (int i = 0; i < 26; i++) {
			if (cnt[i]) {
				while (cnt[i]) {
					for (int l = j; l < int(s.size()); l += blk) v[l] = (char)i + 'a';
					cnt[i] -= k;
					j++;
					// string temp (v.begin(), v.end());
					// cout << temp << '\n';
				}
			}
		}
		string temp (v.begin(), v.end());
		cout << temp << '\n';
	}


}
