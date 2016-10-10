#include <iostream>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
#include <sstream>
#include <set>
#include <climits>
#include <cstdio>
#include <string>
using namespace std;
int main() {
	// std::ios_base::sync_with_stdio(false);
	// freopen("1.txt", "r", stdin);
	// freopen("2.txt", "w" , stdout);
	int n, idx;

	while (scanf("%d", &n), n != 0) {
		int pos, car;
		int startArr[n] = {0};
		memset(startArr, 0, sizeof startArr);

		bool flag = true;

		for (int i = 0; i < n; i++) {
			scanf("%d", &car);
			scanf("%d", &pos);
			if (!flag)
				continue;

			if (pos > 0) {
				pos = (i + pos);
				flag = pos >= n ? false : flag;

			}
			else if (pos < 0) {
				pos = abs(pos);
				pos = (i - pos);
				flag = pos < 0 ? false : flag;
			} else
				pos = i;

			if (!flag)
				continue;

			startArr[pos] = car;
			// for (int i = 0; i < n; i++)
			// 	printf("%d ", startArr[i]);
			// printf("\n");
		}
		

		for (int i = 0; i < n; i++)
			if (startArr[i] == 0) {
				flag = false;
				break;
			}

		if (flag) {
			for (int i = 0; i < n; i++) {
				printf("%d", startArr[i]);
				if (i + 1 != n)
					printf(" ");

			}
			printf("\n");
		} else
			printf("-1\n");

	}
}