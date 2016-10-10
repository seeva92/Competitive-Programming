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
#include <map>
#include <unordered_map>
using namespace std;
int main() {

#ifndef ONLINE_JUDGE
	freopen("1.txt", "r", stdin);
	freopen("2.txt", "w", stdout);
#endif
	bool arr[510][510];
	int w, h, n;
	int x1, x2, y1, y2;
	int counter = 0;
	while (scanf("%d %d %d", &w, &h, &n), w || h || n) {
		memset(&arr[0][0], 0, sizeof arr);

		while (n--) {
			scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
			if (x1 > x2)
				swap(x2, x1);
			if (y1 > y2)
				swap(y1, y2);

			for (int i = x1; i <= x2; i++)
				for (int j = y1; j <= y2; j++)
					arr[i][j] = 1;
		}

		counter = 0;
		for (int i = 1; i <= w; i++)
			for (int j = 1; j <= h; j++)
				if (arr[i][j] == 0)
					counter++;

		if (counter == 0)
			printf("There is no empty spots.\n");
		else if (counter == 1)
			printf("There is one empty spot.\n");
		else
			printf("There are %d empty spots.\n", counter);
	}
}