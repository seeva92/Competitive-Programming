#include <bits/stdc++.h>
typedef long long ll;
const int mod = 1e9 + 7;
const int MAX = 1e6 + 7;
using namespace std;
typedef vector<int> vi;
pair<string, int> arr[MAX];
int pIdx = 0;
vector<string> mp[MAX];
class Comments
{
	string s;
	int start = 0;
public:
	void compute(int lvl) {

		mp[lvl].push_back(arr[start].first);
		int temp  = arr[start].second;
		start++;
		for (int i = 0; i < temp; i++) {
			compute(lvl + 1);
		}
	}
	void solve() {
		cin >> s;
		int len = s.size();
		int prev = 0;
		int cnt = 0;
		for (int i = 0; i < len;) {
			cnt = 0;
			while (i < len && s[i] != ',') {
				i++; cnt++;
			}
			arr[pIdx].first = s.substr(prev, cnt);

			i++; cnt = 0; prev = i;
			while (i < len && s[i] != ',') {
				i++; cnt++;
			}
			arr[pIdx].second = stoi(s.substr(prev, cnt));
			i++; prev = i;
			pIdx++;
		}
		// for (int i = 0; i < pIdx; i++) {
		// 	cout << arr[i].first << " " << arr[i].second << '\n';
		// }
		while (start < pIdx) {
			compute(0);
		}
		cnt = 0;
		for (int i = 0; i < MAX; i++) {
			if (mp[i].size() == 0) break;
			else cnt++;
		}
		cout << cnt << '\n';
		for (int i = 0; i < cnt; i++) {
			for (auto j : mp[i]) cout << j << " ";
			cout << '\n';
		}
	}

};
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	Comments c; c.solve();
}
