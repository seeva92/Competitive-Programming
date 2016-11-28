#include <bits/stdc++.h>
typedef long long ll;
const int mod = 1e9 + 7;
const int MAX = 1e5 + 7;
using namespace std;
typedef vector<int> vi;
int T, N, X;
int cnt[MAX * 10] = {0};
vector<pair<int, int>> v;
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> T;
	while (T--) {
		memset(cnt, 0, sizeof cnt);
		v.clear();
		cin >> N;
		for (int i = 0; i < N; i++) { cin >> X; cnt[X]++;}
		for (int i = 0; i < (MAX * 10); i++)
			if (cnt[i] != 0) v.push_back({i, cnt[i]});
		int res = -1e9, val = v[0].second;
		for (int i = 1; i < v.size(); i++) {
			if (res < abs(val - v[i].second)) res = abs(val - v[i].second);
			val = min(val, v[i].second);
		}
		if (res == -1e9) cout << -1 << '\n';
		else cout << res << '\n';
	}
}
