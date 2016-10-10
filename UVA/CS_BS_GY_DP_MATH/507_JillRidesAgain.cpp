#include <bits/stdc++.h>
#define vi vector<int>
using namespace std;
int main() {
#ifndef ONLINE_JUDGE
	freopen("E:/Shiva backup/Shiva/Learning/Learning/UVA/1.txt", "r", stdin);
	freopen("E:/Shiva backup/Shiva/Learning/Learning/UVA/2.txt", "w", stdout);
#endif
	int b, bi, i, x = 1;
	scanf("%d", &b);
	while (b--) {
		scanf("%d", &bi);
		int val;
		int sum = 0, imax = 0, imin = 0, cmin = 0, ans = 0;
		for (i = 1; i < bi; i++) {
			scanf("%d", &val);
			sum += val;
			if (sum > ans || (sum == ans && ((i - cmin) > (imax - imin)))) {
				ans = sum;
				imin = cmin;
				imax = i;
			}
			if (sum < 0) {
				cmin = i;
				sum = 0;
			}
		}
		if (ans > 0)
			printf("The nicest part of route %d is between stops %d and %d\n", x++, imin + 1, imax + 1);
		else printf("Route %d has no nice parts\n", x++);
	}

}