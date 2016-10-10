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
	freopen("1.txt", "r", stdin);
	freopen("2.txt", "w", stdout);

	int n, p;
	while (scanf("%d %d", &n, &p), n || p) {
		int x = 1;
		int mid = n / 2 + 1;
		int count = 0;
		while (x * x < p) {
			x += 2;
			count++;
		}


		if (x * x == p) {
			printf("Line = %d, column = %d.\n", mid + count, mid + count);
			continue;
		}
		int i = mid + count, j = mid + count;
		int range = (count * 2);
		int nextHigh = pow(x, 2);
		int down = nextHigh - range;
		int left = down - range; int up = left - range;
		int right = up - range + 1;
		// cout << "i: " << i << "j: " << j << '\n';
		// cout << nextHigh << " " << down << " " << left << " " << up << " " << right << '\n';
		if (nextHigh > p && p >= down) {
			i = mid + count;
			j = mid + count;
			printf("Line = %d, column = %d.\n", (i - (nextHigh - p)), j);
		} else if (down > p && p >= left) {
			i = mid - count;
			j = mid + count;
			printf("Line = %d, column = %d.\n", i, (j - (down - p)));
		} else if (left > p && p >= up) {
			j = mid - count;
			i = mid - count;
			printf("Line = %d, column = %d.\n", (i + (left - p)), j);
		} else if (up > p && p >= right) {
			i = mid + count;
			j = mid - count;
			// cout << "i: " << i << "j: " << j << '\n';
			printf("Line = %d, column = %d.\n", i, (j + (up - p)));
		}

	}
}
// int main() {
// 	std::ios_base::sync_with_stdio(false);
// freopen("1.txt", "r", stdin);
// freopen("2.txt", "w", stdout);
// 	int n, p;
// 	int direction[] = {0, 1, 2, 3};
// 	int dir_idx = -1;
// 	while (scanf("%d %d", &n, &p), n || p) {
// 		int arr[n];
// 		int x = 1, y;
// 		int i = n / 2 + 1, j = n / 2 + 1;
// 		dir_idx = -1;
// 		int change = 1;
// 		// printf("%d %d %d\n", i, j, x);

// 		for (x = 1; x < p;) {

// 			dir_idx = (dir_idx + 1) % 4;
// 			for (y = 1; x < p && y <= change; x++, y++) {

// 				switch (dir_idx) {
// 				case 0: i++; break;
// 				case 1: j--; break;
// 				case 2: i--; break;
// 				case 3: j++; break;
// 				};
// 				// printf("%d %d %d\n", i, j, x + 1);

// 			}
// 			if (x == p)
// 				break;
// 			dir_idx = (dir_idx + 1) % 4;
// 			for (y = 1; x < p && y <= change; x++, y++) {
// 				switch (dir_idx) {
// 				case 0: i++; break;
// 				case 1: j--; break;
// 				case 2: i--; break;
// 				case 3: j++; break;
// 				};

// 				// printf("%d %d %d\n", i, j, x + 1);
// 			}
// 			if (x == p)
// 				break;

// 			change++;
// 		}

// 		printf("Line = %d, column = %d\n", i, j);
// 	}
// }