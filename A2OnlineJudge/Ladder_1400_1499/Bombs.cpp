#include <bits/stdc++.h>
typedef long long ll;
const int mod = 1e9 + 7;
const int MAX = 1e5 + 7;
using namespace std;
typedef vector<int> vi;
struct pt {
	ll x, y;
};
struct movie {
	int t, k; char dir;
};
pt v[MAX];
movie moves[20 * MAX];
int mIdx = 0;
pair<ll, int> arr[MAX];

class Bombs
{
	int n;
public:
	void compute() {
		for (int i = 0; i < n; i++) {
			int dx = v[arr[i].second].x, dy = v[arr[i].second].y;
			if (0 < dx) {
				moves[mIdx].t = 1; moves[mIdx].k = dx; moves[mIdx].dir = 'R'; mIdx++;
			} else if (0 > dx) {
				moves[mIdx].t = 1; moves[mIdx].k = -dx; moves[mIdx].dir = 'L'; mIdx++;
			}

			if (0 < dy) {
				moves[mIdx].t = 1; moves[mIdx].k = dy; moves[mIdx].dir = 'U'; mIdx++;
			} else if (0 > dy) {
				moves[mIdx].t = 1; moves[mIdx].k = -dy; moves[mIdx].dir = 'D'; mIdx++;
			}
			moves[mIdx].t = 2; mIdx++;
			if (0 < dx) {
				moves[mIdx].t = 1; moves[mIdx].k = dx; moves[mIdx].dir = 'L'; mIdx++;
			} else if (dx < 0) {
				moves[mIdx].t = 1; moves[mIdx].k = -dx; moves[mIdx].dir = 'R'; mIdx++;
			}

			if (0 < dy) {
				moves[mIdx].t = 1; moves[mIdx].k = dy; moves[mIdx].dir = 'D'; mIdx++;
			} else if (dy < 0) {
				moves[mIdx].t = 1; moves[mIdx].k = -dy; moves[mIdx].dir = 'U'; mIdx++;
			}
			moves[mIdx].t = 3; mIdx++;
		}
	}
	void solve() {
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> v[i].x >> v[i].y;
			arr[i].first = (v[i].x * v[i].x) + (v[i].y * v[i].y);
			arr[i].second = i;
		}
		sort(arr, arr + n);
		compute();
		cout << mIdx << '\n';
		for (int i = 0; i < mIdx; i++) {
			if (moves[i].t == 1)
				cout << moves[i].t << " " << moves[i].k << " " << moves[i].dir << '\n';
			else cout << moves[i].t << '\n';
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
	Bombs b; b.solve();
}
