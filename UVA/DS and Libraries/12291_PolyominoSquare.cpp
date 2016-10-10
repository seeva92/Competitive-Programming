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
char big[12][12], small[12][12];
char copy1[12][12], copy2[12][12], result[12][12];
char ssmall[12][12], sbig[12][12];
char buffer[100];
void compute(int n, int  m, int & sr, int & sc, int & br, int & bc) {
	int i, j, k, l;
	int up = m, down = -1, left = m, right = -1;
	for (i = 0; i < m; i++)
		for (j = 0; j < m; j++)
			if (small[i][j] == '*') {
				if (up > i)
					up = i;
				if (down < i)
					down = i;
				if (left > j)
					left = j;
				if (right < j)
					right = j;
			}

	fill(&ssmall[0][0], &ssmall[12][0], '.');
	for (i = up, k = 0; i <= down; i++, k++)
		for (j = left, l = 0; j <= right; j++, l++)
			ssmall[k][l] = small[i][j];

	sr = down - up + 1;
	sc = right - left + 1;

	up = n; down = -1; left = n; right = -1;
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			if (big[i][j] == '*') {
				if (up > i)
					up = i;
				if (down < i)
					down = i;
				if (left > j)
					left = j;
				if (right < j)
					right = j;
			}
	fill(&sbig[0][0], &sbig[12][0], '.');
	for (i = up, k = 0; i <= down; i++, k++)
		for (j = left, l = 0; j <= right; j++, l++)
			sbig[k][l] = big[i][j];

	br = down - up + 1;
	bc = right - left + 1;
}

int main() {
	// std::ios_base::sync_with_stdio(false);
	// cin.tie(0);

	// freopen("1.txt", "r", stdin);
	// freopen("2.txt", "w", stdout);

	int n, m, i, j, k, l, x, y;
	fgets(buffer, sizeof buffer, stdin);


	int counter = 0;
	while (sscanf(buffer, "%d %d", &n, &m), n || m)
	{
		fill(&big[0][0], &big[12][0], '.');
		fill(&small[0][0], &small[12][0], '.');
		fill(&copy1[0][0], &copy1[12][0], '.');
		fill(&copy2[0][0], &copy2[12][0], '.');
		fill(&result[0][0], &result[12][0], '.');
		for (i = 0; i < n; i++) {
			fgets(buffer, sizeof buffer, stdin);
			int len = strlen(buffer);
			for (j = 0; j < len; j++)
				if (buffer[j] == '.' || buffer[j] == '*')
					big[i][j] = buffer[j];
		}


		int starcount = 0;
		for (i = 0; i < m; i++) {
			fgets(buffer, sizeof buffer, stdin);
			int len = strlen(buffer);
			for (j = 0; j < len; j++) {
				if (buffer[j] == '.' || buffer[j] == '*')
					small[i][j] = buffer[j];
				if (small[i][j] == '*') starcount++;
			}
		}
		// printf("Small\n");
		// for (i = 0; i < m; i++, printf("\n"))
		// 	for (j = 0; j < m; j++)
		// 		printf("%c", small[i][j] );

		// printf("Big\n");
		// for (i = 0; i < n; i++, printf("\n"))
		// 	for (j = 0; j < n; j++)
		// 		printf("%c", big[i][j] );
		// printf("\n");


		starcount *= 2;
		int currentcount = 0;
		bool flag = false;
		int sr, sc, br, bc;
		compute(n, m, sr, sc, br, bc);

		// printf("Ssmall\n");
		// for (i = 0; i < sr; i++, printf("\n"))
		// 	for (j = 0; j < sc; j++)
		// 		printf("%c", ssmall[i][j] );

		// printf("Sbig\n");
		// for (i = 0; i < br; i++, printf("\n"))
		// 	for (j = 0; j < bc; j++)
		// 		printf("%c", sbig[i][j] );
		// printf("\n");

		//Moving Copy 1 starting from each cell
		for (i = 0; i < br && !flag; i++) {
			for (j = 0; j < bc && !flag; j++) {
				fill(&copy1[0][0], &copy1[12][0], '.');
				for (k = 0; k < sr && i + k < br; k++) {
					for (l = 0; l < sc && j + l < bc; l++) {
						copy1[i + k][j + l] = ssmall[k][l];
					}
				}
				//Moving Copy 2 starting from each cell for every Copy 1
				for (x = 0; x < br; x++) {
					for (y = 0; y < bc; y++) {
						fill(&copy2[0][0], &copy2[12][0], '.');

						for (k = 0; k < sr && x + k < br; k++) {
							for (l = 0; l < sc && l + y < bc; l++)
								copy2[x + k][y + l] = ssmall[k][l];
						}
						fill(&result[0][0], &result[12][0], '.');
						currentcount = 0;

						//Superimpose copy1 and copy2
						for (k = 0; k < br; k++)
							for (l = 0; l < bc; l++) {
								if (result[k][l] == '.')
									result[k][l] = copy1[k][l];
								if (result[k][l] == '.')
									result[k][l] = copy2[k][l];
								if (result[k][l] == '*')
									currentcount++;
							}
						//Match with big one
						if (!flag && currentcount == starcount) {
							bool fail = false;
							for (k = 0; k < br && !fail; k++) {
								for (l = 0; l < bc; l++) {
									if (result[k][l] != sbig[k][l]) {
										fail = true;
										break;
									}
								}
							}
							if (k == br && l == bc)
								flag = true;
						}
					}
				}
			}
		}
		if (flag)
			printf("1\n");
		else
			printf("0\n");



		fgets(buffer, sizeof buffer, stdin);
	}
}