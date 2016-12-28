#include <bits/stdc++.h>
typedef long long ll;
const int mod = 1e9 + 7;
const int MAX = 1e5 + 7;
using namespace std;
typedef vector<int> vi;
class ParallelogramIsBack
{
public:
	void solve() {
		int ax, ay, bx, by, cx, cy;
		cin >> ax >> ay >> bx >> by >> cx >> cy;
		cout << 3 << '\n';
		cout << (ax + bx - cx) << " " << (ay + by - cy) << '\n';
		cout << (bx + cx - ax) << " " << (by + cy - ay) << '\n';
		cout << (cx + ax - bx) << " " << (cy + ay - by) << '\n';
	}

};
int main() {
#ifndef ONLINE_JUDGE
	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	ParallelogramIsBack p; p.solve();
}
