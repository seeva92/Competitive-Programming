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
	freopen("1.txt", "r", stdin);
	freopen("2.txt", "w", stdout);
	int n, r, c, k;
	while (scanf("%d %d %d %d", &n, &r, &c, &k), n || r || c || k) {
		int arr[r][c], brr[r][c];


		for (int i = 0; i < r; i++)
			for (int j = 0; j < c; j++)
				scanf("%d", &arr[i][j]);

		while (k--) {
			fill(&brr[0][0], &brr[r][0], -1);
			for (int i = 0; i < r; i++) {
				for (int j = 0; j < c; j++) {
					if (i - 1 >= 0 && ((arr[i][j] - arr[i - 1][j] == -1) || (arr[i][j] - arr[i - 1][j] == n - 1)))
						brr[i - 1][j] = arr[i][j];
					if (i + 1 < r && ((arr[i][j] - arr[i + 1][j] == -1) || (arr[i][j] - arr[i + 1][j] == n - 1)))
						brr[i + 1][j] = arr[i][j];
					if (j - 1 >= 0 && ((arr[i][j] - arr[i][j - 1] == -1) || (arr[i][j] - arr[i][j - 1] == n - 1)))
						brr[i][j - 1] = arr[i][j];
					if (j + 1 < c && ((arr[i][j] - arr[i][j + 1] == -1) || (arr[i][j] - arr[i][j + 1] == n - 1)))
						brr[i][j + 1] = arr[i][j];
				}
			}

			for (int i = 0; i < r; i++)
				for (int j = 0; j < c; j++)
					if (brr[i][j] != -1)
						arr[i][j] = brr[i][j];

		}
		int i, j;
		for (i = 0; i < r; i++) {
			for (j = 0; j < c - 1; j++)
				printf("%d ", arr[i][j]);
			printf("%d\n", arr[i][j]);
		}
	}
}