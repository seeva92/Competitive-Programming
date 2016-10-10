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
	int n, m;
	char buffer[100];
	fgets(buffer, sizeof buffer, stdin);
	char big[12][12];
	char small[12][12];
	while (sscanf(buffer, "%d %d\n", &n, &m), n || m) {
		fill(&big[0][0], &big[12][0], '.');
		fill(&small[0][0], &small[12][0], '.');
		for (int i = 0; i < n; i++) {
			fgets(buffer, sizeof buffer, stdin);
			strcpy(big[i], buffer);
			// int len = strlen(buffer);
			// int j;
			// for (j = 0; j < len; j++)
			// 	if (buffer[j] == '.' || buffer[j] == '*')
			// 		big[i][j] = buffer[j];
		}

		for (int i = 0; i < m; i++) {
			fgets(buffer, sizeof buffer, stdin);
			strcpy(small[i], buffer);
			// int len = strlen(buffer);
			// int j;
			// for (j = 0; j < len; j++)
			// 	if (buffer[j] == '.' || buffer[j] == '*')
			// 		small[i][j] = buffer[j];
		}

		for (int i = 0; i < n; i++, printf("\n"))
			for (int j = 0; j < n; j++)
				printf("%c", big[i][j]);


		for (int i = 0; i < m; i++, printf("\n"))
			for (int j = 0; j < m; j++)
				printf("%c", small[i][j]);
		fgets(buffer, sizeof buffer, stdin);
	}
}