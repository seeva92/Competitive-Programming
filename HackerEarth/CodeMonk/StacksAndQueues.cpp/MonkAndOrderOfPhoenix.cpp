#include <bits/stdc++.h>
typedef long long ll;
const int mod = 1e9 + 7;
const int MAX = 1e5 + 7;
using namespace std;
typedef vector<int> vi;
int N, X, val, Q;
int t, k, h;
map<int, int> mp[11];
stack<int> st[11];
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> X;
		for (int j = 1; j <= X; j++) {
			cin >> val;
			mp[i][val]++;
			st[i].push(val);
		}
	}
	cin >> Q;
	for (int i = 1; i <= Q; i++) {
		cin >> t;
		if (t == 1) {
			cin >> k >> h;

			st[k].push(h);
			mp[k][h]++;
			// cout << k << " " << h << " " << mp[k][h] << " Added\n";
		} else if (t == 0) {
			cin >> k;
			if (!st[k].empty()) {
				// cout << st[k].top() << "Pochi " << mp[k][st[k].top()] << "\n";
				if (mp[k][st[k].top()] > 1)
					mp[k][st[k].top()]--;
				else mp[k].erase(st[k].top());
				st[k].pop();
			}
		} else {
			int temp = -1;
			int j;
			// for (int j = 1; j <= N; j++) {
			// for (auto l : mp[j]) cout << l.first << " "; cout << '\n';
			// }
			for (j = 1; j <= N; j++) {
				// for (auto l : mp[j]) cout << l.first << " "; cout << '\n';
				// cout << "Size " << j << " " << mp[j].size() << '\n';
				auto tmp = mp[j].upper_bound(temp);
				// cout << tmp->first << '\n';
				if (tmp != mp[j].end() && tmp->second > 0) temp = tmp->first;
				else break;
			}
			if (j == N + 1) cout << "YES\n";
			else cout << "NO\n";
		}
	}
}
