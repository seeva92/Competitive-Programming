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
struct NumPuzz {
	char c;
	int i;
	int j;
};
NumPuzz numpuzz[10];

int main() {
	// freopen("1.txt", "r", stdin);
	// freopen("2.txt", "w", stdout);
	char c = 'a';
	for (int i = 1; i <= 3; i++)
		for (int j = 1; j <= 3; j++, c++)
			numpuzz[(int)(c - 'a')] = {c, i, j};

	// for (int i = 0; i < 9; i++ )
	// printf("%d %d\n", numpuzz[i].i, numpuzz[i].j);

	char str[1000];
	int a[5][5];
	int testcase = 1;
	while (fgets(str, sizeof str, stdin)) {
		memset(&a[0][0], 0, sizeof a);
		int x, y;
		int len = strlen(str);
		for (int i = len - 1; i >= 0; i--) {
			x = numpuzz[(int)(str[i] - 'a')].i;
			y = numpuzz[(int)(str[i] - 'a')].j;
			a[x][y] = (a[x][y] + 1) % 10; a[x - 1][y] = (a[x - 1][y] + 1) % 10;
			a[x][y - 1] = (a[x][y - 1] + 1) % 10; a[x + 1][y] = (a[x + 1][y] + 1) % 10;
			a[x][y + 1] = (a[x][y + 1] + 1) % 10;
		}
		printf("Case #%d:\n", testcase); testcase++;
		int i, j;
		for (i = 1; i <= 3; i++, printf("\n")) {
			for (j = 1; j <= 2; j++) {
				printf("%d ", a[i][j]);
			}
			printf("%d", a[i][j]);
		}

	}
}