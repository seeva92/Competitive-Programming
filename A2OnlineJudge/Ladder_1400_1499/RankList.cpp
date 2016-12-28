#include <bits/stdc++.h>
typedef long long ll;
const int mod = 1e9 + 7;
const int MAX = 1e5 + 7;
using namespace std;
typedef vector<int> vi;
pair<int, int> v[100];
class RankList
{
	int n, k;
public:
	static bool compare(pair<int, int> a, pair<int, int> b) {
		if (a.first > b.first) return true;
		else if (a.first == b.first) {
			if (a.second < b.second) return true;
		}
		return false;
	}
	void solve() {
		cin >> n >> k;
		for (int i = 0; i < n; i++) cin >> v[i].first >> v[i].second;
		sort(v, v + n, compare);
		pair<int, int> p = v[k - 1];
		int c = 0;
		for (int i = 0; i < n; i++) if (v[i].first == p.first && v[i].second == p.second) c++;
		cout << c;
	}
};
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	RankList r; r.solve();
}
