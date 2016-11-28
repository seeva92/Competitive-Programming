#include <bits/stdc++.h>
typedef long long ll;
const int mod = 1e9 + 7;
const int MAX = 1e5 + 7;
const long double eps = 1e-18;
using namespace std;
typedef vector<int> vi;
ll n, l, r;
ll x, y;
ll dx, dy;
struct piece {
	char c; ll l, r;
	long double d;
};
bool blks[8];
inline bool compare(piece a, piece b) {
	if (a.d <= b.d + eps)
		return true;
	return false;
}
piece pieces[5 * MAX];
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	for (int i = 0; i < 8; i++) blks[i] = true;
	cin >> n >> x >> y; bool flag = true; char c;
	for (ll i = 0; i < n; i++) {
		cin >> pieces[i].c >> pieces[i].l >> pieces[i].r;
		pieces[i].d = sqrt((long double)((x - pieces[i].l) * (x - pieces[i].l)) + (long double)((y - pieces[i].r) * (y - pieces[i].r)));
	}
	sort(pieces, pieces + n, compare);
	for (int i = 0; i < n; i++) {
		if (flag) {
			dx = x - pieces[i].l; dy = y - pieces[i].r;
			// cout << pieces[i].c << " " << pieces[i].l << " " << pieces[i].r << " " << pieces[i].d << '\n';

			if (x == pieces[i].l) {
				if (blks[0] && y < pieces[i].r) {
					if ((pieces[i].c == 'R' || pieces[i].c == 'Q')) { flag = false; break;}
					else blks[0] = false;
				}
				if (blks[1]  && y > pieces[i].r) {
					if ((pieces[i].c == 'R' || pieces[i].c == 'Q')) { flag = false; break;}
					else blks[1] = false;
				}
			}
			else if (y == pieces[i].r) {
				if (blks[2] && x > pieces[i].l) {
					if ((pieces[i].c == 'R' || pieces[i].c == 'Q')) { flag = false; break;}
					else blks[2] = false;
				}
				if (blks[3] && x < pieces[i].l) {
					if ((pieces[i].c == 'R' || pieces[i].c == 'Q')) { flag = false; break;}
					else blks[3] = false;
				}
			}
			else if (abs(dx) == abs(dy)) {
				if (blks[4]  && x < pieces[i].l && y < pieces[i].r) {
					if ((pieces[i].c == 'B' || pieces[i].c == 'Q')) { flag = false; break;}
					else blks[4] = false;
				}
				if (blks[5]  && x < pieces[i].l && y > pieces[i].r)  {
					if ((pieces[i].c == 'B' || pieces[i].c == 'Q')) { flag = false; break;}
					else blks[5] = false;
				}
				if (blks[6] && x > pieces[i].l && y < pieces[i].r) {
					if ((pieces[i].c == 'B' || pieces[i].c == 'Q')) { flag = false; break;}
					else blks[6] = false;
				}
				if (blks[7] && x > pieces[i].l && y > pieces[i].r) {
					if ((pieces[i].c == 'B' || pieces[i].c == 'Q')) { flag = false; break;}
					else blks[7] = false;
				}
			}

		}
	}
	if (flag) cout << "NO";
	else cout << "YES";
}
