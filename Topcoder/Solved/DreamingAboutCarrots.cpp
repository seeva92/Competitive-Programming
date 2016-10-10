// BEGIN CUT HERE

// END CUT HERE
#line 5 "DreamingAboutCarrots.cpp"
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <iostream>
#define vi vector<int>
#define all(v) v.begin(), v.end()
#define pii pair<int, int>
#define mp make_pair
#define ll long long
using namespace std;
class DreamingAboutCarrots {
public:

	int carrotsBetweenCarrots(int x1, int y1, int x2, int y2) {
		if (x1 == x2) return max(y1, y2) - min(y1, y2) - 1;
		if (y1 == y2) return max(x1, x2) - min(x1, x2) - 1;
		int xl = min(x1, x2), xh = max(x1, x2);
		int yl = min(y1, y2), yh = max(y1, y2);
		int sy = y2 - y1, sx = x2 - x1;
		int sg = __gcd(sy, sx);
		sy /= sg; sx /= sg;
		if (sy == 0 || sx == 0) return 0;
		int count = 0;
		for (int i = xl; i <= xh; i++)
			for (int j = yl; j <= yh; j++) {
				if ((i == x1 && j == y1) || (i == x2 && j == y2)) continue;
				// cout << i << " " << j << endl;

				int sfy = j - y1, sfx = i - x1;
				if (sfy == 0 || sfx == 0) continue;
				int sfg = __gcd(sfy, sfx);
				sfy /= sfg; sfx /= sfg;

				int ssy = y2 - j, ssx = x2 - i;
				if (ssy == 0 || ssx == 0) continue;
				int ssg = __gcd(ssy, ssx);
				ssy /= ssg; ssx /= ssg;

				if ((sy == ssy) && (ssy == sfy) && (sx == sfx) && (sfx == ssx)) count++;
			}
		// cout << count << endl;
		return count;
	}

};
// int main() {
// #ifndef ONLINE_JUDGE
// 	freopen("/Users/seeva92/Workspace/Contests/1.txt", "r", stdin);
// 	freopen("/Users/seeva92/Workspace/Contests/2.txt", "w", stdout);
// #endif
// 	DreamingAboutCarrots d;
// 	d.carrotsBetweenCarrots(0, 0, 42, 36);
// }
