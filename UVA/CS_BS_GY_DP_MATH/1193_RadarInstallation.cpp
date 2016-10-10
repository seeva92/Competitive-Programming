#include <bits/stdc++.h>
#define vi vector<int>
#define all(v) v.begin(),v.end()
#define pii pair<int,int>
#define mp make_pair
#define sqr(x) x*x
using namespace std;
struct P {
	int x, y;
	bool operator < (const P a) const {
		return x < a.x;
	}
};
int main() {
#ifndef ONLINE_JUDGE
	freopen("E:/Shiva backup/Shiva/Learning/Learning/UVA/1.txt", "r", stdin);
	freopen("E:/Shiva backup/Shiva/Learning/Learning/UVA/2.txt", "w", stdout);
#endif
	int n, d, x, y, cas = 1;
	while (scanf("%d %d", &n, &d) != EOF && (n || d)) {
		P points[n];
		for (int i = 0; i < n; i++) scanf("%d %d", &(points[i].x), &(points[i].y));
		sort(points, points + n);
		double lt, rt, llt, rrt, dx; int result = 0;
		for (int i = 0; i < n; i++) {
			if (points[i].y > d || points[i].y < 0) {
				result = -1; break;
			}
			if (i == 0) {
				result = 1;
				dx = sqrt(sqr(d) - sqr(points[i].y));
				lt = points[i].x - dx;
				rt = points[i].x + dx;
			} else {
				dx = sqrt(sqr(d) - sqr(points[i].y));
				llt = points[i].x - dx;
				rrt = points[i].x + dx;
				if (llt <= rt && rrt >= lt) {
					lt = max(lt, llt); rt = min(rt, rrt);
				} else {
					result++;
					lt = llt; rt = rrt;
				}
			}
		}
		printf("Case %d: %d\n", cas++, result);
	}
}