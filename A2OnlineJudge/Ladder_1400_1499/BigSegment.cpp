#include <bits/stdc++.h>
typedef long long ll;
const int mod = 1e9 + 7;
const int MAX = 1e5 + 7;
using namespace std;
typedef vector<int> vi;
struct node { int f, s, i; };
node p[MAX];
class BigSegment
{
	int n, l, r;
public:
	static bool compare(node & f, node & s) {
		if (f.f == s.f) {
			if (f.s >= s.s) return true;
			return false;
		}
		else if (f.f < s.f) return true;
		return false;
	}
	void solve() {
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> p[i].f >> p[i].s; p[i].i = i;
		}
		sort(p, p + n, compare);

		for (int i = 1; i < n; i++) {
			if (!(p[0].f <= p[i].f && p[i].s <= p[0].s)) {
				cout << "-1"; return;
			}
		}
		cout << p[0].i + 1;
	}
};
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	BigSegment b; b.solve();
}
